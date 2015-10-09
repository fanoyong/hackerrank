X = int(raw_input())
Y = int(raw_input())
Z = int(raw_input())
N = int(raw_input())

xl = [x for x in range(X+1)]
yl = [x for x in range(Y+1)]
zl = [x for x in range(Z+1)]
answer = []

for x in xl:
    for y in yl:
        for z in zl:
            if x+y+z != N:
                answer.append([x,y,z])

print answer
