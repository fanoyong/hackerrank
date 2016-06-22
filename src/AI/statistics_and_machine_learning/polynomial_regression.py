#!/usr/bin/python

import numpy as np
from sklearn import cross_validation
from sklearn import datasets, linear_model
from sklearn.cross_validation import KFold

s = raw_input()
ss = s.split(' ')
f = int(ss[0])
n = int(ss[1])
data = np.zeros(shape=(n, f+1))
for i in range(n):
    t = raw_input()
    data[i] =  map(float, t.split(' '))

train_x = data[:, :f]
train_y = data[:, f:]
regr = linear_model.LinearRegression()
regr.fit(train_x, train_y)

s = raw_input()
n = int(s)
testdata = np.zeros(shape=(n,f))
for i in range(n):
    t = raw_input()
    testdata[i] = map(float, t.split(' '))

testresult = regr.predict(testdata)
for x in np.nditer(testresult):
    print x
