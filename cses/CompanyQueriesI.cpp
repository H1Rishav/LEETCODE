#include<bits/stdc++.h>
using namespace std;
//solved
const int MAXN=200005;
const int LOG=20;
int up[MAXN][LOG];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    up[1][0]=0;

    for(int i=2;i<=n;i++)
    cin>>up[i][0];

    for(int j=1;j<LOG;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(up[i][j-1])
            up[i][j]=up[up[i][j-1]][j-1];
            else
            up[i][j]=0;
        }
    }

    while(q--){
        int x,k;
        cin>>x>>k;
        for(int j=LOG-1;j>=0;j--)
        {
            if(k&(1<<j))
            {
                x=up[x][j];
            }
            if(x==0)break;
        }
        if(x==0)
        cout<<-1<<"\n";
        else
        cout<<x<<"\n";
    }
}