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
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
   // cout<<n<<m<<q;
   vector<vector<pair<int,long long>>>adj(n);
    vector<vector<long long>>dp(n,vector<long long>(n,1e15));
   for(int i=0;i<n;i++)dp[i][i]=0;
  set<vector<long long>>st;
   for(int i=0;i<m;i++)
   {
        long long a,b,c;
        cin>>a>>b>>c;a--;b--;
       // if(st.find({a,b,c})!=st.end()||st.find({b,a,c})!=st.end()){
           // cout<<"y";continue;}
        //st.insert({a,b,c});
        //st.insert({b,a,c});
        //adj[a].push_back({b,c});
        //adj[b].push_back({a,c});
        dp[a][b]=min(dp[a][b],c);
        dp[b][a]=min(dp[a][b],c);
   }
  
   dp[0][0]=0;
   for(int k=0;k<n;k++)
        {
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    {
        
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        
    }
   }
        }
    
    
    while(q--){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(dp[a][b]==1e15)cout<<-1<<endl;
        else
        cout<<dp[a][b]<<endl;
    }
    
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