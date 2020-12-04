

mandatory = set(["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"])
hexa = "0123456789abcdef"

def check(d):
    if not (1920 <= int(d["byr"]) <= 2002):
        return False
    if not (2010 <= int(d["iyr"]) <= 2020):
        return False
    if not (2020 <= int(d["eyr"]) <= 2030):
        return False
    if not ((d["hgt"][-2:] == "cm" and (150 <= int(d["hgt"][:-2]) <= 193)) or (d["hgt"][-2:] == "in" and (59 <= int(d["hgt"][:-2]) <= 76))):
        return False
    if not (d["hcl"][0] == "#" and all(x in hexa for x in d["hcl"][1:])):
        return False
    if not (d["ecl"] in ["amb","blu","brn","gry","grn","hzl","oth"]):
        return False
    if not (len(d["pid"]) == 9 and d["pid"].isnumeric()):
        return False

    return True


with open("./input", "r") as f:
    ids = [{}]
    i = 0
    curr_user = {}
    count_one =  0
    count_two =  0
    for l in f.readlines():
        line = l.strip()
        if len(line) == 0:
            if mandatory <= set(curr_user.keys()):
                count_one += 1
                if check(curr_user):
                    count_two += 1
            ids[i] = curr_user
            curr_user = {}
            i+=1
            ids.append({})
            continue
        # print(line)
        kvs =  {x[0]:x[1] for x in [s.split(":") for s in line.split()]}
        curr_user.update(kvs)


    print(f"count_one = {count_one}")
    print(f"count_two = {count_two}")



