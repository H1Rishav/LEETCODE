#include <bits/stdc++.h>
using namespace std;
int findpar(int node,vector<int>&par){
    if(node==par[node])return node;
    return par[node]=findpar(par[node],par);
}
void unionf(int u,int v,vector<int>&size,vector<int>&par){
    int u_par=findpar(u,par);
    int v_par=findpar(v,par);
    if(size[u_par]>size[v_par])
    {
        size[u_par]+=size[v_par];
        par[v_par]=u_par;
    }
    else{
        size[v_par]+=size[u_par];
        par[u_par]=v_par;
    }
}
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    //if(vis[node])return;
    
    vis[node]=1;
    
    for(auto it:adj[node]){
        if(vis[it])continue;
        //cout<< node<<" "<<it<<endl;
        dfs(it,adj,vis);
    }
    

}
void solve()
{
   int n,m;
   cin>>n>>m;
   vector<int>par(n,0),size(n,1);
   vector<vector<int>>adj(n);
   for(int i=0;i<n;i++)
   {
    par[i]=i;
   }
   for(int i=0;i<m;i++)
   {
    int a,b;
    cin>>a>>b;a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   vector<int>vis(n,0);
   int left=-1;
   vector<vector<int>>ans;
   for(int i=0;i<n;i++)
   {
    if(vis[i])continue;
    //cout<<i;
    dfs(i,adj,vis);
   // cout<<endl;
        if(left!=-1)
        ans.push_back({left+1,i+1});
        left=i;
    
    

   }
   cout<<ans.size()<<endl;
   for(auto it:ans)
   {
    cout<<it[0]<<" "<<it[1]<<endl;
   }
}
int main()
{
    int t = 1;
    while (t--)
        solve();
}