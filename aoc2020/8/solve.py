

def run(intructions):
    acc = 0
    visited = [False for _ in intructions]
    i = 0
    while i < len(intructions):
        if visited[i] == True:
            return (True, acc)

        visited[i] = True
        if intructions[i][0] == "acc":
            acc += intructions[i][1]
            i += 1
        elif intructions[i][0] == "jmp":
            i += intructions[i][1]
        elif intructions[i][0] == "nop":
            i += 1

    return (False, acc)


with open("./input", "r") as f:
    intructions = []
    for l in f.readlines():
        line = l.strip().split(" ")
        intructions.append((line[0], int(line[1])))

    print(run(intructions)[1])

    for i in range(len(intructions)):
        new_instructions = intructions[:]

        if intructions[i][0] == "nop":
            new_instructions[i] = ("jmp", new_instructions[i][1])
        elif intructions[i][0] == "jmp":
            new_instructions[i] = ("nop", new_instructions[i][1])

        res = run(new_instructions)
        if res[0] == False:
            print(res[1])
            break
