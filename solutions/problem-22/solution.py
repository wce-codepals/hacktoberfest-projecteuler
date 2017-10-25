#solution to problem 22 using document names.txt
with open ("names.txt", "r") as my_file:
    file = my_file.read().split(',')
names = []
for i in file:
    names.append(i.strip('"'))

def total_name_scores(names):
    sorted_names = sorted(names)  #names sorted alphabetically
    names_dict = {}
    total = 0
    for name in sorted_names:
        value = 0
        for letter in name:
            value += ord(letter) - 64 #finds each letters place in the alphabet and adds it to value
        total += value * (sorted_names.index(name) + 1) #multiplies value by the names place in the list
    return total





print(total_name_scores(names))
