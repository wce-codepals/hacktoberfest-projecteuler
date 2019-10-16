age = int(input("Please enter your age here:\n"))

if ((age >= 1) and (age <= 6)):
    print("Hi little baby")
elif ((age >= 6) and (age <= 12)):
    print("Hey little kid")
elif ((age >= 13) and (age <= 17)):
    print("Hey there teen")
elif ((age >= 18) and (age <= 40)):
    print("Hey you are an adult")
elif age >= 41:
    print("You are growing old. xP")
else:
    print("Re-enter your age")
