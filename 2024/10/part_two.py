import time
start_time = time.perf_counter()

f = open("input.txt", "r")
lines = f.readlines()

starts = []
map = []

for i in range(len(lines)):
    line = lines[i].strip()
    int_map = []
    for j in range(len(line)):
        if line[j] == '0':
            starts.append((i, j))
        int_map.append(int(line[j]))
    map.append(int_map)

ans = 0

for start in starts:
    row = start[0]
    col = start[1]
    stack = [(row, col)]
    ans_set = set()
    while len(stack) > 0:
        elm = stack.pop()
        r = elm[0]
        c = elm[1]
        if map[r][c] == 9:
            ans += 1
            ans_set.add((r, c))
            continue
        if r > 0 and map[r-1][c] == map[r][c] + 1:
            stack.append((r-1, c))
        if c > 0 and map[r][c-1] == map[r][c] + 1:
            stack.append((r, c-1))
        if r < len(map) - 1 and map[r+1][c] == map[r][c] + 1:
            stack.append((r+1, c))
        if c < len(map[0]) - 1 and map[r][c+1] == map[r][c] + 1:
            stack.append((r, c+1))

    # ans += len(ans_set)

print(ans)

end_time = time.perf_counter()

print(f"Execution time: {end_time - start_time:.4f} seconds")
