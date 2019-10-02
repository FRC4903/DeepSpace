import sys
import time
from networktables import NetworkTables
from pygame import *

# To see messages from networktables, you must setup logging
import logging

logging.basicConfig(level=logging.DEBUG)

ip = '10.49.3.2'

NetworkTables.initialize(server=ip)

table = NetworkTables.getTable("Vision")


while True:
    print('robotTime:', table.getNumber('test', 'N/A'))


