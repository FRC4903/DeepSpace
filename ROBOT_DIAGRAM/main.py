import sys
import time
from networktables import NetworkTables
from pygame import *
import math as m

# To see messages from networktables, you must setup logging
import logging

logging.basicConfig(level=logging.DEBUG)

ip = 'localhost' #'10.49.3.2'

NetworkTables.initialize(server=ip)

table = NetworkTables.getTable("Diagram")
screen = display.set_mode((800, 450))

init()

pytimer = time.Clock()

ELEVATOR_MAX_VALUE = 2195
TILT_MAX_VALUE = 450000

# text
font = font.Font('avenir.otf', 20)
texts = []

INTAKE_POSITIONS = {-1:'OUT', 0:'NEUTRAL', 1:'IN'}

rocket = image.load('rocket.png')

#    C
#   __--
#  |  /
# A| / B
#  |/

A = 8
B = 12

TPI = 1

D_INIT = 7

def text(x, y, msg):
    Text = font.render(msg, True, (255, 255, 255))
    screen.blit(Text, (x, y))


def arm(x, y, r, robotState):
    # arm surface

    orig_arm = Surface((100, 450), SRCALPHA)
    origCenter = orig_arm.get_rect().center

    # hook
    if robotState['hook']:
        draw.line(orig_arm, (170, 170, 170), (80, 178), (97, 161), 8)
    else:
        draw.line(orig_arm, (170, 170, 170), (81, 178), (81, 155), 8)

    # arm
    draw.polygon(orig_arm, (0, 255, 255),
                 [(73, 185), (73, 130), (82, 130), (82, 188), (54, 228), (48, 223),
                  (73, 185)])

    if robotState['intake'] != 0:

        # arrow
        draw.line(orig_arm, (245, 128, 128), (60, 90), (95, 90), 5)

        if robotState['intake'] == -1:
            draw.line(orig_arm, (245, 128, 128), (87, 80), (95, 90), 5)
            draw.line(orig_arm, (245, 128, 128), (87, 100), (95, 90), 5)
        elif robotState['intake'] == 1:
            draw.line(orig_arm, (245, 128, 128), (68, 80), (60, 90), 5)
            draw.line(orig_arm, (245, 128, 128), (68, 100), (60, 90), 5)

    # rotate on new suface and center and draw
    arm_rotated = transform.rotate(orig_arm, r)
    newCenter = arm_rotated.get_rect().center

    screen.blit(arm_rotated, (x + origCenter[0] - newCenter[0], y + origCenter[1] - newCenter[1]))

def armAngle(distance):
    return m.degrees(m.acos((A ** 2 + B ** 2 - distance ** 2) / (2 * A * B)))

def Robot(x, y, robotState):
    # top pole
    #arm(x + 30, y - 275 - int(100 * robotState['elevator'] / ELEVATOR_MAX_VALUE) * 2, -armAngle(D_INIT + (robotState['tilt'] / 1024) / 25.7 / TPI), robotState)
    arm(x + 30, y - 275 - int(100 * robotState['elevator'] / ELEVATOR_MAX_VALUE) * 2, -armAngle(robotState['tilt'] / TILT_MAX_VALUE), robotState)

    # secondary pole
    draw.rect(screen, (255, 255, 0), (x + 76, y - 175 - int(100 * robotState['elevator'] / ELEVATOR_MAX_VALUE), 8, 140))
    draw.rect(screen, (255, 255, 0), (x + 68, y - 50 - int(100 * robotState['elevator'] / ELEVATOR_MAX_VALUE), 8, 10))

    # main pole
    draw.rect(screen, (255, 0, 255), (x + 60, y - 160, 8, 130))

    # wheels
    draw.circle(screen, (50, 50, 50), (x - 70, y + 5), 20)
    draw.circle(screen, (50, 50, 50), (x + 70, y + 5), 20)

    # base
    draw.polygon(screen, (0, 0, 255) if robotState['alliance'] == 'BLUE' else (225, 0, 0),
                 [(x, y - 50), (x + 120, y - 20), (x + 120, y + 15), (x, y - 15), (x - 120, y + 15), (x - 120, y - 20),
                  (x, y - 50)])

running = True

while running:

    robotState = {
        'elevator': table.getNumber('elevator', 0),
        'backClimb': table.getNumber('backClimb', 0),
        'frontClimb': table.getNumber('frontClimb', 0),
        'hook': table.getNumber('hook', 0),
        'tilt': table.getNumber('tilt', 0),
        'intake': table.getNumber('intake', 0),
        'ledR': table.getNumber('ledR', 0),
        'ledG': table.getNumber('ledG', 0),
        'ledB': table.getNumber('ledB', 1),
        'incognito': table.getNumber('incognito', 0),
        'alliance': 'RED' if table.getNumber('red', 0) == 1 else 'BLUE'
    }

    for e in event.get():
        if e.type == QUIT:
            running = False

    # screen
    screen.fill((0, 0, 0))
    W = screen.get_width();
    H = screen.get_height();

    screen.blit(rocket, (W // 2 - 30, -80))

    # draw robot
    Robot(W // 2 - 150, 420, robotState)


    # text
    texts = ["Elevator Position: %i / %i" % (robotState['elevator'], ELEVATOR_MAX_VALUE),
             "Tilt Position: %i / %i" % (robotState['tilt'], TILT_MAX_VALUE),
             "Hook: %s" % ("OUT" if robotState['hook'] else "IN"),
             "Intake Direction: %s" % INTAKE_POSITIONS[robotState['intake']],
             "Incognito Mode: %s" % ('ENABLED' if robotState['incognito'] else 'DISABLED'),
             "Alliance: %s" % robotState['alliance'],
             "Connected to %s" % ip]

    for i in range(len(texts)):
        text(20, 55 + i * 30, texts[i])

    # status bar
    draw.rect(screen, (255 if robotState['ledR'] else 0, 255 if robotState['ledG'] else 0, 255 if robotState['ledB'] else 0), (0, 0, W, 40))

    display.flip()


    pytimer.tick(60)

exit()



