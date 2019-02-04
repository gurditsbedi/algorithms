from collections import defaultdict, OrderedDict

TEST_INPUT = open('./input.txt').readlines()
SAMPLE_INPUT = open('./sample.txt').readlines()


def parseInput(inp):
    parse = []
    for line in inp:
        l = line.split(' ')
        parse.append((l[1], l[-3]))
    return parse


def solve_part1(insts):
    q = list(set(t[0] for t in insts) - set(t[1] for t in insts))
    order = ''
    visited = set()

    req = defaultdict(set)
    for t in insts:
        req[t[1]].add(t[0])

    nextt = defaultdict(set)
    for t in insts:
        nextt[t[0]].add(t[1])

    while len(q):
        q.sort()

        curr = q.pop(0)
        visited.add(curr)

        if curr not in order:
            order += curr

        present = set(q).union(visited)

        for n in nextt[curr]:
            req_for_n_fullfilled = all([x in visited for x in req[n]])
            if n not in present and req_for_n_fullfilled:
                q.append(n)

    return order

def solve_part2(insts, ws):
    q = list(set(t[0] for t in insts) - set(t[1] for t in insts))
    order = ''
    visited = set()

    req = defaultdict(set)
    for t in insts:
        req[t[1]].add(t[0])

    nextt = defaultdict(set)
    for t in insts:
        nextt[t[0]].add(t[1])

    while len(q):
        q.sort()

        curr = q.pop(0)
        visited.add(curr)

        if curr not in order:
            order += curr

        present = set(q).union(visited)

        for n in nextt[curr]:
            req_for_n_fullfilled = all([x in visited for x in req[n]])
            if n not in present and req_for_n_fullfilled:
                q.append(n)

    return order



def solve():
    # SAMPLE_TESTING
    sample_parsed = parseInput(SAMPLE_INPUT)

    sample_part1 = solve_part1(sample_parsed)
    assert sample_part1 == 'CABDFE'

    sample_part2 = solve_part2(sample_parsed, 1+1)
    assert sample_part2 == 15

    # INPUT_TESTING
    test_parsed = parseInput(TEST_INPUT)

    part1 = solve_part1(test_parsed)
    print('part1:', part1)

    # part2 = solve_part2(test_parsed, 1+4)
    # print('part2:', part2)

    # regression
    # assert part1 == 4754
    # assert part2 == 42344

solve()
