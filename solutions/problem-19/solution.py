from datetime import *

counter = 0
year = 1901
month = 1

curr_day = date(year,month,1)

while(curr_day.year < 2001):
	if(curr_day.weekday() == 6):
		counter += 1
	if(month+1 == 13):
		month = 1
		year += 1
	else:
		month += 1
	curr_day = date(year,month,1)

print("Sundays : " + str(counter))
