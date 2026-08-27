// #include<bits/stdc++.h>
// using namespace std;

// const int MAXN=200005;
// const int LOG=20;
// int up[MAXN][LOG];

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n,q;
//     cin>>n>>q;
//     up[1][0]=0;

//     for(int i=2;i<=n;i++)
//     cin>>up[i][0];

//     for(int j=1;j<LOG;j++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             if(up[i][j-1])
//             up[i][j]=up[up[i][j-1]][j-1];
//             else
//             up[i][j]=0;
//         }
//     }

//     while(q--){
//         int x,k;
//         cin>>x>>k;
//         for(int j=LOG-1;j>=0;j--)
//         {
//             if(k&(1<<j))
//             {
//                 x=up[x][j];
//             }
//             if(x==0)break;
//         }
//         if(x==0)
//         cout<<-1<<"\n";
//         else
//         cout<<x<<"\n";
//     }
// }

#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
vector<vector<int>>dp;

long long func(int h,int n,int type){
    if(h==n)return 1;
    long long ans=0;
    if(dp[h][type]!=-1)
    return dp[h][type];
    if(type==0){
        ans=((4*func(h+1,n,type))%mo+func(h+1,n,!type)%mo)%mo;
    }
    if(type==1){
        ans=((2*func(h+1,n,type))%mo+func(h+1,n,!type)%mo)%mo;
    }
    ans=ans%mo;
    return dp[h][type]=ans;
}

    
    
    
void solve(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n,vector<int>(2,-1));
   cout<< (func(1,n,0)+func(1,n,1))%mo<<endl;
}
int main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}