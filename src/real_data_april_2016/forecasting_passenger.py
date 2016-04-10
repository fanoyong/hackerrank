import sys
n = int(raw_input())
Data = [[0 for x in range(12)] for x in range(15)] 
count = [0 for x in range(12)]
for i in range(0,n):
    line = raw_input().split()
    month = line[0]
    value = line[1]
    Data[i%12][count[i%12]] = value
    count[i%12] = count[i%12] + 1

for i in range(0,12):
    for j in range(0,15):
        print Data[i][j]

    


