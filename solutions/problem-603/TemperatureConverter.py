# decides which formula to use for conversion
def convert(temperature, unit1, unit2):

    # If no conversion is needed
    if unit1 == unit2:
        return temperature

    # if converting from celsius
    elif unit1 == 'C':
        if unit2 == 'F':
            return celsius_to_fahrenheit(temperature)
        else:
            return celsius_to_kelvin(temperature)

    # if converting from fahrenheit
    elif unit1 == 'F':
        if unit2 == 'C':
            return fahrenheit_to_celsius(temperature)
        else:
            return fahrenheit_to_kelvin(temperature)

    # if converting from kelvin
    elif unit1 == 'K':
        if unit2 == 'C':
            return kelvin_to_celsius(temperature)
        else:
            return kelvin_to_fahrenheit(temperature)


def celsius_to_fahrenheit(C):
    return (C*(9/5)) + 32


def celsius_to_kelvin(C):
    return C + 273.15


def fahrenheit_to_celsius(F):
    return (F - 32)*(5/9)


def fahrenheit_to_kelvin(F):
    return (F + 459.67)*(5/9)


def kelvin_to_celsius(K):
    return K - 273.15


def kelvin_to_fahrenheit(K):
    return (K*(9/5)) - 459.67


# receives input from user
while True:
    try:
        temperature = float(input("Please input temperature: "))
        break
    except ValueError:
        print("Invalid input")
        continue
    else:
        break
unit1 = input(
    "Please input original unit of temperature (C - Celsius, F - Fahrenheit, K - Kelvin): ")
unit2 = input(
    "Please input unit to convert to (C - Celsius, F - Fahrenheit, K - Kelvin): ")

final_temperature = convert(temperature, unit1, unit2)

# %.2f prints final temperature rounded off to 2 decimal places
print(temperature, unit1, "is equivalent to %.2f" % final_temperature, unit2)
