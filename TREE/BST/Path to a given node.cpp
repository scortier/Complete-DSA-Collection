vector<int>ans;
void util(TreeNode *root, int x, vector<int> temp) {
    if (root == NULL)
        return;

    if (root->val == x) {
        temp.push_back(root->val);
        ans = temp;
        return;
    }

    temp.push_back(root->val);
    util(root->left, x, temp);
    util(root->right, x, temp);
}

vector<int> Solution::solve(TreeNode* root, int x) {
    vector<int> temp;
    util(root, x, temp);
    return ans;
}

---------------------------------------------------------------------- -
bool kya_path_hai(TreeNode* root, vector<int>&ans, int x)
{
    if (!root) return false;

    ans.push_back(root->val);

    if (root->val == x or kya_path_hai(root->left, ans, x) or kya_path_hai(root->right, ans, x))
        return true;

    ans.pop_back();
    return false;

}
vector<int>solve(TreeNode* root, int x)
{
    vector<int>ans;
    kya_path_hai(root, ans, x);
    return ans;
}

----------------------------------------------------------------------------

//for mulitple queries ans using BFS (queue)

vector<int>adj[1e5];
int vis[1e5];
vector<int>path[1e5];

void addEdge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void bfs(int root)
{
    queue<pair<int, int>>q;

    q.push({root, -1});
    vis[root] = 1;
    while (!q.empty())
    {
        pair<int, int>p = q.front();

        q.pop();
        vis[p.first] = 1;

        for (auto child : adj[p.first])
        {
            if (!vis[child])
            {
                q.push({child, p.first});

                // Path from the root to this vertex is
                // the path from root to the parent
                // of this vertex followed by the
                // parent itself
                path[child] = path[p.first];
                path[child].push_back(p.first);
            }
        }
    }
}

// Utility Function to print the
// path from root to given node
void displayPath(int node)
{
    vector<int> ans = path[node];
    for (int k : ans) {
        cout << k << " ";
    }
    cout << node << '\n';
}

// Driver code
int main()
{

    // Number of vertices
    int n = 6;

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(3, 5);

    // Calling modified bfs function
    bfs(0);

    // Display paths from root vertex
    // to the given vertices
    displayPath(2);
    displayPath(4);
    displayPath(5);

    return 0;
}