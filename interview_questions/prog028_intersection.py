def findIntersection(v1, v2, v3):
    d = {}

    for i in v1:
        if i not in d:
            d[i] = 1
        
    for i in v2:
        if i in d:
            d[i] = 2

    r = []
    for i in v3:
        if i in d and d[i] == 2:
          r.append(i)

    return r  

def findIntersection2(v1,v2,v3):
    x = y = z = 0
    r = []

    while x < len(v1) and y < len(v2) and z < len(v3):
        if v2[y] < v1[x]:
            y += 1 
        elif v2[y] > v1[x]: 
            x += 1
            continue
        else:
            if v3[z] < v1[x]:
                z += 1
            elif v3[z] > v1[x]:
                x += 1
                continue
            else:
                r.append(v1[x])
                x += 1
                y += 1
                z += 1

    return r            

def findIntersection3(v1,v2,v3):

    x = y = z = 0
    r = []

    while x < len(v1) and y < len(v2) and z < len(v3):
        if v1[x] == v2[y] and v2[y] == v3[z]:
            r.append(v1[x])
        
        if v1[x] < v2[y]:
            x += 1
        elif v2[y] < v3[z]:
            y += 1
        else:
            z += 1

    
    return r

v1 = [2,6,6,9,11,13,17]
v2 = [3,6,6,7,10,13,18]
v3 = [4,5,6,6,9,11,13]

print (findIntersection3(v1,v2,v3))