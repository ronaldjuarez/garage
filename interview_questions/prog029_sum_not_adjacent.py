def findMaxSumNotAdjacent(v):
    incl = v[0]
    excl = 0

    for i in range(1, len(v)):
        incl, excl = excl + v[i], max(incl,excl)

    return max(incl, excl)


v = [1, 90, 100, 25, 1, 90 , 1]
print (findMaxSumNotAdjacent(v))