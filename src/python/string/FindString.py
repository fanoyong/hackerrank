s = raw_input()
t = raw_input()

i = s.find(t)
if i < 0:
    print 0
else:
    count = 1
    while i < len(s):
        i = s.find(t,i + len(t), len(s))
        if i > 0:
            count += 1
        else:
            i = len(s)
    print count
