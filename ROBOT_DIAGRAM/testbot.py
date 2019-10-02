import time
from networktables import NetworkTables

# To see messages from networktables, you must setup logging
import logging

logging.basicConfig(level=logging.DEBUG)

NetworkTables.initialize()
sd = NetworkTables.getTable("Diagram")

i = 0
while True:

    thing = input().split()

    sd.putNumber(thing[0], int(thing[1]))
