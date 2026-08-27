class Solution {
public:
    vector<int>dis;
    vector<vector<int>>adj;
    vector<int>ans;
    vector<int>child;
    int size;
    int precalc(int node,int parent){
        
        //int sum=0;
        int count=1;
        for(auto it:adj[node])
        {
            if(it!=parent)
            {
               
               
                 count+=precalc(it,node);
            }
        }
        return child[node]=count;
    }
    int presum(int node,int par){
        int sum=0;
        for(auto it:adj[node])
        {
            if(it!=par){
                sum+=presum(it,node)+1*child[it];
            }
        }
        return dis[node]=sum;
    }
    void reroot(int node, int par,int prev){
        int calc=prev;
        if(node!=0)
         calc=prev-child[node]+(adj.size()-child[node]);
        cout<<calc<<" "<<node<<endl;;
        ans[node]=calc;
        for(auto it:adj[node])
        {
            if(it!=par)
            {
                reroot(it,node,calc);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        //precalculatee for the root node then move towards its children
        // adj.resize(n);
        // dis.resize(n);
        adj.clear();dis.clear();ans.clear();child.clear();
        adj.assign(n,{});
        dis.assign(n,{});
        ans.assign(n,0);
        child.assign(n,0);
        size=n;
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        precalc(0,-1);
        presum(0,-1);
        //cout<<dis[0];
        reroot(0,-1,dis[0]);
        
        return ans;
    }
};