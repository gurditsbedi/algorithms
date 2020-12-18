def grid_equal(grid, next_grid):
    row = len(grid)
    col = len(grid[0])
    for r in range(row):
        for c in range(col):
            if grid[r][c] != next_grid[r][c]:
                return False

    return True


def print_grid(grid):
    for r in grid:
        print("".join(r))

def visible_seat_type(grid, r, idx):
    ri, rj = r
    i, j = idx
    if i == 0 and j == 0:
        return '.'

    row = len(grid)
    col = len(grid[0])
    for a in range(1, max(row, col)):
        x = ri + a * i
        y = rj + a * j
        if 0 < x < row -1 and 0 < y < col -1:
            el = grid[x][y]
            if el != '.':
                return el
        else:
            break

    return '.'


with open("./input", "r") as f:
    grid = []
    for l in f.readlines():
        grid.append(list('.' + l.strip() + '.'))

    col = len(grid[0])

    grid = [list('.' * col)] + grid + [list('.' * col)]
    original = [row[:] for row in grid]

    row = len(grid)
    col = len(grid[0])

    while True:
        next_grid = [row[:] for row in grid]

        for ri in range(1, row - 1):
            for ci in range(1, col - 1):
                if grid[ri][ci] == '.':
                    continue

                count = {'.': 0, 'L': 0, '#': 0}  # floor(.) occupied(#) empty(L)
                count[grid[ri][ci]] = -1
                for i in [-1, 0, 1]:
                    for j in [-1, 0, 1]:
                        count[grid[ri + i][ci + j]] += 1

                if grid[ri][ci] == 'L' and count['#'] == 0:
                    next_grid[ri][ci] = '#'
                if grid[ri][ci] == '#' and count['#'] >= 4:
                    next_grid[ri][ci] = 'L'

        if grid_equal(grid, next_grid):
            r = sum(1 for r in range(row) for c in range(col) if next_grid[r][c] == '#')
            print(r)
            break

        grid = [row[:] for row in next_grid]

    grid = [row[:] for row in original]

    while True:
        next_grid = [row[:] for row in grid]

        for ri in range(1, row - 1):
            for ci in range(1, col - 1):
                if grid[ri][ci] == '.':
                    continue

                count = {'.': 0, 'L': 0, '#': 0}  # floor(.) occupied(#) empty(L)
                for i in [-1, 0, 1]:
                    for j in [-1, 0, 1]:
                        count[visible_seat_type(grid, (ri, ci), (i, j))] += 1

                if grid[ri][ci] == 'L' and count['#'] == 0:
                    next_grid[ri][ci] = '#'
                if grid[ri][ci] == '#' and count['#'] >= 5:
                    next_grid[ri][ci] = 'L'

        if grid_equal(grid, next_grid):
            r = sum(1 for r in range(row) for c in range(col) if next_grid[r][c] == '#')
            print(r)
            break

        grid = [row[:] for row in next_grid]
