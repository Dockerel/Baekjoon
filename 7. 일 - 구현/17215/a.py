import sys

input = sys.stdin.readline

s = input().strip()

rounds = []
curr = ""
for c in s:
    if len(rounds) == 9:
        curr += c
        continue
    if c == "S":
        rounds.append("S")
        curr = ""
        continue
    curr += c
    if len(curr) == 2:
        rounds.append(curr)
        curr = ""
rounds.append(curr)

temp = rounds.pop()
rounds.extend([c for c in temp])


def to_score(s_score):
    if s_score == "S":
        return 10
    if "P" in s_score:
        return 10
    score = 0
    for c in s_score:
        if c == "-":
            continue
        score += int(c)
    return score


score = 0
for i in range(9):
    if rounds[i] == "S":
        score += to_score(rounds[i])
        if len(rounds[i + 1]) == 2:
            score += to_score(rounds[i + 1])
        else:
            score += to_score(rounds[i + 1])
            score += to_score(rounds[i + 2][0])
    elif "P" in rounds[i]:
        score += to_score(rounds[i])
        score += to_score(rounds[i + 1][0])
    else:
        score += to_score(rounds[i])

for i in range(9, len(rounds)):
    if rounds[i] == "P":
        score += 10 - int(rounds[i - 1])
        continue
    score += to_score(rounds[i])

print(score)
