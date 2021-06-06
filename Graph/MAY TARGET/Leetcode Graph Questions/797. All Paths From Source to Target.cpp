
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int nodes = graph.size();
        int src = 0, dest = nodes - 1;
        vector<vector<int>>ans;
        vector<int>path;
        queue<vector<int>>q;
        path.push_back(src);
        q.push(path);
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            int last_val = path.back(); //vector ka first ele from last
            if (last_val == dest)
                ans.push_back(path);
            else
            {
                for (auto ch : graph[last_val])
                {
                    vector<int>temp(path);
                    temp.push_back(ch);
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};

/*
- Can we have multiple components here?
ans: no as src and dest is given for one query only

-Which one to prefer dfs or bfs?
ans: any as it is traversal only

BLUNDAR MISTAKE
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int nodes=graph.size();
        int src=0, dest=nodes-1;
        vector<vector<int>>ans;
        vector<int>path;
        queue<int>q;
        q.push(src);
        path.push_back(src);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();

            if(x==dest)
                ans.push_back(path);
            else
            {
                for(auto ch:graph[x])
                {
                    vector<int>temp(path);
                    //isko karne se vector m 0,1,2 y seq generate hoga
                    temp.push_back(ch);
                    q.push(ch);
                }
            }
        }
        return ans;
    }
};


*/