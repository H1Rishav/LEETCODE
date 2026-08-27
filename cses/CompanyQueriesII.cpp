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
const int LOGN=20;
const int MAXN=200005;

int up[MAXN][LOGN];
int lvl[MAXN];

void dfs(int curr,int dep,vector<vector<int>>&adj)
{
    for(auto it:adj[curr])
    {
        lvl[it]=dep+1;
        dfs(it,dep+1,adj);
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>>adj(n+1);
    up[1][0]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>up[i][0];
        adj[up[i][0]].push_back(i);
    }

    for(int i=1;i<LOGN;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(up[j][i-1])
            up[j][i]=up[up[j][i-1]][i-1];
            else
            up[j][i]=0;
        }
    }
    lvl[1]=0;
    dfs(1,0,adj);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(lvl[a]>lvl[b]) swap(a,b);
        int diff=lvl[b]-lvl[a];
        //will bring b to the level of a
        for(int i=LOGN-1;i>=0;i--)
        {
            if((1<<i)&diff)
            b=up[b][i];
            if(b==0) break;
        }
        if(a==b)
        {
            cout<<a<<endl;

        }
        else{
            for(int j=LOGN-1;j>=0;j--)
            {
                if(up[a][j]!=up[b][j])
                {
                    a=up[a][j];
                    b=up[b][j];
                }
            }
            cout<<up[a][0]<<endl;//as it waits for the last step because we dont want it to eb the same

        }

    }

}
