from pygame import *
import math

init()
screen = display.set_mode((800, 600))
running = True

# robot stats
LIGHT_STATUS = (0, 255, 0)
ELEVATOR_HEIGHT = 100  # 0 to 100
ELEVATOR_MAX_VALUE = 1000

ROTATE = 0  # degrees
HOOK = False  # True = out, False = in
INTAKE = 0  # True = out, False = in

# text
font = font.Font('avenir.otf', 20)
texts = []

INTAKE_POSITIONS = {-1:'OUT', 0:'NEUTRAL', 1:'IN'}

rocket = image.load('rocket.png')


def text(x, y, msg):
    Text = font.render(msg, True, (255, 255, 255))
    screen.blit(Text, (x, y))


def arm(x, y, r):
    # arm surface

    orig_arm = Surface((100, 450), SRCALPHA)
    origCenter = orig_arm.get_rect().center

    # hook
    if HOOK:
        draw.line(orig_arm, (170, 170, 170), (80, 178), (97, 161), 8)
    else:
        draw.line(orig_arm, (170, 170, 170), (81, 178), (81, 155), 8)

    # arm
    draw.polygon(orig_arm, (0, 255, 255),
                 [(73, 185), (73, 130), (82, 130), (82, 188), (54, 228), (48, 223),
                  (73, 185)])

    if INTAKE is not 0:

        # arrow
        draw.line(orig_arm, (245, 128, 128), (60, 90), (95, 90), 5)

        if INTAKE == -1:
            draw.line(orig_arm, (245, 128, 128), (87, 80), (95, 90), 5)
            draw.line(orig_arm, (245, 128, 128), (87, 100), (95, 90), 5)
        else:
            draw.line(orig_arm, (245, 128, 128), (68, 80), (60, 90), 5)
            draw.line(orig_arm, (245, 128, 128), (68, 100), (60, 90), 5)

    # rotate on new suface and center and draw
    arm_rotated = transform.rotate(orig_arm, r)
    newCenter = arm_rotated.get_rect().center

    screen.blit(arm_rotated, (x + origCenter[0] - newCenter[0], y + origCenter[1] - newCenter[1]))


def Robot(x, y):
    # top pole
    arm(x + 30, y - 275 - int(100 * ELEVATOR_HEIGHT / ELEVATOR_MAX_VALUE) * 2, -ROTATE)

    # secondary pole
    draw.rect(screen, (255, 255, 0), (x + 76, y - 175 - int(100 * ELEVATOR_HEIGHT / ELEVATOR_MAX_VALUE), 8, 140))
    draw.rect(screen, (255, 255, 0), (x + 68, y - 50 - int(100 * ELEVATOR_HEIGHT / ELEVATOR_MAX_VALUE), 8, 10))

    # main pole
    draw.rect(screen, (255, 0, 255), (x + 60, y - 160, 8, 130))

    # wheels
    draw.circle(screen, (50, 50, 50), (x - 70, y + 5), 20)
    draw.circle(screen, (50, 50, 50), (x + 70, y + 5), 20)

    # base
    draw.polygon(screen, (21, 98, 214),
                 [(x, y - 50), (x + 120, y - 20), (x + 120, y + 15), (x, y - 15), (x - 120, y + 15), (x - 120, y - 20),
                  (x, y - 50)])


while running:

    for e in event.get():
        if e.type == QUIT:
            running = False


        elif e.type == MOUSEBUTTONDOWN:
            if e.button == 3:
                HOOK = not HOOK
            else:
                INTAKE = -1


    # screen
    screen.fill((0, 0, 0))
    W = screen.get_width();
    H = screen.get_height();


    screen.blit(rocket, (W // 2 - 30, 35))


    # draw robot
    Robot(W // 2 - 150, 530)


    # text
    texts = ["Elevator Position: %i / %i" % (ELEVATOR_HEIGHT, ELEVATOR_MAX_VALUE),
             "Tilt Position: %i / %i" % (ELEVATOR_HEIGHT, ELEVATOR_MAX_VALUE),
             "Hook: %s" % ("OUT" if HOOK else "IN"),
             "Intake Direction: %s" % INTAKE_POSITIONS[INTAKE]]
    for i in range(len(texts)):
        text(20, 55 + i * 30, texts[i])

    # status bar
    draw.rect(screen, LIGHT_STATUS, (0, 0, W, 40))

    ELEVATOR_HEIGHT = 500 + math.sin(time.get_ticks() / 1000) * 500
    #ROTATE = 90 - math.sin(time.get_ticks() / 1000) * 30

    display.flip()
quit()
