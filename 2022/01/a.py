f = open("input.txt", "r")


def solution_one():
    max = 0
    cur = 0
    for line in f:
        if line == '\n':
            max = max if max > cur else cur
            cur = 0
        else:
            cur += int(line)

    max = max if max > cur else cur
    print(max)


def solution_two():
    ans_arr = []
    cur = 0
    for line in f:
        if line == '\n':
            ans_arr.append(cur)
            cur = 0
        else:
            cur += int(line)
    ans_arr.append(cur)
    ans_arr.sort()
    print(sum(ans_arr[-3:]))


solution_two()
