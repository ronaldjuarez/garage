from collections import deque

class queue2(object):
    def __init__(self, q = deque([])):
        self.q = q

    def getQueue(self):
        return self.q
    
    def put(self, v):
        self.q.append(v)
    
    def get(self):
        if len(self.q) < 1:
            return None
        else: 
            return self.q.popleft()

q = queue2()
q.put(1)
q.put(5)
print(q.getQueue())
print(q.get())
print(q.getQueue())
print(q.get())
print(q.get())
print(q.getQueue())