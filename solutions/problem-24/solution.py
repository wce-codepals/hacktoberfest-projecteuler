def fix_first_half(l, length, factorial, answer, total):
    if len(answer) == 13:
        return answer
    else:
        if factorial[length - 1] > total:
            return fix_first_half(l[1:], length - 1, factorial, answer + l[0], total)
        else:
            return fix_second_half(answer, l, total, factorial, length, "")


def fix_second_half(first_answer, l, total, factorial, length, second_answer):
    if len(l) == 1:
        return first_answer + second_answer + l[0]
    elif total == 0:
        return first_answer + second_answer + str(''.join(reversed(l)))
    else:
        temp = factorial[length - 1]
        if temp == total:
            return fix_second_half(first_answer, l[1:], total,
                                   factorial, length - 1, second_answer + l[0])
            pass
        else:
            count = 0
            while temp <= total:
                temp += factorial[length - 1]
                count += 1
                if temp + factorial[length - 1] > total:
                    break
            total -= temp
            return fix_second_half(first_answer, l[:count] + l[count + 1:], total, factorial,
                                   length - 1, second_answer + l[count])
            pass


if __name__ == '__main__':
    factorial = {
        0: 1,
        1: 1,
        2: 2,
        3: 6,
        4: 24,
        5: 120,
        6: 720,
        7: 5040,
        8: 40320,
        9: 362880,
        10: 3628800,
        11: 39916800,
        12: 479001600,
        13: 6227020800, }
    tc = 1000000
    l = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    length = len(l)
    answer = fix_first_half(l, length, factorial, "", tc)
    print(answer)
