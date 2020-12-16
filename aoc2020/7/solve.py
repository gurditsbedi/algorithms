

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

    count_one = 0
    count_one = recursor(word)
    print(len(everyone))
