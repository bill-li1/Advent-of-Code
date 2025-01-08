file = open("input.txt", "r")
# file = open("test.txt", "r")
content = file.readline().strip()

blocks = []
for i in range(len(content)):
    val = int(content[i])
    if i % 2 == 0:
        blocks.append((str(i // 2), val))
    else:
        blocks.append(('.' , val))

ans_arr = []
for i in range(len(blocks)):
    block = blocks[i]
    if block[0] == '.':
        num_spaces = block[1]
        while True:
            found = False
            for j in range(len(blocks) - 1, i, -1):
                if blocks[j][0] != '.' and blocks[j][1] <= num_spaces:
                    ans_arr.append(blocks[j])
                    found = True
                    num_spaces -= blocks[j][1]
                    blocks[j] = ('.', blocks[j][1])
                    break
            if not found:
                if num_spaces > 0:
                    ans_arr.append(('.', num_spaces))
                break
    else:
        ans_arr.append(block)

print(ans_arr)

ans = 0
index = 0
for elm in ans_arr:
    val = elm[0]
    num = elm[1]
    if val == '.':
        index += num
    else:
        for j in range(num):
            ans += int(val) * index
            index += 1
print(ans)
