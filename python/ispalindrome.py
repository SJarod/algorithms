def isPalindrome(n) :
    # negative numbers are not palindromes
    if n < 0 :
        return False
    # single digit numbers are palindromes
    if n < 10 :
        return True

    # get first digit and digit count
    digitNum = 1
    firstDigit = n
    while firstDigit > 10 :
        firstDigit = int(firstDigit / 10)
        digitNum += 1

    # get last digit
    lastDigit = n % 10

    if firstDigit == lastDigit :
        a = n % pow(10, digitNum - 1)
        a = int(a / 10)
        return True if a == 0 else isPalindrome(a)
    else :
        return False