import scipy.io.wavfile as wavfile
import PyQt4.QtGui as qt
import time
import numpy as np
import matplotlib.pyplot as pyplot

def dialer(file_name,frame_rate,phone,tone_time):
    data = np.array(np.zeros(1))
    fs = frame_rate*tone_time
    for i in range(len(str(phone))):
        d = int(str(phone)[i]) #digit

        if d%3 == 1:
            f = 1209
        elif d%3 == 2:
            f = 1336
        elif d%3 == 0:
            f = 1477
        t = np.linspace(0, tone_time, fs)
        
        if d==1 or d==2 or d==3:
            f2 = 697
        elif d==4 or d==5 or d==6:
            f2 = 770
        elif d ==7 or d==8 or d==9:
            f2 = 852
        else: 
            f2 = 941
        tone = np.cos(2*np.pi*f*t) + np.cos(2*np.pi*f2*t)
        data = np.append(data,tone)

    wavfile.write(file_name,frame_rate,data)
    qt.QSound.play(file_name)


def __main__():
    dialer("haha.wav", 44100, 5086602459, 1)



