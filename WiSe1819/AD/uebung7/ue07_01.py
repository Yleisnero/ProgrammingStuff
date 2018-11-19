import math


class TreeElement:
    val = 0
    left = None
    right = None

    def __init__(self):
        self.left = None
        self.right = None


class Searchtree:
    root = None
    size = 0

    def insert(self, root, elem):
        if elem.val <= root.val:
            if root.left is None:
                root.left = elem
                self.size += 1
            else:
                self.insert(root.left, elem)
        else:
            if root.right is None:
                root.right = elem
                self.size += 1
            else:
                self.insert(root.right, elem)

    def delete_tree(self):
        while self.root is not None:
            pre = self.root
            self.root = self.root.left
            pre = None

    def print(self, root):
        if root is not None:
            print("(", end="")
            self.print(root.left)
            print("," + str(root.val) + ",", end="")
            self.print(root.right)
            print(")", end="")
        else:
            print("n", end="")

    def insert_object(self, object):
        elem = TreeElement()
        elem.val = object
        elem.left = None
        elem.right = None
        if self.root is None:
            self.root = elem
        else:
            self.insert(self.root, elem)

    def get_height(self):
        return int(math.log2(self.size))

    def delete_object(self, object):
        curr = self.root
        try:
            rest, index = self.contains(object)
        except:
            index = False
        if index:
            for i in range(index):
                if object <= curr.val:
                    curr = curr.left
                else:
                    curr = curr.right
            if curr.right is not None and curr.left is not None and curr.right.left is None:
                help = curr
                while curr.left.left is not None:
                    curr = curr.left
                help.val = curr.left.val
                curr.left = None
                self.size -= 1
            elif curr.right is not None and curr.left is not None:
                help = curr
                curr = curr.right
                try:
                    while curr.left.left is not None:
                        curr = curr.left
                except AttributeError:
                    pass
                help.val = curr.left.val
                curr.left = None
                self.size -= 1
            elif curr.right is not None and curr.left is None:
                rest, index = self.contains(curr.val)
                curr = self.root
                for i in range(index - 1):
                    curr = curr.right
                help = curr
                help = help.right
                new = help.right
                curr.right = None
                curr.right = new
                self.size -= 1
            elif curr.left is not None and curr.right is None:
                help = curr
                while curr.left.left is not None:
                    curr = curr.left
                help.val = curr.left.val
                curr.left = None
                self.size -= 1
            elif curr.right is None and curr.left is None:
                curr = self.root
                for i in range(index - 1):
                    if object <= curr.val:
                        curr = curr.left
                    else:
                        curr = curr.right
                if object <= curr.val:
                    curr.left = None
                    self.size -= 1
                else:
                    curr.right = None
                    self.size -= 1
        elif index == 0:
            self.root = None
            self.size = 0
        else:
            print("Object not in tree!")

    def contains(self, object):
        curr = self.root
        index = 0
        while curr is not None:
            if curr.val == object:
                return True, index
            else:
                if object <= curr.val:
                    curr = curr.left
                    index += 1
                else:
                    curr = curr.right
                    index += 1
        return False


if __name__ == "__main__":
    tree = Searchtree()
    for i in range(20):
        tree.insert_object(i)
    tree.print(tree.root)
    print("Size: " + str(tree.size))
    print(tree.contains(10))
    tree.delete_object(12)
    tree.print(tree.root)
    print("Size: " + str(tree.size))
    tree.delete_tree()
    tree.print(tree.root)
