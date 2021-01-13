def masked(mask, value):
    maskand = int(mask.replace("X", "1", len(mask)), 2)
    maskor = int(mask.replace("X", "0", len(mask)), 2)
    ans = (maskor | value) & maskand
    return ans


with open("./input", "r") as f:
    mem = {}
    mask = ""
    mk = 0
    mv = 0
    for l in f.readlines():
        line = l.strip()
        if line.startswith("mask"):
            mask = line.split()[-1]
        if line.startswith("mem"):
            t = line[4:].split()
            mk = int(t[0][:-1])
            mv = int(t[-1])

            mem[mk] = masked(mask, mv)

    print(sum(mem.values()))
