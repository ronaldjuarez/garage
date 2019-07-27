import time

# Input
s = 'Mr John Smith    '
t = 13

## FUNCTIONS

def replaceSpaces(s, trueLength):

    l = len(s)
    l_trimmed =  len(s.strip)

    for i in reversed(range(trueLength)):
        print(i)

def urlify(string, length):
    '''function replaces single spaces with %20 and removes trailing spaces'''
    new_index = len(string)
    #string = list(string)
    for i in reversed(range(length)):
        if string[i] == ' ':
            # Replace spaces
            string[new_index - 3:new_index] = '%20'
            new_index -= 3
        else:
            # Move characters
            string[new_index - 1] = string[i]
            new_index -= 1
    #string = ''.join(string)
    return string



## END FUNCTIONS


t_start = time.time()


## Print your experiments here

#c = countPairs_naive(v, k)
c = urlify(list(s), t)

## End of experiments


## Print Results Here

print(c)

## End print Results


t_end = time.time()
t_elapsed =  t_end - t_start
print ("Elapsed time: ", t_elapsed, " seconds")