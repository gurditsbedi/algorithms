
TEST_INPUT = open('./input.txt').readlines()
SAMPLE_INPUT = open('./sample.txt').readlines()

def parseInput(inp):
    raise NotImplementedError


def solve_part1(points):
    raise NotImplementedError


def solve_part2(points, limit):
    raise NotImplementedError


def solve():
    # SAMPLE_TESTING
    sample_parsed = parseInput(SAMPLE_INPUT)

    sample_part1 = solve_part1(sample_parsed)
    assert sample_part1 == 0

    # sample_part2 = solve_part2(sample_parsed)
    # assert sample_part2 == 0

    # INPUT_TESTING
    # test_parsed = parseInput(TEST_INPUT)

    # part1 = solve_part1(test_parsed)
    # print('part1:', part1)

    # part2 = solve_part2(test_parsed)
    # print('part2:', part2)

    # regression
    # assert part1 == 0
    # assert part2 == 0

solve()
