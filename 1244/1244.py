n = int(input())

for i in range(n):
    s = input()
    print(" ".join(sorted(s.split(), key=len, reverse=True)))