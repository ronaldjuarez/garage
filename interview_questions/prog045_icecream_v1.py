def icecream_v1(v, n, target):
    
    if target == 0 and n >= 0:
        return 1
    if n == 0:
        return 0
    if target < 0:
        return 0

    return max(icecream_v1(v,n-1, target), 1 + icecream_v1(v, n-1, target - v[n-1]))

def icecream_v2(v, n, target):
    
    L = [[0] * (target+1) for _ in range(n+1)]

    #for i in range(len(L))

    for i in range(1, n+1):
        for j in range(1, target+1):
            if j < v[i-1]:
                L[i][j] = L[i-1][j]
            else:
                L[i][j] = max(L[i-1][j], 1+ L[i-1][j - v[i-1]])

    for i in range(len(L)):
        print(L[i])

    return L[n][target]
v = [2, 7, 13, 5, 4, 13,5]
target = 13
n = len(v)
    

print(icecream_v2(v,n, target))

'''
how many icecreams at most you can buy with $ 10 given the price of the icecreams
v = [2, 7, 13, 5, 4, 13, ,5]

you can just buy one ice cream per value

'''