def get_largest_product_in_series(numbers, wide=13):
    max_product = 0
    max_series = numbers[0:wide]
    for i in range(len(numbers) - wide + 1):
        current_series = numbers[i:i+wide]

        # There is no point trying this one if there is a 0 in there
        if '0' in current_series:
            continue

        current_product = 1
        for w in range(wide):
            current_product *= int(current_series[w])

        if current_product > max_product:
            max_product = current_product
            max_series = current_series

    return max_product, max_series
