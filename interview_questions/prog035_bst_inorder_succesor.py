class Node:
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None
        
 
class BST:
    def __init__(self):
        self.root = None
       
    def find_in_order_successor(self, inputNode):
        if inputNode.right is not None:
            p = inputNode.right
            while p.left is not None:
                p = p.left
            return p

        else:
            parent = inputNode.parent
            child = inputNode

            while parent is not None and child == parent.right:
                child = parent
                parent = parent.parent
            return parent
  
  
  #                   20 
  #         9                25
  #    5        12            
  #           11   14  
    def insert(self, key):
        newNode = Node(key)
        if self.root is None: 
            self.root = newNode
        else:
            currentNode = self.root
            while currentNode is not None:
                if key < currentNode.key:
                    if currentNode.left is None:
                        currentNode.left = newNode
                        newNode.parent = currentNode
                        break
                    else:
                        currentNode = currentNode.left
                else:
                    if currentNode.right is None:
                        currentNode.right = newNode
                        newNode.parent = currentNode
                        break
                    else:
                        currentNode = currentNode.right
                        
    def getNodeByKey(self, key):
        currentNode = self.root 
        found = False
        while not found and currentNode is not None:
            if key == currentNode.key:
                found = True 
            elif key < currentNode.key:
                currentNode = currentNode.left
            else:
                currentNode = currentNode.right
                
        if found:
            return currentNode
        return None
      
    def printInOrder(self):
        
        currentNode = self.root
        self.printInOrderRec(currentNode)
        
    def printInOrderRec(self, node):
    
        if node is not None:
            print (node.key)
        else: 
            return
            
        self.printInOrderRec(node.left)
        self.printInOrderRec(node.right)
        
bst = BST()

bst.insert(20)
bst.insert(9)
bst.insert(25)
bst.insert(5)
bst.insert(12)
bst.insert(11)  
bst.insert(14)    

test = bst.getNodeByKey(9)
print(bst.find_in_order_successor(9))
bst.printInOrder()
