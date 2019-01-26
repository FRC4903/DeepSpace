//
// Created by henry on 20/01/19.
//

#include "Communicator.h"
#include <thread>
#include <string>

#include "iostream"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;

#define MYPORT "5801"    // the port users will be connecting to
#define MAXBUFLEN 1000

char buf[MAXBUFLEN];
bool listening = true;

Communicator::TargetPosition targetPosition;

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void Communicator::parsePositionData(char *buf) {


    char *key, *value, *saveGroup, *savePair;
    char *group = strtok_r(buf, ";", &saveGroup);


    while (group != NULL) {

        key = strtok_r(group, ":", &savePair);
        value = strtok_r(NULL, ":", &savePair);

        // Some sketchy hard code

        if (strcmp(key, "heading") == 0) {
            targetPosition.heading = atof(value);

        } else if (strcmp(key, "locked") == 0) {
            targetPosition.locked = strcmp(value, "1") == 0;

        } else if (strcmp(key, "timestamp") == 0) {
            targetPosition.timestamp = atof(value);

        } else {
            cout << "Invalid key: " << key << endl;

        }

        group = strtok_r(NULL, ";", &saveGroup);
    }
}

int Communicator::listen() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int numbytes;
    struct sockaddr_storage their_addr;
    //char buf[MAXBUFLEN];
    socklen_t addr_len;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE; // use my IP

    if ((rv = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("listener: socket");
            continue;
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("listener: bind");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "listener: failed to bind socket\n");
        return 2;
    }

    freeaddrinfo(servinfo);

    printf("listener: waiting to recvfrom...\n");

    while (listening) {

        addr_len = sizeof their_addr;
        printf("1\n");

        if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN - 1, 0,
                                 (struct sockaddr *) &their_addr, &addr_len)) == -1) {
            perror("recvfrom");
            exit(1);
        }

        printf("listener: got packet from %s\n",
               inet_ntop(their_addr.ss_family,
                         get_in_addr((struct sockaddr *) &their_addr),
                         s, sizeof s));
        printf("listener: packet is %d bytes long\n", numbytes);
        buf[numbytes] = '\0';
        printf("listener: packet contains \"%s\"\n", buf);

        parsePositionData(buf);

    }

    close(sockfd);

    return 0;
}

Communicator::Communicator() {

    /*
     * Things that matter:
     * -Heading
     * -Locked
     * -Last updated
     * */

    thread listener (&Communicator::listen, this);

    listener.detach();
}