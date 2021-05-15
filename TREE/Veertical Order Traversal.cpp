/*
In this question vertical order k sath horizontal i.e level order traversal ka bhi dhyan rkhna
hai islye pair ya fir set use karna padega map k andar.

https://www.youtube.com/watch?v=kqHNP6NTzME
*/


//MAP K ANDAR VECTOR WITH PAIR
class Solution {
public:
    void dfs(TreeNode* root, int dist, int level, map<int, vector<pair<int, int>>> &m) {
        if (!root)return;
        m[dist].push_back(make_pair(level, root->val));
        dfs(root->left, dist - 1, level + 1, m);
        dfs(root->right, dist + 1, level + 1, m);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        vector<vector<int>> ans;

        dfs(root, 0, 0, m);
        for (auto it : m) {
            sort(it.second.begin(), it.second.end());
            vector<int> tmp;
            for (auto i : it.second)tmp.push_back(i.second);
            ans.push_back(tmp);
        }
        return ans;
    }
};

//MAP K ANDAR multiSET PAIR
class Solution {
public:
    void vertical_traversal(TreeNode *root, int hd, int level, map<int, multiset<pair<int, int>>>&mp)   {
        if (root == NULL) return;
        mp[hd].insert({level, root->val});
        vertical_traversal(root->left, hd - 1, level + 1, mp);
        vertical_traversal(root->right, hd + 1, level + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //pair(level, node->val)
        map<int, multiset<pair<int, int>>> mp;
        vertical_traversal(root, 0, 0, mp);

        vector<vector<int>> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> temp;
            for (auto i : it->second) {
                temp.push_back(i.second);
            }
            res.push_back(temp);
        }
        return res;

    }
};

/*
ERROR IN THIS SOLN AS
Input:
[0,2,1,3,null,null,null,4,5,null,7,6,null,10,8,11,9]
Output:
[[4,10,11],[3,7,6],[2,5,8,9],[0],[1]]
Expected:
[[4,10,11],[3,6,7],[2,5,8,9],[0],[1]]

SO TO MAINTAIN ORDER WE HAVE TO USE SET
vector<vector<int>>ans;
void util(TreeNode* root,int h,map<int,vector<int>>&mp)
{
    if(root==NULL) return;
    mp[h].push_back(root->val);
    util(root->left,h-1,mp);
    util(root->right,h+1,mp);

}
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    if(root==NULL) return{};
    map<int,vector<int>>mp;
    util(root,0,mp);
   vector<vector<int>> res;
        for(auto it:mp){
            vector<int> temp;
            for(auto i:it.second){
                temp.push_back(i);
            }
            res.push_back(temp);
        }
        return res;

}
*/

//MAP K ANDAR MULTISET PAIR
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int, multiset<pair<int, int>>> mp; // [x][y, val]
        traverse(root, 0, 0, mp);
        vector<vector<int>> res;
        for (auto& [x, st] : mp)
        {
            res.push_back({});
            for (auto& [y, val] : st) res.back().push_back(val);
        }
        return res;
    }

protected:
    void traverse(TreeNode* node, int x, int y,  map<int, multiset<pair<int, int>>>& mp)
    {
        if (!node) return;
        mp[x].insert({y, node->val});
        traverse(node->left, x - 1, y + 1, mp);
        traverse(node->right, x + 1, y + 1, mp);
    }
};

