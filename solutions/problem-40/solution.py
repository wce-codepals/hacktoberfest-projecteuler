s = ""
counter = 1

while len(s) < 1000000:
    s += str(counter)
    counter += 1

print(int(s[0]) * int(s[9]) * int(s[99]) * int(s[999]) * int(s[9999]) * int(s[99999]))
