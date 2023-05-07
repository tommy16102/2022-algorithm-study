def to2(number):
    return format(number, 'b')

def toTree(s,i,tree):
    mid = int((len(s))/2)
    tree[i] = s[mid]
    if len(s) > 3:
        toTree(s[:mid],i*2,tree)
        toTree(s[mid+1:],i*2+1,tree)
    elif len(s) == 3:
        tree[i*2] = s[mid-1]
        tree[i*2+1] = s[mid+1]
    
def getTreeSize(l):
    size = 2
    while 1:
        if l > size-1:
            size *= 2
        else:
            break
    return size-1

def checkTree(tree,i):
    n = len(tree)
    left = i*2
    right = i*2+1
    has_child = 0
    
    if left <= n and right <= n: 
        has_child = 1
    
    if has_child:
        if tree[i] == '0':
            if tree[left] == '1' or tree[right] == '1':
                return False
            else:
                return checkTree(tree,left) and checkTree(tree,right)
        else:
            return checkTree(tree,left) and checkTree(tree,right)
    else:
        return True
    
def solution(numbers):
    answer = []
    
    for e in numbers:
        e = to2(e)
        size = getTreeSize(len(e))
        e = '0' * (size-len(e)) + e

        tree = [0] * (size+1)
        toTree(e,1,tree)
        if checkTree(tree,1):
            answer.append(1)
        else: answer.append(0)
    
    return answer

