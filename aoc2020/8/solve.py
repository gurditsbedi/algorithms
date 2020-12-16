

accumulator_one = 0
with open("./input", "r") as f:
    intructions = []
    for l in f.readlines():
        line = l.strip().split(" ")
        intructions.append((line[0], int(line[1])))

    # print(intructions)

    visited = [False for _ in intructions]
    i = 0
    while True:
        # print(intructions[i])
        if visited[i] == True:
            print(accumulator_one)
            break

        visited[i] = True
        if intructions[i][0] == "acc":
            accumulator_one += intructions[i][1]
            i += 1
        elif intructions[i][0] == "jmp":
            i += intructions[i][1]
        elif intructions[i][0] == "nop":
            i += 1

