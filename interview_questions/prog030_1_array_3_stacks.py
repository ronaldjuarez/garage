class ThreeStackOneArray:
    def __init__(self, array = [None] * 9):
        self.array = array
        self.length = len(self.array)

        for i in range(3):
            self.array[(self.length // 3 ) * i] = 0

    def insert(self, a, stack):
        if stack != None and stack < 3:
            l_inf = (self.length//3)* stack
            if l_inf + self.array[l_inf] + 1 < (self.length//3)* (stack+1):
                self.array[l_inf+self.array[l_inf] + 1] = a
                self.array[l_inf] += 1

    def pop(self,stack):
        if stack != None and stack < 3:
            
            l_inf = (self.length//3)*stack
            if self.array[l_inf] > 0:
                result = self.array[l_inf + self.array[l_inf]]
                self.array[l_inf + self.array[l_inf]] = None
                self.array[l_inf] -= 1
                return result
            else:
                return None

    def print(self,stack = None):
            if stack is not None:
                if stack < 3:
                    l_inf = (self.length//3)*stack
                    print( self.array[l_inf + 1: l_inf + self.array[l_inf] + 1])
            else:
                for i in range(3):
                    l_inf = (self.length//3) * i
                    print( self.array[l_inf + 1: l_inf + self.array[l_inf] + 1])

s = ThreeStackOneArray()
s.insert(1,1)
s.insert(2,0)
s.insert(10,2)
s.insert(5,0)
s.insert(4,0)
s.print(0)
print(s.array)
s.pop(0)
s.pop(0)
s.pop(0)
print(s.array)

# stacks = 0, 1, 2

