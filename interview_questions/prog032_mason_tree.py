class Node(object):
  def __init__(self, value, children = None, parent = None):
    self.value = value
    self.children = children 
    self.parent = parent 
    
  def findMinPath(Node root):
    if root is None:
      return -1
    
    if root.children is None:
      return root.value 
    else: 
      minPath = 9999999
      for child in self.children:
        minPath = min(minPath, findMindPath(child))
      return root.value + minPath
    
    

'''
Node* root -> root->child(1) ( 100 ) -> root->child(1)->child(1) -> (200)   / coustumer = 300

                                     -> root->child(1)->child(2) -> (50)    / coustumer = 150


struct Node{
  int value;
  vector<Node*> children;
  Node* parent;
}


---> 
'''


