class Node(object):
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None
    
    def insert(self, data):
        if self.data: 
            if self.data > data:
                if self.left:
                    self.left.insert(data)
                else:
                    self.left = Node(data)
            elif self.data <= data:
                if self.right:
                    self.right.insert(data)
                else: 
                    self.right = Node(data)
        else:
            self.data = data

    def print(self):
        if self.left:
            self.left.print()
        print(self.data)
        if self.right:
            self.right.print()

t = Node(12)
t.insert(5)
t.insert(25)
t.insert(14)
t.insert(8)

t.print()
