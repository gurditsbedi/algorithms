def dist_possible_2(num_boxes, boxes, num_children):
    # print(num_boxes, boxes, num_children)
    psb = [[False for j in range(num_children + 1)] for i in range(num_boxes + 1)]

    for box in range(num_boxes + 1):
        psb[box][0] = True

    for i in range(num_boxes + 1):
        for j in range(num_children + 1):
            if j < boxes[i - 1]:
                psb[i][j] = psb[i - 1][j]
            else:
                psb[i][j] = psb[i - 1][j] or psb[i - 1][j - boxes[i - 1]]

    # for i in range(num_boxes + 1):
        # for j in range(num_children + 1):
            # print(psb[i][j], end=" ")
        # print()

    return psb[num_boxes][num_children]


def dist_possible(num_boxes, boxes, num_children):
    # print(num_boxes, boxes, num_children)
    if num_children == 0:
        return True
    elif num_children > 0 and num_boxes == 0:
        return False
    elif boxes[num_boxes - 1] > num_children:
        return dist_possible(num_boxes - 1, boxes, num_children)
    else:
        return dist_possible(num_boxes - 1, boxes, num_children) or dist_possible(num_boxes - 1, boxes, num_children - boxes[num_boxes - 1])


def solve():
    testcases = int(input())
    for _ in range(testcases):
        boxes = [int(x) for x in input().split(' ')]
        num_children = int(input())
        if sum(boxes[1:]) < num_children:
            result = False
        else:
            result = dist_possible(boxes[0], boxes[1:], num_children)
        # print(boxes[0], boxes[1:], num_children, result)
        print("YES" if result else "NO")

solve()
