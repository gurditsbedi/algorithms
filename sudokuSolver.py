#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# A sudoku Solver

def pss(sudoku):
    ''' Prints the sudoku(9x9matrix) in a string '''
    sol = []
    for row in sudoku:
        tmp = list(map(str, row))
        sol.append(''.join(tmp))

    return ''.join(sol)

def findEmptyPosition(sudoku, l):
    ''' Finds the first empty position,
        When Travelling left to right and top to bottom. '''
    for i in range(9):
        for j in range(9):
            if (sudoku[i][j] == 0):
                l[0] = i
                l[1] = j
                return True
    return False

def sudokuSolver(sudoku):
    ''' Solves the sudoku. '''
    l = [0,0]
    if (not findEmptyPosition(sudoku, l)):
        print(pss(sudoku))
        return True

    x = l[0]
    y = l[1]

    for num in range(1, 10):
        # print(x, y, "->-> " + str(p))
        # printSudoku(sudoku)
        # print(isLocationSafe(sudoku))
        if (isLocationSafe(sudoku, num, x, y)):
            sudoku[x][y] = num

            if (sudokuSolver(sudoku)):
                return True

            sudoku[x][y] = 0

def isLocationSafe(sudoku, num, x, y):
    ''' checks whether the num:param can be
        placed at (x:param,y:param) in the sudoku.
        returns True if possible else False. '''
    # checking row wise duplicasy
    for i in range(9):
        if (sudoku[x][i] == num):
            return False

    # checking column wise duplicasy
    for i in range(9):
        if (sudoku[i][y] == num):
            return False

    # checking boxes
    x = x - x%3
    y = y - y%3
    box = []
    for i in range(3):
        for j in range(3):
            if (sudoku[i+x][j+y] == num):
                return False

    # if everything fine return True
    return True

def printSudoku(sudoku):
    ''' A nice way to print the sudoku grid. '''
    for i in range(0,9):
        if i%3 == 0:
            print('-------------------------')
        for j in range(0,9):
            if j%3 == 0:
                print('| ', end='')
            print(sudoku[i][j], end=' ')

        print('|')
    print('-------------------------')

def main():
    data = input()

    # converting to 9x9 matrix
    sudoku = [ list(map(int, list(data[i*9:i*9+9]))) for i in range(0,9)]

    # Solving the sudoku
    sudokuSolver(sudoku)

if __name__ == "__main__":
    main()

