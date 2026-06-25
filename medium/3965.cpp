class Solution {
public:
    long long dfs(int node,vector<int>&b,vector<vector<int>>&adj){
        if(adj[node].size()==0)
            return b[node];
        long long mi=LLONG_MAX,ma=LLONG_MIN;
        for(auto it: adj[node]){
            long long x=dfs(it,b,adj);
            mi=min(mi,x);
            ma=max(ma,x);
        }
        return 2*ma-mi+1LL*b[node];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                
            }

        long long ans=dfs(0,baseTime,adj);
        return ans;
        
    }
};