def longestCommonPrefix(strs) :
    # sort to get shortest first
    strs.sort(key=len)

    # prefix buffer
    prefix = ""

    # each char of shortest string
    index = 0
    for c in strs[0] :
        char = ''
        # compare char index with other strings'
        for i in range(1, len(strs)) :
            if c == strs[i][index] :
                char = c
            else :
                char = ''
                break

        index += 1
        prefix += char

    return prefix if prefix != "" else None