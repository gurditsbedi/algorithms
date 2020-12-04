


def calc(tree, r, c, step_right, step_down):
    count = 0
    i = 0
    j = 0
    while i < r and j < c:

        if trees[i][j] == '#':
            count += 1

        if i + step_down >= r:
            return count

        i = (i+step_down) % r
        j = (j+step_right) % c

    return count


with open("./input", "r") as f:
    trees = [x.strip() for x in f.readlines()]
    # print(trees)
    r = len(trees)
    c = len(trees[0])
    answer_one = 0


    answer_one = calc(trees, r, c, 3, 1)

    print(answer_one)

    answer_two = 1
    answer_two *= calc(trees, r, c, 1, 1)
    answer_two *= calc(trees, r, c, 3, 1)
    answer_two *= calc(trees, r, c, 5, 1)
    answer_two *= calc(trees, r, c, 7, 1)
    answer_two *= calc(trees, r, c, 1, 2)

    print(answer_two)
