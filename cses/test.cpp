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
   int n;
   cin>>n;
   vector<int>a(n);
   set<int>st;
    vector<int>dp(1e6+1,0);
   for(int i=0;i<n;i++){
    cin>>a[i];
    dp[a[i]]=1;
    st.insert(a[i]);
   }
  
   for(int i=1e6;i>=1;i--)
   {
     long long prod=i;
     int multf=2;
     while(true){
        if(multf*prod>1e6) break;
        if(st.find(multf*prod)==st.end()) break;
        dp[prod]=max(dp[prod],dp[multf*prod]+1);
        multf++;
     }
   }
   int maxsize=1;
   for(int i=1;i<=1e6;i++)maxsize=max(maxsize,dp[i]);
   cout<<maxsize;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)solve();
}