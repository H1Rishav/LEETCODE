#include<bits/stdc++.h>
using namespace std;
stack<int>st;
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    
    for(auto it:adj[node])
    {
        if(vis[it])continue;
        dfs(it,adj,vis);

    }
    

    st.push(node);
}
void dfs1(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&curr){
    vis[node]=1;
    curr.push_back(node);
    for(auto it:adj[node])
    {
        if(vis[it])continue;
         dfs1(it,adj,vis,curr);
    }
   

   
}
void solve(){
    int n,m;
    //find out the sccs//join the edges to the sccs
    //perform topo sort 
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<vector<int>>adjr(n);
    vector<int>coins(n);
    for(int i=0;i<n;i++)
    cin>>coins[i];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i])continue;
        dfs(i,adj,vis);
    }

    vis.clear();
    vis.resize(n,0);
    //will only visit all of the edges so no chance of n2 
    vector<vector<int>>ans;
    while(!st.empty()){
        while(!st.empty()&&vis[st.top()])
        st.pop();
        if(st.empty()) break;
        vector<int>curr;
        int nodecurr=st.top();
        dfs1(nodecurr,adjr,vis,curr);
        ans.push_back(curr);
    }
    //will now need to make a graph out of the sccs
    vector<vector<int>>sccs(ans.size());
    map<int,int>mp;
    map<int,long long>siz;
    for(int i=0;i<ans.size();i++){
        long long sum=0LL;
        for(auto it:ans[i])
        {
            mp[it]=i;
            sum+=1LL*coins[it];
        }
        siz[i]=sum;
    }
     vector<int>indeg(ans.size(),0);
    for(int i=0;i<ans.size();i++)
    {
        set<int>st;
        for(auto it:ans[i])
        {
            for(auto it1:adj[it])
            {
                 if(mp[it1]==i)continue;
                st.insert(mp[it1]);
            }
        }
        for(auto sc:st)
        {
            
            sccs[i].push_back(sc);
            indeg[sc]++;
        }
        
    }
    //no we have the size and the scc map of each we will now go with the topo sort approach
    vector<long long>dp(ans.size(),0);
   
    queue<int>q;
    for(int i=0;i<ans.size();i++)
    {
         dp[i]=siz[i];
        if(indeg[i]==0)
        {
            q.push(i);
            dp[i]=siz[i];
        }
    }
    long long masum=0LL;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        masum=max(masum,dp[it]);
        for(auto node:sccs[it])
        {
            indeg[node]--;
            dp[node]=max(dp[node],siz[node]+dp[it]);
            if(indeg[node]==0)
            q.push(node);
            
        }
    }
    cout<<masum<<endl;

}
int main(){

    int t=1;
    //cin>>t;
    while(t--)solve();
}