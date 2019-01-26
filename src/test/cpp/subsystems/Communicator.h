#ifndef SOCKETTEST_COMMUNICATOR_H
#define SOCKETTEST_COMMUNICATOR_H

class Communicator {
public:
    Communicator();
    struct TargetPosition {
        double heading;
        double timestamp;
        bool locked;
    };
    TargetPosition targetPosition;
private:
    int listen();
    char buf[1000];
    void parsePositionData(char buf[1000]);

};


#endif //SOCKETTEST_COMMUNICATOR_H
