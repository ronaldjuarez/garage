def depthBrackets(s):
    if len(s) == 0:
        return 0
    maxCount = 0 
    current_max = 0

    for c in s:
        if c not in ['(', ')']:
            continue
        if c == '(':
            current_max += 1
            maxCount  = max(maxCount, current_max)
        elif c == ')':
            current_max -= 1


        if current_max < 0:
            return -1
    if current_max != 0:
        return -1
    return maxCount

s = '((())((()))'

#s = '{()[{({})[]()}]}([])'
#s = '{}()[{}]'
#s = '[({})]'
#s = '({[]})'
#s = '[({)}]'
#s = '({[})'
#s = '()}[]'

print(depthBrackets(s))