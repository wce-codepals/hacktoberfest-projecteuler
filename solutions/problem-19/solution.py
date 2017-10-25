#You are given the following information, but you may prefer to do some research for yourself.
#
#Jan 1900 was a Monday.
#Thirty days has September,
#April, June and November.
#All the rest have thirty-one,
#Saving February alone,
#Which has twenty-eight, rain or shine.
#And on leap years, twenty-nine.
#A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
#How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

def mondayCounter():
    sundayTheFirst = 0
    daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    days = ['monday', 'tuesday', 'wednesday', 'thursday', 'friday', 'saturday', 'sunday']
    currentDay = 0
    dayInMonth = 0
    year = 1901
    currentMonth = 0
    while not(year == 2001):
        currentDay += 1
        dayInMonth +=1
        dayOfWeek = days[(currentDay % 7)]
        if dayInMonth > daysInMonth[currentMonth]:
            if(currentMonth == 11):
                year += 1
                if(year % 4 == 0):
                    daysInMonth[1] = 29
                else:
                    daysInMonth[1] = 28
            currentMonth = (currentMonth + 1) % 12
            dayInMonth = 1
        if(dayOfWeek == 'sunday' and dayInMonth == 1):
            sundayTheFirst += 1
    return sundayTheFirst

print(mondayCounter())