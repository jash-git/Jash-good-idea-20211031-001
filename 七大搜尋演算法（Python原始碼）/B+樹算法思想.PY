# -*- coding: UTF-8 -*-
# B树查找

class BTree:  #B树
    def __init__(self,value):
        self.left=None
        self.data=value
        self.right=None

    def insertLeft(self,value):
        self.left=BTree(value)
        return self.left

    def insertRight(self,value):
        self.right=BTree(value)
        return self.right

    def show(self):
        print(self.data)


def inorder(node):  #中序遍历：先左子树，再根节点，再右子树
    if node.data:
        if node.left:
            inorder(node.left)
        node.show()
        if node.right:
            inorder(node.right)


def rinorder(node):  #倒中序遍历
    if node.data:
        if node.right:
            rinorder(node.right)
        node.show()
        if node.left:
            rinorder(node.left)

def insert(node,value):
    if value > node.data:
        if node.right:
            insert(node.right,value)
        else:
            node.insertRight(value)
    else:
        if node.left:
            insert(node.left,value)
        else:
            node.insertLeft(value)


if __name__ == "__main__":

    l=[88,11,2,33,22,4,55,33,221,34]
    Root=BTree(l[0])
    node=Root
    for i in range(1,len(l)):
        insert(Root,l[i])

    print("中序遍历（从小到大排序 ）")
    inorder(Root)
    print("倒中序遍历（从大到小排序）")
    rinorder(Root)

