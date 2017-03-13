#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys


def pss(sudoku):
    sol = []
    for row in sudoku:
        tmp = list(map(str, row))
        sol.append(''.join(tmp))

    return ''.join(sol)

def findEmptyPosition(sudoku, l):
    for i in range(9):
        for j in range(9):
            if (sudoku[i][j] == 0):
                l[0] = i
                l[1] = j
                return True
    return False

def sudokuSolver(sudoku):
    l = [0,0]
    if (not findEmptyPosition(sudoku, l)):
        print(pss(sudoku))
        global sumAltogether
        tmp = sudoku[0][:3]
        tmp[0] *= 100
        tmp[1] *= 10
        sumAltogether += int(sum(tmp))
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
    if isinstance(sudoku, str):
        data = sudoku
        sudoku = [ list(map(int, list(data[i*9:i*9+9]))) for i in range(0,9)]
    print()
    for i in range(0,9):
        if i%3 == 0:
            print('-------------------------')
        for j in range(0,9):
            if j%3 == 0:
                print('| ', end='')
            print(sudoku[i][j], end=' ')

        print('|')
    print('-------------------------')
    print()

def main():
    # problem
    sudoku = [[]]*9
    t = input()
    # converting to 9x9 matrix
    for i in range(9):
        sudoku[i] = list(map(int, list(input())))

    sudokuSolver(sudoku)

if __name__ == "__main__":
    sumAltogether = 0
    n = 50
    for i in range(n):
        print("->->" + str(i))
        main()
        print(sumAltogether)
    print("Answer = " + str(sumAltogether))

