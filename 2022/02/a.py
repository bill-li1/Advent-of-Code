f = open("input.txt", "r")

ROCK = 1
PAPER = 2
SCISSORS = 3
WIN = 6
DRAW = 3
LOSS = 0
OUTCOMES_A = {
        "A X": ROCK + DRAW,
        "A Y": PAPER + WIN,
        "A Z": SCISSORS + LOSS,
        "B X": ROCK + LOSS,
        "B Y": PAPER + DRAW,
        "B Z": SCISSORS + WIN,
        "C X": ROCK + WIN,
        "C Y": PAPER + LOSS,
        "C Z": SCISSORS + DRAW,
}


def solution_one():
    score = 0
    for line in f:
        score += OUTCOMES_A[line.strip()]
    print(score)


OUTCOMES_B = {
        "A X": SCISSORS + LOSS,
        "A Y": ROCK + DRAW,
        "A Z": PAPER + WIN,
        "B X": ROCK + LOSS,
        "B Y": PAPER + DRAW,
        "B Z": SCISSORS + WIN,
        "C X": PAPER + LOSS,
        "C Y": SCISSORS + DRAW,
        "C Z": ROCK + WIN,
}


def solution_two():
    score = 0
    for line in f:
        score += OUTCOMES_B[line.strip()]
    print(score)


solution_two()
