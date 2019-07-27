import time

# MERGESORT

# Input

v = [2, 4, 6, 10]
k = 16
#v = [17, 87, 6 ,22, 41]
# End Input


def countSubsets(v,k):
    s = sum(v)
    copy_v = v
    result = 0
    if not v:
        if k == 0:
            return 1
        else:
            return 0

    if s == k:
        return 1
    elif s < k:
        return 0
    else:
        for i in range(len(v)):
            v = copy_v
            m = v.pop(i)
            c = countSubsets(v, k-m)
            result += c
     
    return result


def countSets(arr, total):
    mem = {}
    return countSubsets_dp(arr, total, len(arr) - 1, mem)

def countSubsets_dp(arr, total, i, mem):
    key = (total, i)

    if key in mem:
        return mem[key]
    
    if total == 0:
        return 1
    elif total < 0:
        return 0
    elif i < 0:
        return 0
    elif total < arr[i]:
        result = countSubsets_dp(arr, total, i - 1, mem)
    else:
        a = countSubsets_dp(arr, total - arr[i], i - 1, mem)
        b = countSubsets_dp(arr, total, i-1, mem)
        result =  a + b 
    mem[key] = result
    return result

# your functions here


# End of your functions
        
    

t_start = time.time()
# your runs here

#c = countSubsets(v,k)
c = countSets(v,k)

# end of your runs
t_end = time.time()





t_elapsed =  t_end - t_start



# Print Results Here

print(c)
print ("Elapsed time: ", t_elapsed, " seconds")

# End print Results
