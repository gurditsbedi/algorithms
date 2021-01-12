

def cos(angle):
    if angle < 0:
        angle = -angle

    v = {
        90: 0,
        180: -1,
        270: 0,
    }[angle]

    return v


def sin(angle):
    neg = False
    if angle < 0:
        neg = True
        angle = -angle

    v = {
        90: 1,
        180: 0,
        270: -1,
    }[angle]

    return -v if neg else v


with open("./input", "r") as f:
    directions = ["E", "N", "W", "S", "E", "N", "W", "S"]
    d = list(reversed(directions))
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

    currx = 0
    curry = 0

    wpx = 10
    wpy = 1

    f.seek(0)
    for l in f.readlines():
        line = l.strip()
        ops = line[0]
        val = int(line[1:])
        # print(currx, curry, wpx, wpy)
        # print(ops, val)

        if ops == "F":
            currx += val * wpx
            curry += val * wpy
        elif ops == "L":
            nwpx = wpx * cos(val) - wpy * sin(val)
            nwpy = wpx * sin(val) + wpy * cos(val)
            wpx = nwpx
            wpy = nwpy
        elif ops == "R":
            val *= -1
            nwpx = wpx * cos(val) - wpy * sin(val)
            nwpy = wpx * sin(val) + wpy * cos(val)
            wpx = nwpx
            wpy = nwpy
        elif ops == "E":
            wpx += val
        elif ops == "W":
            wpx -= val
        elif ops == "N":
            wpy += val
        elif ops == "S":
            wpy -= val

    print(abs(currx) + abs(curry))
