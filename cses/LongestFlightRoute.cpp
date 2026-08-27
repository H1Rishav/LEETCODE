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

#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
vector<int> dp;
long long func(int node, vector<vector<int>> &adj)
{
    if (node == adj.size() - 1)
    {
        return 1LL;
    }
    if (dp[node] != -1)
        return dp[node];
    long long ans = 0LL;
    for (auto it : adj[node])
    {
        ans = (ans + func(it, adj)) % mo;
    }
    return dp[node] = ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    dp.clear();
    dp.resize(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = INT_MIN;
    }
    dp[0] = 1;
    vector<int> indeg(n, 0);
    vector<int> par(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    if (q.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    par[0] = 0;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int v : adj[f])
        {
            if (dp[f] != INT_MIN && dp[f] + 1 > dp[v])
            {
                dp[v] = dp[f] + 1;
                par[v] = f;
            }

            indeg[v]--;

            if (indeg[v] == 0)
                q.push(v);
        }
    }
    if (dp[n - 1] == INT_MIN)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dp[n - 1] << endl;
        int u = n - 1;
        vector<int> ans;
        while (par[u] != u)
        {
            ans.push_back(u);
            u = par[u];
        }
        reverse(ans.begin(), ans.end());
        cout << 1 << " ";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] + 1 << " ";
        }
    }
}
int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}