def largest_product_in_a_series(serie, length):
    largest = 0

    for position in range(len(serie)-length+1):
        product = 1
        adjacent = serie[position:position+length]
        for inner in range(length):
            product *= (int(adjacent[inner]))
        if product > largest:
            largest = product

    return largest
