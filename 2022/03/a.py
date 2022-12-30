f = open("input.txt", "r")


def solutionOne():
    sum = 0
    for line in f:
        line = line.strip()
        first = line[:int((len(line)) / 2)]
        second = line[int((len(line)) / 2):]
        ans = [a for a in first if a in second][0]
        if ans >= 'a':
            sum += ord(ans) - ord('a') + 1
        else:
            sum += ord(ans) - ord('A') + 1 + 26
    print(sum)


def solutionTwo():
    sum = 0
    allLines = f.readlines()
    for i in range(0, len(allLines), 3):
        line = allLines[i].strip()
        lineTwo = allLines[i + 1].strip()
        lineThree = allLines[i + 2].strip()
        ans = [a for a in line if a in lineTwo and a in lineThree][0]
        if ans >= 'a':
            sum += ord(ans) - ord('a') + 1
        else:
            sum += ord(ans) - ord('A') + 1 + 26
    print(sum)


solutionTwo()
