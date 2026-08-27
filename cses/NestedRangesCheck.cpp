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
   int n;
   cin>>n;
   vector<vector<int>>arr;
   map<vector<int>,int>mp;
   for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    arr.push_back({a,b});
    mp[{a,b}]=i;
    
   }

   sort(arr.begin(),arr.end(),[](vector<int>&a,vector<int>&b){
    if(a[0]!=b[0]) return a[0]<b[0];
    return a[1]>b[1];
   });

   vector<int>ma(n),mi(n);
   ma[0]=arr[0][1];
   for(int i=1;i<n;i++)
   {
    ma[i]=max(ma[i-1],arr[i][1]);
   }
   mi[n-1]=arr[n-1][1];
   for(int i=n-2;i>=0;i--)
   mi[i]=min(mi[i+1],arr[i][1]);

   vector<int>contains(n,0),contained(n,0);
   for(int i=n-2;i>=0;i--)
   {
    if(mi[i+1]<=arr[i][1])
    contains[i]=1;
   }
   vector<int>contains1(n,0),contained1(n,0);
   for(int i=0;i<n;i++)
   {
    int ind=mp[arr[i]];
    contains1[ind]=contains[i];
    contained1[ind]=contained[i];
   }

   for(int i=0;i<n;i++)cout<<contains1[i]<<" ";
   cout<<endl;
   for(int i=1;i<n;i++)
   {
    if(ma[i-1]>=arr[i][1])
    contained[i]=1;
   }
   for(int i=0;i<n;i++)
   {
    int ind=mp[arr[i]];
    
    contained1[ind]=contained[i];
   }
   for(int i=0;i<n;i++)cout<<contained1[i]<<" ";
   cout<<endl;


}
int main()
{
    int t = 1;
    while (t--)
        solve();
}