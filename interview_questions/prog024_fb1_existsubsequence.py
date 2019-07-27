def findSubsequence(v, target):
    sum = 0
    leftIndex = 0 

    for i in range(len(v)):
        sum += v[i]

        if sum < target:
            continue
        elif sum == target:
            return True
        else:
            for j in range(leftIndex, len(v)):
                sum -= v[j]
                if sum == target:
                    return True
                elif sum < target:
                    leftIndex = j + 1
                    break
    return False

v = [1,5,3,1]

target = 6 

print(findSubsequence(v,target))