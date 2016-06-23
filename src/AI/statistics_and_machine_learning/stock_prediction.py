#!/usr/bin/python

from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline
from sklearn.linear_model import Ridge
from sklearn import linear_model
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import Pipeline
import numpy as np


# !/usr/bin/py
def printTransactions(m, k, d, name, owned, prices):
    count = 0
    x = np.arange(5) + 1
    x = x.flatten()
    x = x.reshape(len(x), 1)
    transantaion = np.zeros(shape=(k, 1))
    projected = m
    for i in range(k):
        if (d == 0):
            continue
        y = np.array(prices[i])
        y = y.flatten()
        y = y.reshape(len(y), 1)
        # model = Pipeline([('poly', PolynomialFeatures(degree=3)), ('linear', LinearRegression(fit_intercept=False))])
        # model = make_pipeline(PolynomialFeatures(3), Ridge())
        model = make_pipeline(PolynomialFeatures(3), linear_model.TheilSenRegressor(random_state=42))
        model.fit(x, y)
        pred = model.predict(6)
        if (pred < 0):
            continue
        xx = int(m / prices[i, 4])
        ratio = pred / prices[i, 4]
        if ratio < 0.7:
            if owned[i] > 0:
#                 projected = projected + owned[i] * prices[i, 4]
#                 print name[i]
                count = count + 1
        elif ratio < 0.8:
            if owned[i] > 0:
#                 projected = projected + owned[i] * prices[i, 4]
#                 print name[i]
                count = count + 1
        elif ratio > 1.2:
            if xx == 1 and projected > prices[i, 4]:
                projected = projected - prices[i, 4]
#                 print name[i]
                count = count + 1
            elif xx >= 2 and projected > int(xx / 2) * prices[i, 4]:
                projected = projected - int(xx / 2) * prices[i, 4]
#                 print name[i]
                count = count + 1
        elif ratio > 1.1:
            if xx == 1 and projected > prices[i, 4]:
                projected = projected - xx * prices[i, 4]
#                 print name[i]
                count = count + 1
            elif xx >= 2 and projected > int(xx / 2) * prices[i, 4]:
                projected = projected - int(xx / 2) * prices[i, 4]
#                 print name[i]
                count = count + 1

    print count

    for i in range(k):
        if (owned[i] < 1):
            continue
        y = np.array(prices[i])
        y = y.flatten()
        y = y.reshape(len(y), 1)
        # model = Pipeline([('poly', PolynomialFeatures(degree=3)), ('linear', LinearRegression(fit_intercept=False))])
        # model = make_pipeline(PolynomialFeatures(3), Ridge())
        model = make_pipeline(PolynomialFeatures(3), linear_model.TheilSenRegressor(random_state=42))
        model.fit(x, y)
        pred = model.predict(6)
        if (pred < 0):
            continue
        ratio = pred / prices[i, 4]
        if ratio < 0.7:
            print name[i] + ' SELL ' + str(owned[i])
            transantaion[i] = transantaion[i] + owned[i];
        elif ratio < 0.8:
            if owned[i] == 1:
                print name[i] + ' SELL ' + str(owned[i])
                transantaion[i] = transantaion[i] + owned[i];
            else:
                print name[i] + ' SELL ' + str(int(owned[i] / 2))
                transantaion[i] = transantaion[i] + int(owned[i] / 2);

    for i in range(k):
        y = np.array(prices[i])
        y = y.flatten()
        y = y.reshape(len(y), 1)
        # model = Pipeline([('poly', PolynomialFeatures(degree=3)), ('linear', LinearRegression(fit_intercept=False))])
        # model = make_pipeline(PolynomialFeatures(3), Ridge())
        model = make_pipeline(PolynomialFeatures(3), linear_model.TheilSenRegressor(random_state=42))
        model.fit(x, y)
        pred = model.predict(6)
        if (pred < 0):
            continue
        ratio = pred / prices[i, 4]
        xx = int(m / prices[i, 4])
        elif ratio > 1.2:
            if xx == 1 and projected > prices[i, 4]:
                print name[i] + ' BUY 1'
                transantaion[i] = transantaion[i] - 1
            elif xx >= 2 and projected > int(xx / 2) * prices[i, 4]:
                 print name[i] + ' BUY ' + str(int(xx / 2))
                transantaion[i] = transantaion[i] - int(xx / 2)
        elif ratio > 1.1:
            if xx == 1 and projected > prices[i, 4]:
                print name[i] + ' BUY 1'
                transantaion[i] = transantaion[i] - 1
            elif xx >= 2 and projected > int(xx / 2) * prices[i, 4]:
                print name[i] + ' BUY ' + str(int(xx / 2))
                transantaion[i] = transantaion[i] - int(xx / 2)
                
    for i in range(k):
        m = m + transantaion[i] * prices[i,4]
        owned[i] = owned[i] - transantaion[i]
    
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

#     names = np.array(names)
#     names = names.reshape(k, -1)
#     owned = np.array(owned)
#     owned = owned.reshape(k, -1)    
    prices = np.array(prices)
    prices = prices.reshape(k, 5)

    printTransactions(m, k, d, names, owned, prices)


