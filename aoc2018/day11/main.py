
GRID_SERIAL = 5235  # input

def power_level(x, y, gridserial = GRID_SERIAL):
    rackID = x + 10
    pl = rackID * y + gridserial
    pl *= rackID
    return (pl // 100) % 10 - 5


assert power_level(3, 5, 8) == 4
assert power_level(122, 79, 57) == -5
assert power_level(217, 196, 39) == 0
assert power_level(101, 153, 71) == 4


def solve(small_grid_size):
    grid = [[power_level(i, j) for i in range(300)] for j in range(300)]

    ans = { 'x': 0, 'y': 0, 'min_': -1000 }

    for i in range(0, 300 - small_grid_size + 1):
        for j in range(0, 300 - small_grid_size + 1):
            x = 0
            for k in range(small_grid_size):
                x += sum(grid[i+k][j:j+3])

            if x > ans['min_']:
                ans = { 'x': j, 'y': i, 'min_': x }

    return ans


def part1():
    ans = solve(3)
    print(f"{ans['x']},{ans['y']}")


def part2():
    grid = [[power_level(i, j) for i in range(300)] for j in range(300)]

    g = grid[:]

    ans = { 'x': 0, 'y': 0, 'min_': -1000 }

    for size in range(1, 300):
        for i in range(0, 298):
            for j in range(0, 298):
                row = sum(

                g =

    for i in range(0, 300 - small_grid_size + 1):
        for j in range(0, 300 - small_grid_size + 1):
            x = 0
            for k in range(small_grid_size):
                x += sum(grid[i+k][j:j+3])

            if x > ans['min_']:
                ans = { 'x': j, 'y': i, 'min_': x }

    return ans

# part1()
part2()
