from collections import deque
def findPath(G,s,d):
    visited = {}
    for key,_ in G.items():
        visited[key] = 0
    
    return dfs(G,s,d,visited)
    

def dfs(G,s,d, visited):
    
    if not (s in G and d in G):
        return False

    if s == d:
        return True

    if s not in visited or visited[s] != 0:
        return False

    found = False
    visited[s] = 1

    for child in G[s]:
        found = found or dfs(G,child, d, visited)

    return found


    

def bfs(G,s,d):

    if not (s in G and d in G):
        return False

    if s == d:
        return True

    q = deque([])

    q.append(s)

    found = False

    while len(q) > 0 and not found:
        n = q.popleft()
        if (n == d):
            found = True
        else:
            for child in G[n]:
                q.append(child)

    return found
    
def find_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if not start in graph:
        return None
    for node in graph[start]:
        if node not in path:
            newpath = find_path(graph, node, end, path)
            if newpath: 
                return newpath
    return None

def find_all_paths(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return [path]
    if not start in graph:
        return []
    
    paths = []
    for node in graph[start]:
        if node not in path:
            newpaths = find_path(graph, node, end, path)
            if not newpaths == None:
                for newpath in newpaths:
                    paths.append(newpath)
                    
    return paths



G = {1: [2,3],
    2:[4],
    3:[6],
    4:[5,7],
    5:[6,8],
    6:[8],
    7:[],
    8:[]}

source = 1
dest = 8

#print(findPath(G,source, dest))
#print(bfs(G,source, dest))
print (find_all_paths(G,1,8))


