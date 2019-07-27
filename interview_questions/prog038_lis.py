def LIS(v):

    if len(v) <= 0:
        return []
    if len(v) == 1:
        return v

    if v[0] < v[1]:
        if len([v[0]] + LIS(v[1:])) > len (LIS(v[1:])):
            return [v[0]] + LIS(v[1:])
    
    return LIS(v[1:])


def LIS2(v):

    lis = [1] * len(v)

    for i in range(1, len(v)):
        for j in range(i):
            if v[i] > v[j]:
                lis[i] = max(lis[j] + 1, lis[i])

    return max(lis)
#  L = 1 + LIS(v[i+1:end])
#  L = LIS(v[i+1:end])
v = [ 10, 22, 9, 33, 21, 50, 41, 60, 80 ] 
# result : 6 and LIS is [10, 22, 33, 50, 60, 80].

print( LIS2(v))