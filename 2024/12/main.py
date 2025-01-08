f = open("test.txt", "r")

m = []

for line in f.readlines():
    m.append(line.strip())

num_rows = len(m)
num_cols = len(m[0])

v = [[False for _ in range(num_cols)] for _ in range(num_rows)]

def calc_perimeter(row, col, pattern):
    perimeter = 4
    if row > 0 and m[row - 1][col] == pattern:
        perimeter -= 1
    if row < num_rows - 1 and m[row + 1][col] == pattern:
        perimeter -= 1
    if col > 0 and m[row][col - 1] == pattern:
        perimeter -= 1
    if col < num_cols - 1 and m[row][col + 1] == pattern:
        perimeter -= 1
    return perimeter

def calc(row, col):
    pattern = m[row][col]
    area = 0
    perimeter = 0
    q = [(row, col)]
    while len(q) > 0:
        row, col = q.pop()
        if v[row][col]:
            continue
        v[row][col] = True
        area += 1
        perimeter += calc_perimeter(row, col, pattern)
        if row > 0 and not v[row - 1][col] and m[row - 1][col] == pattern:
            q.append((row - 1, col))
        if col > 0 and not v[row][col - 1] and m[row][col - 1] == pattern:
            q.append((row, col - 1))
        if row < num_rows - 1 and not v[row + 1][col] and m[row + 1][col] == pattern:
            q.append((row + 1, col))
        if col < num_cols - 1 and not v[row][col + 1] and m[row][col + 1] == pattern:
            q.append((row, col + 1))

    return (area, perimeter)

ans = 0

for i in range(num_rows):
    for j in range(num_cols):
        if not v[i][j]:
            a, p = calc(i, j)
            print(a, p)
            ans += a * p

print(ans)
