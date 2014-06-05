from time import sleep
import serial
import pygame

import time


track = {
    1: '1_intro',
    2: '2_hello_olaf',
    3: '3_go_away_anna',
    4: '4_for_the_first_time',
    5: '5_conceal_dont show',
    6: '6_transition_snow',
    7: '7_olaf_dadada',
    8: '8_let_it_go',
    9: '9_put_us_down',
    10: '10_frozen_heart',
    11: '11_save_elsa',
    12: '12_are_you_ready'
}


def play(index):
    pygame.mixer.music.fadeout(200)
    pygame.mixer.music.load('%s.wav' % track[index])
    pygame.mixer.music.play()
    time.sleep(0.3)


ser = serial.Serial('/dev/tty.usbmodemfa131', 9600) # Establish the connection on a specific port
# counter = 32 # Below 32 everything in ASCII is gibberish
c = 0
pygame.init()
while True:
    # counter +=1
    c+=1
    # ser.write(str(chr(counter))) # Convert the decimal number to ASCII then send it to the Arduino
    line = ser.readline()
    # print line# Read the newest output from the Arduino
    # print type(line)# Read the newest output from the Arduino
    # if ('triggered' in line):
    if (len(line)>0):
        pid = int(line) + 1
        print track[pid]
        play(pid)
        line = ''
    # play();
    # print  # Read the newest output from the Arduino
    sleep(.01) # Delay for one tenth of a second
    # if counter == 255:
    # counter = 32

