#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<vector<int>> adj;
vector<char> dead;              // nodes already used as a centroid
vector<int> sz, par, cnt;       // subtree sizes, parents, depth counter
ll ans = 0;

// [1] subtree sizes of the current piece, iteratively
vector<int> buildSizes(int root){
    vector<int> order, stk{root};
    par[root] = 0;
    while(!stk.empty()){
        int u = stk.back(); stk.pop_back();
        order.push_back(u);
        for(int v : adj[u])
            if(!dead[v] && v != par[u]){ par[v] = u; stk.push_back(v); }
    }
    for(int u : order) sz[u] = 1;
    for(int i = order.size()-1; i >= 1; i--) sz[par[order[i]]] += sz[order[i]];
    return order;
}

// [2] walk toward the heavy child until nothing exceeds half
int findCentroid(int root){
    int total = sz[root], cur = root;
    while(true){
        int heavy = -1;
        for(int v : adj[cur])
            if(!dead[v] && v != par[cur] && 2*sz[v] > total){ heavy = v; break; }
        if(heavy < 0) return cur;
        cur = heavy;
    }
}

// [3] count length-k paths passing through c
void countThrough(int c){
    vector<int> touched{0}, depth;
    cnt[0] = 1;                                   // c itself is a depth-0 endpoint
    for(int nb : adj[c]){
        if(dead[nb]) continue;
        depth.clear();
        vector<array<int,3>> stk{{nb, c, 1}};     // {node, parent, depth}
        while(!stk.empty()){
            auto [u,p,d] = stk.back(); stk.pop_back();
            if(d > k) continue;                   // too deep to ever pair up
            depth.push_back(d);
            for(int v : adj[u]) if(!dead[v] && v != p) stk.push_back({v,u,d+1});
        }
        for(int d : depth) ans += cnt[k-d];       // QUERY earlier subtrees
        for(int d : depth){ cnt[d]++; touched.push_back(d); }   // then MERGE
    }
    for(int d : touched) cnt[d] = 0;              // reset only what we dirtied
}

// [4] the recursion
void decompose(int root){
    buildSizes(root);
    countThrough(findCentroid(root));
    int c = findCentroid(root);
    dead[c] = 1;
    for(int v : adj[c]) if(!dead[v]) decompose(v);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    adj.assign(n+1, {});
    for(int i=0;i<n-1;i++){ int a,b; cin>>a>>b; adj[a].push_back(b); adj[b].push_back(a); }
    dead.assign(n+1,0); sz.assign(n+1,0); par.assign(n+1,0); cnt.assign(k+1,0);
    decompose(1);
    cout << ans << "\n";
}