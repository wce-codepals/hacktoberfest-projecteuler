# counting Sundays on the first of the month during the twentieth century
import calendar
count = 0
for i in range(1901, 2001):
    for j in range(1,13):
        if calendar.weekday(i,j,1) == 6:
            count += 1
print(count)