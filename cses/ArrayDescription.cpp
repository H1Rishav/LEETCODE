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
int start,endf;
bool dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,vector<int>&par,long long sum){
    vis[node]=1;
    for(auto it:adj[node])
    {
        int secnode=it.first;
        int weight=it.second;
        if(vis[secnode]&&it.first!=par[node]&&sum+weight<0)
        {
            start=secnode;
            endf=node;
            cout<<start<<" "<<endf<<endl;
            return true;
        }
        if(vis[secnode])continue;
        par[secnode]=node;
        if(dfs(secnode,adj,vis,par,sum+weight))
        return true;
    }
    return false;

}
int n,m;
int mo=1e9+7;
long long helper(int ind,int prev,vector<int>&req, vector<vector<int>>&dp){
    if(prev<=0||prev>m)return 0LL;
    if(ind ==n)
    return 1LL;

     int ans=0;
    if(ind==0){
        if(req[ind]==0)
        {
            for(int i=0;i<=m;i++)
            ans=(ans+helper(ind+1,i,req,dp))%mo;
        }
        else{
            ans=(ans+helper(ind+1,req[ind],req,dp))%mo;
        }
        return ans;

    }
    if(dp[ind][prev]!=-1)return dp[ind][prev];
    if(req[ind]!=0)
    {
        int diff=abs(prev-req[ind]);
        if(diff>1)
        return 0;
        ans=(ans+helper(ind+1,req[ind],req,dp))%mo;

    }
    else{
        ans=(ans+helper(ind+1,prev,req,dp))%mo;
        ans=(ans+helper(ind+1,prev-1,req,dp))%mo;
        ans=(ans+helper(ind+1,prev+1,req,dp))%mo;
    }
    return dp[ind][prev]=ans;

}
void solve(){
   
    cin>>n>>m;
   // cout<<n<<m<<q;
   vector<int>req;
   for(int i=0;i<n;i++)
   {
        int a;
        cin>>a;
        //cout<<a;
        req.push_back(a);
   }
   vector<vector<int>>dp(n,vector<int>(m+1,-1));
   cout<<helper(0,1,req,dp);
    
}
  


   
    

// void solve()
// {
//    int n,m;
//    cin>>n>>m;
//    vector<vector<int>>adj(n);
//    for(int i=0;i<m;i++)
//    {
//     int a,b;
//     cin>>a>>b;a--;b--;
//     adj[a].push_back(b);
//     adj[b].push_back(a);
//    }

//    //cycle detection via bfs
//    queue<int>q;
//    vector<int>vis(n,0);
//    q.push(0);
//    vis[0]=1;
//    vector<int>par(n,0);
//    int anotherst=-1;
//    int start=-1;
//    while(!q.empty()){
//     auto it=q.front();
//     q.pop();
    
//     for(auto nodes:adj[it])
//     {
//         if(nodes==par[it])continue;

//         if(vis[nodes]&&nodes!=par[it]) {
//             start=nodes;
//             anotherst=it;
//            break;
//             }
//             vis[nodes]=1;
//             par[nodes]=it;
//         q.push(nodes);
//     }

//    }
//    if(start==-1)
//    {
//     cout<<"IMPOSSIBLE";
//    }
//    else{

//     //need to do dfs
//     set<int>st;
//     st.insert(start);
//     string s="";
//     s+=to_string(start);
//     while(par[start]!=start){
//         s+=to_string(par[start]);
//         st.insert(par[start]);
//         start=par[start];
//     }
//     string s1="";
//     while(true){
//         if(st.find(anotherst)!=st.end())
//         {
//         reverse(s1.begin(),s1.end());
//         s+=s1;
//         s+=s[0];
//         break;
//         }
//         s1+=to_string(anotherst);
//         anotherst=par[anotherst];
//     }
//     cout<<s1<<endl;
//    }
// }
int main()
{
    int t = 1;
    while (t--)
        solve();
}