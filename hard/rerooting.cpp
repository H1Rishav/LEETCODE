#include <bits/stdc++.h>
using namespace std;

//for samsung test from kirang repo

// void solve() {
//    int n;
//    cin>>n;
//    vector<int>a(n);
//    for(int i=0;i<n;i++)cin>>a[i];
//    map<int,vector<int>>mp;
//    for(int i=0;i<n;i++)
//    {
//     if(mp.find(a[i])==mp.end())
//     {
//         mp[a[i]]={i,INT_MIN,1};
//     }
//     else{
//         auto it=mp[a[i]];
//         int last=it[0];
//         int gap=it[1];
//         int freq=it[2];
//         mp[a[i]]={i,max(gap,i-last-1),freq+1};
//     }
//    }
//    for(auto it:mp)
//    {
//      int last=it[0];
//      int gap=it[1];
//      int freq=it[2];
//      mp[a[i]]={last,max(gap,n-last-1,freq)};

//    }
//    vector<int>ans(n,-1);
//    int done=n;
//    for(auto it:mp){
//     int last=it[0];
//     int gap=it[1];
//     int freq=it[2];


//    }


// }

// void solve(){
//    int n,k;
//    cin>>n>>k;
//    vector<int>arr(n);
//    for(int i=0;i<n;i++)
//    cin>>arr[i];
//     int ma=*max_element(arr.begin(),arr.end());
//     int low=ma,high=ma+k;
//     while(low<=high){
//         int mid=(low+high)/2;
//         int poss=0;
//         //if it is possible or not
//         for(int i=0;i<n-1;i++)
//         {
            
//             //go left
//             int j=i+1;
//             int avak=k;
//             avak-=(mid-ma);
//             if(avak<0)continue;
//             int count=1;
//             int diff;
//             while(j<=n-1){
//                 if(j==n-1)
//                 {
//                     if(arr[j]-arr[j-1]-diff>=0){
//                         poss=1;break;
//                     } 
//                 }
//                  diff=mid-arr[j]-count;
//                 if(diff>avak){
//                     poss=0; break;
//                 }
//                 if(arr[j]>=mid-count){
//                     poss=1;
//                     break;
//                 }
//                 avak-=diff;
//                 j++;count++;
//             }
//             if(poss)break;

//             //go right
//         }
//         if(poss)
//         low=mid+1;
//         else 
//         high=mid-1;
//     }
//     cout<<high<<endl;
// }
vector<int>val;
vector<int>child;
vector<int>sumcalc;
vector<vector<int>>adj;
vector<int>ans;
int act;
int precalc(int node,int par)
{
    int sum=val[node];
    for(auto it:adj[node])
    {
        if(it==par)continue;
        sum+=precalc(it,node);
    }
    return child[node]=sum;

}
int presum(int node,int par){
    int sum=0;
    for(auto it:adj[node]){
        if(it==par)continue;
        sum+=presum(it,node)+child[it];
    }
    return sum;
}
void reroot(int node,int par,int prev){
    int calc=prev;
    if(node!=0)
    calc=prev-child[node]+act-child[node];

    ans[node]=calc;

    for(auto it:adj[node]){
        if(it==par) continue;

        reroot(it,node,calc);
    }


}
void solve(){
    int n;
    cin>>n;
    val.clear();
    val.assign(n,0);
    child.clear();
    child.assign(n,0);
    adj.clear();
    adj.assign(n,vector<int>());
    ans.clear();
    ans.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>val[i];
        act+=val[i];}
    //since tree there will be n-1 edges
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //have to reroot
    //child calc sum calc
    precalc(0,-1);
    
   reroot(0,-1,presum(0,-1));
   int mi=INT_MIN;
   for(int i=0;i<n;i++)
   mi=max(mi,ans[i]);
   cout<<mi;




}

int main() {
    int t=1;
    //cin >> t;

    while(t--)
        solve();
}