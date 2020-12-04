with open("./input", "r") as f:
    answer_one = 0
    answer_two = 0
    for l in f.readlines():
        line = l.strip()
        limit, c, passw = line.split()

        ll, ul = [int(x) for x in limit.split('-')]
        char = c[0]
        count = sum(1 for x in passw if x == char)

        if ll <= count <= ul:
            answer_one += 1

        count_two = int(passw[ll-1] == char) + int(char == passw[ul-1])
        if count_two == 1:
            answer_two += 1

    print(answer_one)
    print(answer_two)

