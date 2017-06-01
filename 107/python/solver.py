from binarytree import (Node,heap,convert)

class TreeNode(object):
    def __init__(self,x):
        self.val=x
        self.left=None
        self.right=None

# How to limit input to 'binarytree.Node'?
def fromNodetoTreeNode(root):
    if not root:
        return None
    vals=convert(root)
    tNodes=[None for _ in vals]
    tRoot = TreeNode(vals[0])
    tNodes[0]=tRoot
    index=1
    while index < len(tNodes):
        val = vals[index]
        parenttNode=tNodes[int((index+1)/2)-1]
        if  val:
            newtNode = TreeNode(val)
            tNodes[index]=newtNode
            if (index%2):
                parenttNode.left=newtNode
            else:
                parenttNode.right=newtNode
        index+=1

    return tRoot


class Solution(object):
    def levelOrderBotttom(self,root):
        queue = [(root,0)]
        result=[]
        while queue:
            node,level=queue.pop()
            if node:
                if level >= len(result):
                    result.insert(0,[])
                result[-(level+1)].append(node.val)
                queue.insert(0,(node.left,level+1))
                queue.insert(0,(node.right,level+1))
        return result

noderoot=heap(2)
print(noderoot)
tRoot=fromNodetoTreeNode(noderoot)
solver=Solution()
result=solver.levelOrderBotttom(tRoot)
print(result)