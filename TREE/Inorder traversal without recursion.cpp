Method 1: Using one stack and the binary tree node will be changed. Easy , not Practical

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        if (!root)
            return vector;
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *pNode = stack.top();
            if (pNode->left)
            {
                stack.push(pNode->left);
                pNode->left = NULL;
            }
            else
            {
                vector.push_back(pNode->val);
                stack.pop();
                if (pNode->right)
                    stack.push(pNode->right);
            }
        }
        return vector;
    }
};
Method 2: Using one stack and one unordered_map, this will not changed the node. Better

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        if (!root)
            return vector;
        unordered_map<TreeNode *, bool> map;//left child has been visited:true.
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *pNode = stack.top();
            if (pNode->left && !map[pNode])
            {
                stack.push(pNode->left);
                map[pNode] = true;
            }
            else
            {
                vector.push_back(pNode->val);
                stack.pop();
                if (pNode->right)
                    stack.push(pNode->right);
            }
        }
        return vector;
    }
};
Method 3: Using one stack and will not changed the node. Best(at least in this three solutions)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;

        while (!stack.empty() || pCurrent)
        {
            if (pCurrent)
            {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
};
