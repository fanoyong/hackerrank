#!/usr/bin/python

from sklearn.preprocessing import PolynomialFeatures
from sklearn import linear_model
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import Pipeline
import numpy as np


#!/usr/bin/py
def printTransactions(m, k, d, name, owned, prices):
    count = 0
    x = np.arange(5)+1
    x = x.flatten()
    x = x.reshape(len(x),1)
    SELL = []
    BUY = []
    model = Pipeline([('poly', PolynomialFeatures(degree=3)), ('linear', LinearRegression(fit_intercept=False))])
    for i in range(k):
        y = np.array(prices[i])
        y = y.flatten()
        y = y.reshape(len(y),1)
        model.fit(x, y)
        pred = model.predict(6)
        if (pred > prices[i,4] * 1.1):
            count = count+1
            SELL.append(name)
        elif (pred < prices[i,4] * 0.9):
            count = count+1
            BUY.append(name)
    print count
    print "SELL"
    print SELL
    print "BUY"
    print BUY
    
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
    
    prices = np.array(prices)
    prices = prices.reshape(k,5)

    printTransactions(m, k, d, names, owned, prices)

