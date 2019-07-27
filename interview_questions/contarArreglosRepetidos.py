from itertools import groupby
import collections
def countArrays(v, a):
    d = dict()
    for i in v:
        if not tuple(i) in d:
            d[tuple(i)] = 1
        else:
            d[tuple(i)] += 1
    
    if not tuple(a) in d:
        return None

    return d[tuple(a)]

def countArrays_2(v,a):
    d = { tuple(k): len(list(group)) for k, group in groupby(v)}
    if not tuple(a) in d:
        return None
    return d[tuple(a)]


v = [[0, 1], [0 ,1], [2, 0]] 
a = [0, 1]
vv = [[2, 0],[0, 1], [0 ,1], [2, 0],[2, 0], [3, 0]] 
aa = [2, 0]
bb = [0, 2]

print (countArrays_2(v,a))
print (countArrays_2(vv,aa))
print (countArrays_2(vv,bb))


for k, group in groupby(v):
    print(k)
    print(list(group))

#[len(list(group)) for key, group in groupby(a)]

#d = { (tuple(key), len(list(group))) for key, group in groupby(vv)}
#dd = { (key, tuple(list(group))) for key, group in groupby(v)}