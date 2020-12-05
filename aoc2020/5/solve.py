

def binary_jumping(s, low_value, high_value, up_ins, low_ins):
    rows_low = low_value
    rows_high = high_value

    for ins in s:
        mid = (rows_low + rows_high) // 2
        if ins == up_ins:
            rows_high = mid
        elif ins == low_ins:
            rows_low = mid + 1

    return rows_low


with open("./input", "r") as f:
    max_seat = 0
    for l in f.readlines():
        line = l.strip()
        row_code = line[:7]
        col_code = line[7:]

        row = binary_jumping(row_code, 0, 127, "F", "B")
        col = binary_jumping(col_code, 0, 7, "L", "R")

        seat = row * 8 + col
        if seat > max_seat:
            max_seat = seat

    print(max_seat)

