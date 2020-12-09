

from collections import defaultdict

ALPHABET = "abcedfghijklmnopqrstuvwxyz"
with open("./input", "r") as f:
    count_one = 0
    curr_count = 0
    exists = defaultdict(int)

    count_two = 0
    group_size = 0

    for l in f.readlines():
        line = l.strip()

        if not line:
            count_one += len(exists.values())
            count_two += sum(1 for x in exists.values() if x == group_size)
            group_size = 0
            exists.clear()
            continue

        for c in line:
            exists[c] += 1

        group_size += 1


    print(count_one)
    print(count_two)
