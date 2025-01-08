from collections import defaultdict

file = open("input.txt", "r")

nodes = defaultdict(list)

rows = 0
cols = 0
for line in file.readlines():
	line = line.strip()
	cols = len(line)
	for col in range(len(line)):
		if line[col] != '.':
			nodes[line[col]].append((rows, col))
	rows += 1

ans = set()
for l in nodes:
	points = nodes[l]
	for i in range(len(points) - 1):
		for j in range(i+1, len(points)):
			r1, c1 = points[i]
			r2, c2 = points[j]
			ans.add((r1, c1))
			ans.add((r2, c2))
			if (r1 >= r2 and c1 >= c2) or (r2 >= r1 and c2 >= c1):
				# line has negative slope
				# go left
				diffr = r1 - r2
				diffc = c1 - c2
				while True:
					a2r = r2 - diffr
					a2c = c2 - diffc
					if a2r >= 0 and a2r < rows and a2c >= 0 and a2c < cols:
						ans.add((a2r, a2c))
						r2 = a2r
						c2 = a2c
					else:
						break
				# go right
				while True:
					a1r = r1 + diffr
					a1c = c1 + diffc
					if a1r >= 0 and a1r < rows and a1c >= 0 and a1c < cols:
						ans.add((a1r, a1c))
						r1 = a1r
						c1 = a1c
					else:
						break
			else:
				# line has positive slope
				# go left
				# go right
				diffr = abs(r1 - r2)
				diffc = abs(c1 - c2)
				lowerr = min(r1, r2)
				higherr = max(r1, r2)
				lowerc = min(c1, c2)
				higherc = max(c1, c2)
				while True:
					a1r = lowerr - diffr
					a1c = higherc + diffc
					if a1r >= 0 and a1r < rows and a1c >= 0 and a1c < cols:
						ans.add((a1r, a1c))
						lowerr = a1r
						higherc = a1c
					else:
						break

				while True:
					a2r = higherr + diffr
					a2c = lowerc - diffc
					if a2r >= 0 and a2r < rows and a2c >= 0 and a2c < cols:
						ans.add((a2r, a2c))
						higherr = a2r
						lowerc = a2c
					else:
						break

print(len(ans))
