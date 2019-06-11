n = int(input())
a = []

for i in range(n):
    s = input()
    if s not in a:
        a.append(s)
        
print ("Falta(m) " + str(151 - len(a)) + " pomekon(s).")