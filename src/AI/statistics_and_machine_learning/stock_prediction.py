#!/usr/bin/python

from sklearn.preprocessing import PolynomialFeatures
from sklearn import linear_model
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import Pipeline
import numpy as np


#!/usr/bin/py
def printTransactions(m, k, d, name, owned, prices):
    count = 0
    print m
    print k
    print d
    print name.shape
    print owned.shape
    print prices.shape
    x = np.arange(5)+1
    x = x.flatten()
    x = x.reshape(len(x),1)
    SELL = []
    BUY = []
    model = Pipeline([('poly', PolynomialFeatures(degree=3)), ('linear', LinearRegression(fit_intercept=False))])
    for i in range(k):
        if (d == 0):
            continue
        y = np.array(prices[i])
        y = y.flatten()
        y = y.reshape(len(y),1)
        model.fit(x, y)
        pred = model.predict(6)
        ratio = pred / prices[i,4]
        if ratio < 0.5:
            count = count + 1
        elif ratio < 0.9:
            count = count + 1
        elif ratio > 1.5:
            count = count + 1
        elif ratio > 1.1:
            count = count + 1

    print count

    for i in range(k):
        if (d == 0):
            continue
        y = np.array(prices[i])
        y = y.flatten()
        y = y.reshape(len(y),1)
        model.fit(x, y)
        pred = model.predict(6)
        ratio = pred / prices[i,4]
        if ratio < 0.5:
            m = m + d * prices[i,4]
            cout name[i] + " SELL " + d
        elif ratio < 0.9:
            m = m + int(d/2) * prices[i,4]
            cout name[i] + " SELL " + int(d/2)


    for i in range(k):
        if (d == 0):
            continue
        y = np.array(prices[i])
        y = y.flatten()
        y = y.reshape(len(y),1)
        model.fit(x, y)
        pred = model.predict(6)
        ratio = pred / prices[i,4]
        x = int(m / prices[i,4])
        if ratio > 1.5:
            m = m - x * prices[i,4]
            cout name[i] + " BUY " + x
        elif ratio > 1.1:
            count = count + 1
            m = m + int(x/2) * prices[i,4]
            cout name[i] + " BUY " + int(x/2)
    
    
if __name__ == '__main__':
    m, k, d = [float(i) for i in raw_input().strip().split()]
    k = int(k)
    d = int(d)
    names = []
    owned = []
    prices = []
    for data in range(k):
        temp = raw_input().strip().split()
        names.append(temp[0])
        owned.append(int(temp[1]))
        prices.append([float(i) for i in temp[2:7]])

    names = np.array(names)
    names = names.reshape(k,-1)
    owned = np.array(owned)
    owned = owned.reshape(k,-1)    
    prices = np.array(prices)
    prices = prices.reshape(k,5)

    printTransactions(m, k, d, names, owned, prices)

