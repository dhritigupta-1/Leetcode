class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>indegree(numCourses);
        for(int i=0; i<numCourses; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
                indegree[adj[i][j]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<adj.size(); i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(q.size() > 0)
        {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0; i<adj[temp].size(); i++)
            {
                int n = adj[temp][i];
                indegree[n]--;
                if(indegree[n] == 0)
                    q.push(n);
            }
        }
        if(ans.size() == numCourses)
            return ans;
        return {};
    }
};