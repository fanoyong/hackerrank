#!/usr/bin/python

from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import Pipeline
import numpy as np

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
model = Pipeline([('poly', PolynomialFeatures(degree=3)), ('linear', LinearRegression(fit_intercept=False))])
model = model.fit(train_x, train_y)

s = raw_input()
n = int(s)
testdata = np.zeros(shape=(n,f))
for i in range(n):
    t = raw_input()
    testdata[i] = map(float, t.split(' '))

testresult = model.predict(testdata)
for x in np.nditer(testresult):
    print np.round(x,2)
