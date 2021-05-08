/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> bfs;
        bfs.push(root);

        int total_sum = 0;

        while (!bfs.empty()) {
            TreeNode* curr = bfs.front();
            bfs.pop();

            if (!curr->left && !curr->right)
                total_sum += curr->val;

            if (curr->left)
                bfs.push({curr->left, (curr->val * 10 + curr->left->val)});
            if (curr->right)
                bfs.push({curr->right, (curr->val * 10 + curr->right->val)});
        }

        return total_sum;
    }
};

/*
class Solution {
public:
    // int sum=0;
    int sumNumbers(TreeNode* root,int sum=0) {
        if(root==NULL) return 0;
        sum=sum*10+root->val;
        if(!root->left and !root->right)
            return sum;
        return sumNumbers(root->left,sum)+sumNumbers(root->right,sum);
    }
};
*/