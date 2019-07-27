def hash_function(x): 
    return x % 10

def insert(table,input,value): 
    hash_code = hash_function(input)
    table[hash_code].append((input,value))

def get(table, input):
    hash_code = hash_function(input)
    for i in table[hash_code]:
        if input in i:
            return i[1]
    return None

hash_table = [[] for i in range(10)] 

insert(hash_table, 14, 'apple')
insert(hash_table, 93, 'banana')
insert(hash_table, 13, 'tangerine' )


print (get(hash_table, 13))

