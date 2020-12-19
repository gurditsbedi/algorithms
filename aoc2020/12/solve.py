

with open("./input", "r") as f:
    directions = ["E", "N", "W", "S", "E", "N", "W", "S"]
    currx = 0
    curry = 0
    currd = "E"
    for l in f.readlines():
        line = l.strip()
        ops = line[0]
        val = int(line[1:])

        if ops == "F":
            if currd == "E":
                currx += val
            elif currd == "W":
                currx -= val
            elif currd == "N":
                curry += val
            elif currd == "S":
                curry -= val
        elif ops == "L":
            t = val // 90
            currd = directions[directions.index(currd) + t]
        elif ops == "R":
            d = list(reversed(directions))
            t = val // 90
            currd = d[d.index(currd) + t]
        elif ops == "E":
            currx += val
        elif ops == "W":
            currx -= val
        elif ops == "N":
            curry += val
        elif ops == "S":
            curry -= val

    print(abs(currx) + abs(curry))
