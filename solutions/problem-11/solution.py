def largest_product_in_a_grid(grid, length):
    x = 0
    y = 0
    largest = 0

    len_x = len(grid)
    len_y = len(grid[0])

    for x in range(len_x):
        for y in range(len_y):
            product = 0
            can_right = False
            can_down = False
            can_right_down = False
            can_left_down = False

            if y < len_y - length + 1:
                can_right = True
            if x < len_x - length + 1:
                can_down = True
            if x < len_x - length + 1 and y < len_y - length + 1:
                can_right_down = True
            if x > length-2 and y < len_y - length + 1:
                can_left_down = True

            if can_right:
                product = grid[x][y] * grid[x][y+1] * grid[x][y+2] * grid[x][y+3]
            if product > largest:
                largest = product
            if can_down:
                product = grid[x][y] * grid[x+1][y] * grid[x+2][y] * grid[x+3][y]
            if product > largest:
                largest = product
            if can_right_down:
                product = grid[x][y] * grid[x+1][y+1] * grid[x+2][y+2] * grid[x+3][y+3]
            if product > largest:
                largest = product
            if can_left_down:
                product = grid[x][y] * grid[x-1][y+1] * grid[x-2][y+2] * grid[x-3][y+3]
            if product > largest:
                largest = product

    return largest
