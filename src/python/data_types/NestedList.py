import sys
N = int(raw_input())
data = []
min_1 = sys.maxint
min_2 = sys.maxint

for i in range(0,N):
    name = raw_input()
    score = float(raw_input())
    
    if score < min_1 and score < min_2:
        min_2 = min_1
        min_1 = score
    elif score > min_1 and score < min_2:
        min_2 = score

    data.append([name, score])

from operator import itemgetter
data.sort(key=itemgetter(0))

for i in range(0,N):
    if data[i][1] == min_2:
        print data[i][0]
