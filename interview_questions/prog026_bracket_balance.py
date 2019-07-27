d = dict([('(',')'),('[',']'),('{','}')])

def isOpener(c):
    return c in d

def isCloser(c):
    for _, value in d.items():
        if  value == c:
            return True
    return False

def checkBalanceBrackets(s):
    stack = []
    for c in s:
        if isOpener(c):
            stack.append(c)
        elif isCloser(c):
            if len(stack) == 0 or  d[stack.pop()] != c:
                return False
    return len(stack) == 0

#s = '{()[{({})[]()}]}([])'
#s = '{}()[{}]'
#s = '[({})]'
#s = '({[]})'
#s = '[({)}]'
#s = '({[})'
s = '()}[]'

print(checkBalanceBrackets(s))