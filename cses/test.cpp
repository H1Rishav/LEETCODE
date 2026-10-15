#include <bits/stdc++.h>
using namespace std;


// void dfs(int node,int dist,int k,vector<int>&arr,int&ans)
// {
//     if(dist==k)
//     {
//         ans=node;
//         return;
//     }
//     dfs(arr[node],dist+1,k,arr,ans);
// }
bool dfs(int node,int dest,int dist,vector<int>&arr,vector<int>&vis,int&ans){
    //will use backtracking logic
    if(node==dest){
        ans=min(ans,dist);
        return true;
    }
    vis[node]=1;

    int next=arr[node];
    if(vis[next])return false;

    if(dfs(next,dest,dist+1,arr,vis,ans))
    vis[node]=0;

    return true;


}
void solve(){
    // int n,q;
    // cin>>n>>q;
    // vector<int>arr(n);
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];arr[i]--;
    // }
    // //will form arrays
    // vector<int>vis(n,0);
    // for(int i=0;i<n;i++){

    // }
    // while(q--){
    //     int start,k;
    //     cin>>start>>k;
    //     start--;
    //     if(arr[start]==start)
    //     cout<<start+1<<" ";
    //     else{
    //         int ans=-1;
    //         dfs(start,0,k,arr,ans);
    //         cout<<ans+1<<" ";
    //     }
    // }
    int n,q;
    cin>>n>>q;
    vector<vector<int>> up(30+1,vector<int>(n,INT_MAX));
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>up[0][i];
        up[0][i]--;
    }
    for(int i=1;i<=30;i++){
        for(int j=0;j<n;j++){
            if(up[i-1][j]!=INT_MAX)
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    while(q--){
        int start,k;
        cin>>start>>k;
        start--;
        for(int i=0;i<30;i++){
            if(k&(1<<i))
            start=up[i][start];
        }
        cout<<start+1<<"\n";
    }
 
}



int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int t=1;
   while(t--)solve();
}

