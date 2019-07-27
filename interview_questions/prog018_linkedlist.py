class Node(object):
    def __init__(self, data=None,next_node = None):
        self.data = data
        self.next_node = next_node

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next_node

    def set_next(self, new_next):
        self.next_node = new_next

    
class LinkedList(object):
    def __init__(self, head=None):
        self.head = head

    def insert(self,data):
        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node

    def size(self):
        current = self.head
        count = 0
        while current:
            count += 1
            current = current.get_next()
        return count

    def search(self,data):
        current = self.head
        found = False
        while current and not found:
            if current.get_data() == data:
                found = True
            else:
                current = current.get_next()
        
        if current is None:
            raise ValueError('Data not in List')
        return current
        
    def delete(self,data):
        
        current = self.head

        if current.get_data() == data:
            self.head = current.get_next()
        else:    
            previous = current
            current = current.get_next()
            found = False
            while current and not found:
                if current.get_data() == data:
                    found = True
                    previous.set_next(current.get_next())
                else:
                    current = current.get_next()
            
            if current is None:
                raise ValueError('Data not in List')
        
        return current


l = LinkedList()
l.insert(1)
l.insert(2)
l.insert(3)


print (l.search(2).get_data())
l.delete(2)
print (l.size())
print (l.search(3).get_data())