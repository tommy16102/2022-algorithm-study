import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    tree = {}
    preorder = list(map(int,input().split()))
    inorder = list(map(int,input().split()))
    
    def make_tree(here,_pre,_in):
        if not _pre or not _in: return
        tree[here] = _pre[0]
        idx = _in.index(_pre[0])
        make_tree(here*2,_pre[1:1+idx],_in[:idx])
        make_tree(here*2+1,_pre[1+idx:],_in[idx+1:])
        return 
    make_tree(1,preorder,inorder)
    res = []
    def postorder(here):
        if here*2 in tree:
            postorder(here*2)
        if here*2+1 in tree:
            postorder(here*2+1)
        res.append(tree[here])
    postorder(1)
    print(" ".join(map(str,res)))