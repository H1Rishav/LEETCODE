#include <bits/stdc++.h>
using namespace std;
int findpar(int node,vector<int>&par){
    if(node==par[node])return node;
    return par[node]=findpar(par[node]);
}
void unionf(int u,int v,vector<int>&size,vector<int>&par){
    int u_par=findpar(u);
    int v_par=findpar(v);
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
    if(vis[node])
    return;

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
   for(int i=0;i<n;i++)
   {
    int a,b;
    cin>>a>>b;a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   vector<int>vis(n,0);
   int left=-1;
   
   for(int i=0;i<n;i++)
   {
    if(vis[i])continue;
    dfs(i,adj,vis);
    if(left !=-1)
    {
        cout<<left<<" "<<i<<endl;
        left=i;
    }
    

   }
}
int main()
{
    int t = 1;
    while (t--)
        solve();
}