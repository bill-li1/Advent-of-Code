f = open("input.txt", "r")
s = f.read().strip()
# s += s[0]
ans = 0
# for i in range(len(s) - 1):
# 	if s[i] == s[i+1]:
# 		ans += int(s[i])
dist = len(s) // 2
for i in range(len(s)):
	idx = (i + dist) % len(s)
	if s[i] == s[idx]:
		ans += int(s[i])
		
print(ans)
