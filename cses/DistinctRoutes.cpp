#include <bits/stdc++.h>
using namespace std;
vector<int> dfs(int ind,vector<vector<int>>&adj,vector<int>&vis,int&n,vector<int>&tempv){
    if(vis[ind]) return {};
    if(adj[ind][1]==n){
        //cout<<ind<<endl;
        vis[ind]=1;
        return {n};   }
    for(int i=0;i<vis.size();i++)
    {
        if(vis[i])continue;
        if(adj[i][0]==adj[ind][1])
        {
            vector<int>x=dfs(i,adj,vis,n,tempv);
            if(!x.empty())
            {
                //if(vis[i]) return {};
                vis[i]=1;
                 x.push_back(adj[i][0]);
                 return x;
            }
        }
    }
    tempv[ind]=0;
    return {};

}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj.push_back({a,b});
    }
    sort(adj.begin(),adj.end());
    vector<int>vis(m,0);
    int count=0;
    vector<vector<int>>ans;
    for(int i=0;i<m;i++)
    {
        if(adj[i][0]!=1)break;
        vector<int>tempv(m,0);
        tempv[i]=1;
        vector<int>temp=dfs(i,adj,vis,n,tempv);
        if(!temp.empty())
        {
            
         
            
            vis[i]=1;
            
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            
            count++;
        }
        
    }
    cout<<count<<endl;
    for(auto&vec:ans)
    {
        cout<<vec.size()+1<<endl;
        cout<<1<<" ";
        for(auto it:vec){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
}
int main() 
{
    int t=1;
    while(t--)solve();
}