#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&siz){
    vis[node]=1;
    int val=1;
    //cout<<node;
    for(auto it:adj[node]){
        if(vis[it])continue;
        dfs(it,vis,adj,siz);
        //cout<<it<<" "<<siz[it]<<endl;
        val+=siz[it];
    }
    siz[node]=val;
}
void checkdfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&siz,vector<int>&cet){
    vis[node]=1;
    bool flag=0;
    for(auto it:adj[node])
    {
        if(vis[it])continue;
        checkdfs(it,vis,adj,siz,cet);
        if(siz[it]>adj.size()/2)
        flag=1;
    }
    if(!flag)
    {
        if(adj.size()-siz[node]<=adj.size()/2)
        cet.push_back(node);
    }
}
void solve(){
   int n,k;
   cin>>n;
   vector<vector<int>>adj(n);
   for(int i=0;i<n-1;i++)
   {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   vector<int>vis(n,0),siz(n,0);
   dfs(0,vis,adj,siz);
  
   vector<int>centroids;
   vis.clear();
   vis.resize(n,0);
   checkdfs(0,vis,adj,siz,centroids);
   if(centroids.size()==0)
   cout<<-1;
   else
   cout<<centroids[0]+1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)solve();
}