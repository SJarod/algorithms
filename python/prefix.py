def longestPrefix(strs) :
    prefix = ""

    for i in range(1, len(strs)) :
        temp = ""
        for j in range(0, len(strs[i])) :
            if j >= len(strs[0]) :
                break

            c = strs[0][j]
            cc = strs[i][j]
            if c == cc :
                temp += cc
            else :
                break

        if temp != "" :
            prefix += temp
        else :
            break

    return None if prefix == "" else prefix

print(longestPrefix([ "Flower", "Fly", "Flee", "Fl" ])) # Fl
print(longestPrefix([ "FL", "Flower", "Fly", "Flee", "Fl" ])) # F
print(longestPrefix([ "F", "Flower", "Fly", "Flee", "Fl" ])) # F
print(longestPrefix([ "Fyds", "Flower", "Fly", "Flee", "Fl" ])) # F
print(longestPrefix([ "Fs", "Flower", "Fly", "Flee", "Fl" ])) # F
print(longestPrefix([ "Flower", "Fly", "Flee", "Fl", "fkdls" ])) # None
print(longestPrefix([ "Flower", "Fly", "Flee", "Fl", "f" ])) # None
print(longestPrefix([ "Flower", "Fly", "FL", "Flee", "Fl" ])) # F
print(longestPrefix([ "Flower", "Fly", "Fw", "Flee", "Fl" ])) # F
print(longestPrefix([ "Flower", "Fly", "Fdsw", "Flee", "Fl" ])) # F