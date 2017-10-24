line = ''
with open('p042_words.txt') as file_handle:
    line = file_handle.readline()

words = line.replace('"', '').split(',')

# The largest word in the list is 14 letters and the largest possible letter is
# 'Z'. Therefore, only compute the triangle numbers up to 14 * (ord('Z') - 64)
max_triangle_number = 14 * (ord('Z') - 64)


def t_n(n):
    return 0.5 * n * (n + 1)

triangle_numbers = [1]
while triangle_numbers[-1] < max_triangle_number:
    triangle_numbers.append(t_n(len(triangle_numbers) + 1))


# ord('A') = 65, subtract 64 from each ord(letter) to get its position in the
# alphabet
def word_value(word):
    return sum([(ord(letter) - 64) for letter in word])


triangle_words = [(word_value(word) in triangle_numbers) for word in
                  words].count(True)
print(triangle_words)
