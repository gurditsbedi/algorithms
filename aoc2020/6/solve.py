

from collections import defaultdict

ALPHABET = "abcedfghijklmnopqrstuvwxyz"
with open("./input", "r") as f:
    count_one = 0
    curr_count = 0
    exists = defaultdict(int)

    for l in f.readlines():
        line = l.strip()

        if len(line) == 0:
            count_one += len(exists.values())
            exists.clear()

        for c in line:
            exists[c] = 1


    print(count_one)
