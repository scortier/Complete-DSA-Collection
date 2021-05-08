/*
Approach:

1.Firstly do the general base case check i.e whether root is null or not.
2.Then check whether there is any eft child of root and if exists, then it is leaf or not.
3.If left child exists and its leaf then add it to a sum variable declared privately.
4.Now recursively call the function the function for left and right subtree.
5.Finally return the sum variable.

*/
//recursion
class Solution {
    int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left && root->left->left == NULL && root->left->right == NULL)
            sum += root->left->val;
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};


class Solution {
public:
    int sum;
    void solve (TreeNode* root, bool side) {
        if (!root)
            return ;

        if (!root->left && !root->right && side == true)
            sum += root->val;

        solve(root->left, true);
        solve(root->right, false);

        return;
    }

    int sumOfLeftLeaves(TreeNode* root) {

        solve(root, false);

        return sum;
    }
};


//iterative approach -BFS
//FOR DFS DO WITH STACK
int sumOfLeftLeaves(Node* root)
{
    if (root == NULL)
        return 0;
    // A queue of pairs to do bfs traversal
    // and keep track if the node is a left
    // or right child if boolean value
    // is true then it is a left child.
    queue<pair<Node*, bool> > q;
    q.push({ root, 0 });
    int sum = 0;
    // do bfs traversal
    while (!q.empty()) {
        Node* temp = q.front().first;
        bool is_left_child =
            q.front().second;
        q.pop();
        // if temp is a leaf node and
        // left child of its parent
        if (!temp->left && !temp->right &&
                is_left_child)
            sum = sum + temp->key;
        // if it is not leaf then
        // push its children nodes
        // into queue
        if (temp->left) {
            // boolean value is true
            // here because it is left
            // child of its parent
            q.push({ temp->left, 1 });
        }
        if (temp->right) {
            // boolean value is false
            // here because it is
            // right child of its parent
            q.push({ temp->right, 0 });
        }
    }
    return sum;
}

