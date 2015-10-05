
N = int(raw_input())
data = []
for i in range(0,N):
    line = raw_input().split()
    if line[0] == 'print':
        print data
    elif line[0] == 'append':
        param1 = int(line[1])
        data.append(param1)
    elif line[0] == 'extend':
        param1 = line[1]
        data.extend(param1)
    elif line[0] == 'insert':
        param1 = int(line[1])
        param2 = int(line[2])
        data.insert(param1, param2)
    elif line[0] == 'remove':
        param1 = int(line[1])
        data.remove(param1)
    elif line[0] == 'pop':
        data.pop()
    elif line[0] == 'index':
        param1 = int(line[1])
        print data.index(param1)
    elif line[0] == 'count':
        param1 = int(line[1])
        print data.count(param1)
    elif line[0] == 'sort':
        data.sort()
    elif line[0] == 'reverse':
        data.reverse()

