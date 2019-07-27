def arrayOfArrayProducts(v):

    r = []
    prod = 1
    for e in v:
        r.append(prod)
        prod *= e
    print (r)
    prod = 1
    for i in reversed(range(0,len(v))):
        #print(i)
        r[i] *= prod
        prod *= v[i]
        print (prod)
    return r

# input = [2,7,3,4]
# [1, 1*2, 1*2*7, 1*2*7*3]
# [7*3*4*1, 3*4*1, 4*1, 1]
# output = [7*3*4, 2*3*4, 2*7*4, 2*7*3]

v = [2,7,3,4]
print (arrayOfArrayProducts(v))