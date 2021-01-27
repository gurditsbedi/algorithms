from collections import defaultdict


def masked(mask, value):
    maskand = int(mask.replace("X", "1", len(mask)), 2)
    maskor = int(mask.replace("X", "0", len(mask)), 2)
    ans = (maskor | value) & maskand
    return ans


def binary_string_from_pattern_generator(s):
    if "X" in s:
        yield from binary_string_from_pattern_generator(s.replace("X", "0", 1))
        yield from binary_string_from_pattern_generator(s.replace("X", "1", 1))
    else:
        yield s


def masking_two(mask, value):
    bmask = list(mask)
    bvalue_ = f"{value:0b}"
    bvalue = ["0"] * (36 - len(bvalue_)) + list(bvalue_)
    bresult = ["0"] * 36
    c = 0
    for i in range(36):
        if bmask[i] == "0":
            bresult[i] = bvalue[i]
        elif bmask[i] == "1":
            bresult[i] = "1"
        elif bmask[i] == "X":
            c += 1
            bresult[i] = bmask[i]

    gen = binary_string_from_pattern_generator("".join(bresult))
    addresses = [next(gen) for _ in range(2 ** c)]

    return addresses


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

    f.seek(0)
    mem = defaultdict(int)
    for l in f.readlines():
        line = l.strip()
        if line.startswith("mask"):
            mask = line.split()[-1]
        if line.startswith("mem"):
            t = line[4:].split()
            mk = int(t[0][:-1])
            mv = int(t[-1])

            addresses = masking_two(mask, mk)
            for adr in addresses:
                mem[adr] = mv

    print(sum(mem.values()))
