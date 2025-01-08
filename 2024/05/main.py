f = open("input.txt", "r")

ordering = []
ans = 0

for line in f:
	if '|' in line:
		a, b = map(int, line.split("|"))
		ordering.append([a, b])
	if ',' in line:
		elms = list(map(int, line.split(",")))
		is_wrong = False
		while(True):
			flag = True
			for rule in ordering:
				first, second = rule
				if first in elms and second in elms:
					first_i = elms.index(first)
					second_i = elms.index(second)
					if first_i >= second_i:
						is_wrong = True
						flag = False
						elms[first_i] = second
						elms[second_i] = first
						break
			if flag:
				break
		if is_wrong:
			ans += elms[(len(elms) - 1) // 2]
print(ans)
