from __future__ import division
data = {}
n = int(raw_input())
for i in range(0,n):
    line = raw_input().split()
    name = line[0]
    sum = float(line[1]) + float(line[2]) + float(line[3])
    data[name] = sum

pick = raw_input()
    
answer = "%.2f" % round(data[pick]/3, 2)
print answer
