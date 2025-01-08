file = open("input.txt", "r")
# file = open("input.txt", "r")
content = file.readline().strip()

blocks = []
for i in range(len(content)):
    val = int(content[i])
    if i % 2 == 0:
        blocks.extend([str(i // 2)] * val)
    else:
        blocks.extend(['.'] * val)

print(blocks)
back_counter = len(blocks) - 1
ans_arr = []
for i in range(len(blocks)):
    if i > back_counter:
        break
    if blocks[i] == '.':
        while(blocks[back_counter] == '.'):
            back_counter -= 1
        ans_arr.append(blocks[back_counter])
        back_counter -= 1
    else:
        ans_arr.append(blocks[i])

ans = 0
for i in range(len(ans_arr)):
    val = int(ans_arr[i])
    ans += val * i

print(ans)


