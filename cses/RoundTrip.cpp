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
int start=-1,en=-1;
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&par){
    if(start!=-1)return ;
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(start!=-1)return ;
        if(vis[it]&&it!=par[node])
        {
            start=it;
            en=node;
            //cout<<start<<" "<<en<<endl;
            return;
        }
        if(vis[it])continue;
        
        par[it]=node;
        dfs(it,adj,vis,par);
    }

}
void solve(){
       int n,m;
   cin>>n>>m;
   start=-1;en=-1;
   vector<vector<int>>adj(n);
   vector<int>par(n,0);
   for(int i=0;i<m;i++)
   {
    int a,b;
    cin>>a>>b;a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   vector<int>vis(n,0);
   for(int i=0;i<n;i++)
   {
    if(vis[i])continue;
    dfs(i,adj,vis,par);
   }
   
   if(start==-1){
    cout<<"IMPOSSIBLE"<<endl;
    return;
   }
   int count=2;
   string s=to_string(start+1);
   while(en!=start){
    s+=" "+to_string(en+1);
    count++;
    en=par[en];
   }
   s+=" "+to_string(start+1);
   cout<<count<<endl;
   cout<<s<<endl;
   

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