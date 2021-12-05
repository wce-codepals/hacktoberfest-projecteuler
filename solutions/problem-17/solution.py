#solution to problem 17
from random import randint

digit_to_word = {
"1": "one",
"2": "two",
"3": "three",
"4": "four",
"5": "five",
"6": "six",
"7": "seven",
"8": "eight",
"9": "nine"
}

thy_to_word = {
"2": "twenty",
"3": "thirty",
"4": "forty",
"5": "fifty",
"6": "sixty",
"7": "seventy",
"8": "eighty",
"9": "ninety"
}

teen_to_word = {
"10": "ten",
"11": "eleven",
"12": "twelve",
"13": "thirteen",
"14": "fourteen",
"15": "fifteen",
"16": "sixteen",
"17": "seventeen",
"18": "eighteen",
"19": "nineteen"
}

hundred = "hundred"
thousand = "thousand"

def number_to_english(x):
	if(len(str(x))>=5):
		return "Too big number"

	thousand_str = None
	hundred_str = None
	ten_str = None
	digit_str = None

	if(len(str(x))>=4) and (str(x)[-4]!="0"):
		thousand_str = digit_to_word[str(x)[-4]] + " " + thousand
	
	if(len(str(x))>=3) and (str(x)[-3]!="0"):
		hundred_str = digit_to_word[str(x)[-3]] + " " + hundred

	if( ((x-round(x/100)*100)>=10) and ((x-round(x/100)*100)<20)):
		last_two = str(x)[-2:]
		digit_str = teen_to_word[last_two]
	else:
		if(len(str(x))>=2) and (str(x)[-2]!="0"):
			ten_str = thy_to_word[str(x)[-2]]

		if(len(str(x))>0) and (str(x)[-1]!="0"):
			digit_str = digit_to_word[str(x)[-1]]

	res = ""
	if(thousand_str):
		res = thousand_str + " "
	if(hundred_str):
		res = res + hundred_str + " "
	if (thousand_str or hundred_str) and (ten_str or digit_str):
		res = res + "and "
	if ten_str:
		res = res + ten_str
	if ten_str and digit_str:
		res = res + "-"
	if digit_str:
		res = res + digit_str

	return res

sum = 0

for x in xrange(1,1001):
	sum = sum + len(number_to_english(x).replace('-', '').replace(' ', ''))

print(sum)
