

from collections import defaultdict

word = "shiny gold"

mapper = defaultdict(list)

everyone = set()


def recursor(bag):
    if bag in mapper.keys():
        for b in mapper[bag]:
            everyone.add(b)
            recursor(b)


with open("./input", "r") as f:
    for l in f.readlines():
        line = l.strip()

        frm, to = line.split("contain")
        ins = [" ".join(x.split()[1:-1]) for x in to[:-1].split(",")]
        for t in ins:
            mapper[t].append(" ".join(frm.split(" ")[:-2]))

    count_one = recursor(word)
    print(len(everyone))


mappertwo = defaultdict(list)


def recursor_two(bag):
    if not mappertwo[bag]:
        return 0
    count = 0
    for subbag, subbag_count in mappertwo[bag]:
        count += subbag_count * (1 + recursor_two(subbag))
    return count


with open("./input", "r") as f:
    for l in f.readlines():
        line = l.strip()

        frm, to = line.split("contain")
        frm = " ".join(frm.split()[:-1])
        for x in to[:-1].split(","):
            a = x.split()
            if a[0] == "no":
                mappertwo[frm] = []
            else:
                t = (" ".join(a[1:-1]), int(a[0]))
                mappertwo[frm].append(t)

    print(recursor_two(word))
