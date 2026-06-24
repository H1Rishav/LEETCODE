class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // WILL BE USING DIJKSTRAS ALGORITHM -SIMILARISH APPROACH
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        // now the dijkstras algorithm
        vector<vector<long long>> dis(n, vector<long long>(k + 1, LLONG_MAX));
        priority_queue<vector<long long>, vector<vector<long long>>,
                       greater<vector<long long>>>
            pq;
        pq.push({0LL, 0, 1});
        // distance,node,count
        dis[0][1] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long d = it[0];
            int no = it[1];
            int c = it[2];

            if (no == n - 1)
                return d;

            // if (dis[no][c] < d)
            //     continue;     this is redundant as we already checked it before

            for (auto nodes : adj[no]) {
                int next = nodes.first;
                long long weight = nodes.second;
                int newcnt = c;
                // wo we have the next node and the weight to be added
                if (labels[no] == labels[next])
                    newcnt++;
                else
                    newcnt = 1;

                if (newcnt > k)
                    continue;

                long long nd = d + weight;

                if (nd < dis[next][newcnt]) {
                    dis[next][newcnt] = nd;
                    pq.push({nd, next, newcnt});
                }
            }
        }
        long long mini = 1e15;
        for (auto it : dis[n - 1]) {
            mini = min(mini, it);
        }
        if (mini >= 1e15)
            return -1;
        return mini;
    }
};