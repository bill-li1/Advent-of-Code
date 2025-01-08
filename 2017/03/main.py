n = 23
i = 1
while(True):
    if i * i > n:
        i -= 2
        break
    i += 2

print(i)
a = (i - 1) // 2
x = a
y = -a
x += 1
ans = i * i + 1

print(x, y)


