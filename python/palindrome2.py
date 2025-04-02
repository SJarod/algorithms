def isPalindrome(n) :
    # negative numbers are not palindromes
    if n < 0 :
        return False
    # single digit numbers are palindromes
    if n < 10 :
        return True

    nn = 0
    count = n
    while count > 0 :
        nn = nn * 10 + count % 10
        count = int(count / 10)

    return nn == n

print(isPalindrome(22))