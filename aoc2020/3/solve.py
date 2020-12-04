



with open("./input", "r") as f:
    trees = [x.strip() for x in f.readlines()]
    # print(trees)
    r = len(trees)
    c = len(trees[0])
    answer_one = 0

    i = 0
    j = 0
    run = True

    while i < r and j < c:
        if trees[i][j] == '#':
            answer_one += 1
        i += 1
        j = (j+3) % c

    print(answer_one)
