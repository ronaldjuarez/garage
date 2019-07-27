def twosum(v,target):
    l = 0
    r = len(v) - 1

    while l < r:
        if v[l] + v[r] == target:
            return True
        elif v[l] + v[r] < target:
            l += 1
        else:
            if v[r] > target:
                r -= 1
        
    return False

target = 8
v = [1,2,3,9]
v = [1,2,4,4]

print (twosum(v,target))
