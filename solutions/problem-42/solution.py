import math


def istriangle(n):
    """
    Tests if n is a triangle number.
    Input:
        n -- a positive integer
    Output:
        True if n is a triangle number
        or False if n is not a triangle number
    Examples:
        >>> istriangle(55)
        True
        >>> istriangle(7)
        False
    """
    x = (math.sqrt(8 * n + 1) - 1) / 2
    if x - int(x) > 0:  # if x is not an integer
        return False
    return True


def iswordtriangle(word):
    """
    Tests if a word value is a triangle number.
    Input:
        word -- a string
    Output:
        True if word value is a triangle number
        or False if word value is not a triangle number
    Examples:
        >>> iswordtriangle("SKY")
        True
        >>> iswordtriangle("G")
        False
    """
    wordvalue = 0
    for char in word.lower():
        wordvalue += ord(char) - 96
    return istriangle(wordvalue)


if __name__ == "__main__":
    print(iswordtriangle("SKY"))
    print(iswordtriangle("G"))
    print(istriangle(55))
