def findIndices(v, target):
  d = {}
  r = []
  for i in range(len(v)):
    if v[i] not in d:
      d[target - v[i]] = i
    elif v[i] in d:
      r.append(d[target-v[i]])
      r.append(i)
      break
   
  return r
  

v = [1 , 3 , 7 , 4, 3 ]   #// (i ,j) -> v[i] + v[j] == target

#v = [-2, 1 , 1, 3, 3 , 4, 7 ]

#v = [3,3]

target = 5

print (findIndices(v, target))