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
    TreeNode* util(vector<int>& a, int l, int h) {
        if (h <= l) return NULL;
        else
        {
            int mid = l + (h - l) / 2;
            TreeNode* temp = new TreeNode(a[mid]);
            temp->left = util(a, l, mid);
            temp->right = util(a, mid + 1, h);
            return temp;
        }
    }
public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return util(nums, 0, nums.size());
    }
};

/*
As bst inorder result into sorted array.
inorder - left root right
so to find the root apply binary search
*/