/*
Approach:
1. Inorder traversal (tc:O(n) sc:O(h))

2.
*/

/*
 So the idea is to traverse the tree in Inorder. While traversing, keep track of the count of the nodes visited. If the count becomes k, print the node.
*/
class Solution {
public:
    int cnt = 0;
    int ans = 1;
    void inorder(TreeNode* root, int k)
    {
        if (root == NULL) return;
        inorder(root->left, k);
        cnt++;
        if (cnt == k)
        {
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};

class Solution {
    int solve(TreeNode* root, int &k)
    {
        if (!root)
            return 0;

        int left = solve(root->left, k);
        if (left)
            return left;
        k -= 1;
        if (k == 0)
            return root->val;
        int right = solve(root->right, k);
        return right;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return solve(root, k);
    }
};

/*
iterative approach
class Solution {
public:
    int count=0;
    int ans=1;
    void inorder(TreeNode*root, int k) {
        if(!root) return;
        inorder(root->left , k);
        count++;
        if(count ==k )
        {
            ans = root->val;
            return;
        }
        inorder(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
             inorder(root,k);
             return ans;
    }
};

*/