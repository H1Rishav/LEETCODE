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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    vector<vector<int>>g(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;a--;b--;
        
        adj.push_back({a,b,c});
        g[a].push_back(b);
        // adj[b].push_back({a,c});
    }
    sort(adj.begin(),adj.end());
    vector<long long>dist(n,LLONG_MIN);
    dist[0]=0LL;
    for(int j=0;j<n-1;j++)
    {
       
        for(int i=0;i<adj.size();i++){
            //now we relax the edges
            if(dist[adj[i][0]]!=LLONG_MIN&&dist[adj[i][1]]<dist[adj[i][0]]+adj[i][2])
            dist[adj[i][1]]=dist[adj[i][0]]+adj[i][2];
        }

    }
    // for(int i=0;i<n;i++)
    // cout<<dist[i]<<" ";
    // cout<<endl;
    vector<long long>temp=dist;
    for(int i=0;i<adj.size();i++)
    {
        if(dist[adj[i][1]]<dist[adj[i][0]]+adj[i][2])
            dist[adj[i][1]]=dist[adj[i][0]]+adj[i][2];
    }
    set<int>cq;

    for(int i=0;i<n;i++)
    {
        if(dist[i]!=temp[i]){
            //cout<<i<<" ";
            cq.insert(i);
        }
    }
    //cout<<endl;
    queue<int>q,cyq;
    q.push(0);
    //possibility of a cycle so we use visited array
    vector<int>vis(n,0);
    vis[0]=1;
    vector<int>nvis(n,0);
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        
        if(cq.find(it)!=cq.end()){nvis[it]=1;cyq.push(it);}
        //some cycles maybe be disconnected with 1 like another component
        //could have skipped this step as well just to make
        //sure the bfs is started only from the cycles that actually originate
        //from the starting node
        for(auto node:g[it])
        {
            if(vis[node])continue;
            vis[node]=1;
            q.push(node);
        }

    }
    
    while(!cyq.empty()){
        auto it=cyq.front();
        
        cyq.pop();
        if(it==n-1)
        {
            cout<<-1<<endl;
            return;
        }
        for(auto node:g[it])
        {
            if(nvis[node])continue;
            vis[node]=1;
            cyq.push(node);
        }

    }

    cout<<dist[n-1];

    
    
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