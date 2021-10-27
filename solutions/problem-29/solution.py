combinations = [ ]
for a in range(2,101):
	for b in range(2,101):
	      combinations.append(a**b)
new_combinations = list(combinations)
new_combinations_sorted = list(dict.fromkeys(new_combinations))
print(len(new_combinations_sorted))
