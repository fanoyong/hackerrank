#!/usr/bin/python

import numpy as np
import sys
n = 100
filename = "trainingdata.txt"
data = np.zeros(shape=(100,2))
lines = tuple(open(filename, 'r'))
for i in range(100):
    contents = lines[i].split(',')
    data[i] = contents

target = np.zeros(shape=(100,1))
for i in range(100):
    target[i] = (data[i][1]+1) / (data[i][0]+0.5)

mult = np.mean(target[0:n-1])

m = raw_input()
if (float(m) <= 4.00):
    print float(m) * 2
else:
    print 8
