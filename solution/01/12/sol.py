from typing import Optional, List

from graphviz import Digraph


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:  # noqa
        if not root:
            return False

        targetSum -= root.val

        if not root.left and not root.right:
            return targetSum == 0

        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(root.right, targetSum)


def create_tree(nodes: List[Optional[int]]) -> Optional[TreeNode]:
    if not nodes or nodes[0] is None:
        return None

    root = TreeNode(nodes[0])
    queue = [root]
    i = 1

    while i < len(nodes):
        current = queue.pop(0)
        if i < len(nodes) and nodes[i] is not None:
            current.left = TreeNode(nodes[i])
            queue.append(current.left)
        i += 1
        if i < len(nodes) and nodes[i] is not None:
            current.right = TreeNode(nodes[i])
            queue.append(current.right)
        i += 1

    return root


def add_edges(graph, node, node_id):
    if node.left:
        graph.edge(str(node_id), str(2 * node_id + 1), label=f"L({node.left.val})")
        add_edges(graph, node.left, 2 * node_id + 1)
    if node.right:
        graph.edge(str(node_id), str(2 * node_id + 2), label=f"R({node.right.val})")
        add_edges(graph, node.right, 2 * node_id + 2)


def visualize_tree(root: Optional[TreeNode]) -> Digraph:
    if not root:
        print("Empty tree")
        return None

    graph = Digraph()
    graph.node('0', label=str(root.val))

    add_edges(graph, root, 0)

    return graph


if __name__ == '__main__':
    _roots = [1, 2, 3]

    tree = create_tree(_roots)
    tree_visual = visualize_tree(tree)

    tree_visual.render('binary_tree', view=True)