//galat soln hain
// Input
// [3,1,4,0,2,2]
// Output
// [[0],[1],[3,2],[4]]
// Expected
// [[0],[1],[3,2,2],[4]]
//ITERATIVE APPROACH
//USING QUEUE WITH PAIR AND MAP WITH VECTOR
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<int> > m;  // when iterate map, key is already the order of x-axis
    queue<pair<int, TreeNode*> > q; // for level traversal
    q.push(make_pair(0, root));  // root default x-axis is 0
    while (!q.empty()) {
        multiset<pair<int, int> > tmp;  // k: x-axis, v:val Already solved the case when the position is ths same
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto p = q.front(); q.pop();
            tmp.insert(make_pair(p.first, p.second->val));
            if (p.second->left) q.push(make_pair(p.first - 1, p.second->left));
            if (p.second->right) q.push(make_pair(p.first + 1, p.second->right));
        }

        for (auto p : tmp) m[p.first].push_back(p.second);
    }

    vector<vector<int> > res;
    for (auto kv : m) res.push_back(kv.second);
    return res;
}


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        TreeNode *curr;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<vector<int>> ans;
        map<int, vector<int>> mymap;

        //BFS
        while (!q.empty())
        {
            int size = q.size();
            map<int, multiset<int>> mapset;//not set as duplicate bhi handle karne h

            while (size--)
            {
                curr = q.front().first;
                int col = q.front().second;
                q.pop();
                mapset[col].insert(curr->val);

                if (curr->left)
                    q.push({curr->left, col - 1});
                if (curr->right)
                    q.push({curr->right, col + 1});
            }
            for (auto it : mapset)
                for (auto it2 : it.second)
                    mymap[it.first].push_back(it2);
        }
        //Now pass all values from mymap to ans array
        for (auto it : mymap)
            ans.push_back(it.second);

        return ans;
    }
};


















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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int> > m;  // when iterate map, key is already the order of x-axis
        queue<pair<int, TreeNode*> > q; // for level traversal
        q.push(make_pair(0, root));  // root default x-axis is 0
        while (!q.empty()) {
            multiset<pair<int, int> > tmp;  // k: x-axis, v:val Already solved the case when the position is ths same
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                auto p = q.front(); q.pop();
                tmp.insert(make_pair(p.first, p.second->val));
                if (p.second->left) q.push(make_pair(p.first - 1, p.second->left));
                if (p.second->right) q.push(make_pair(p.first + 1, p.second->right));
            }

            for (auto p : tmp) m[p.first].push_back(p.second);
        }

        vector<vector<int> > res;
        for (auto kv : m) res.push_back(kv.second);
        return res;
    }
};





/*


class Solution {
public:
    void vertical_traversal(TreeNode *root, int hd, int level, map<int, multiset<pair<int, int>>>&mp)   {
        if (root == NULL) return;
        mp[hd].insert({level, root->val});
        vertical_traversal(root->left, hd - 1, level + 1, mp);
        vertical_traversal(root->right, hd + 1, level + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //pair(level, node->val)
        map<int, multiset<pair<int, int>>> mp;
        vertical_traversal(root, 0, 0, mp);

        vector<vector<int>> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> temp;
            for (auto i : it->second) {
                temp.push_back(i.second);
            }
            res.push_back(temp);
        }
        return res;

    }
};


class Solution {
public:
    void dfs(TreeNode* root, int dist, int level, map<int, vector<pair<int, int>>> &m) {
        if (!root)return;
        m[dist].push_back(make_pair(level, root->val));
        dfs(root->left, dist - 1, level + 1, m);
        dfs(root->right, dist + 1, level + 1, m);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        vector<vector<int>> ans;

        dfs(root, 0, 0, m);
        for (auto it : m) {
            sort(it.second.begin(), it.second.end());
            vector<int> tmp;
            for (auto i : it.second)tmp.push_back(i.second);
            ans.push_back(tmp);
        }
        return ans;
    }
};
class Solution {
    map<int,map<int,multiset<int>>> mymap;
    void solve(TreeNode *curr,int col,int row)
    {
        if(!curr)
            return;

        mymap[col][row].insert(curr->val);
        solve(curr->left,col-1,row+1);
        solve(curr->right,col+1,row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);

        vector<vector<int>> ans;
        for(auto m1: mymap)
        {
            ans.push_back(vector<int>());
            for(auto m2: m1.second)
            {
                for(auto m3: m2.second)
                    ans.back().push_back(m3);
            }
        }
        return ans;
    }
};

// */
/*
iterative

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        TreeNode *curr;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        vector<vector<int>> ans;
        map<int,vector<int>> mymap;

        //BFS
        while(!q.empty())
        {
            int size = q.size();
            map<int,multiset<int>> mapset;

            while(size--)
            {
                curr = q.front().first;
                int col = q.front().second;
                q.pop();
                mapset[col].insert(curr->val);

                if(curr->left)
                    q.push({curr->left,col-1});
                if(curr->right)
                    q.push({curr->right,col+1});
            }
            for(auto it: mapset)
                for(auto it2: it.second)
                    mymap[it.first].push_back(it2);
        }
        //Now pass all values from mymap to ans array
        for(auto it: mymap)
            ans.push_back(it.second);

        return ans;
    }
};

shi hai

class Solution {
public:
    void dfs(TreeNode* root, int dist, int level, map<int, vector<pair<int, int>>> &m) {
        if (!root)return;
        m[dist].push_back(make_pair(level, root->val));
        dfs(root->left, dist - 1, level + 1, m);
        dfs(root->right, dist + 1, level + 1, m);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        vector<vector<int>> ans;

        dfs(root, 0, 0, m);
        for (auto it : m) {
            sort(it.second.begin(), it.second.end());
            vector<int> tmp;
            for (auto i : it.second)tmp.push_back(i.second);
            ans.push_back(tmp);
        }
        return ans;
    }
};
*/


