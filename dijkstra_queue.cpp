#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 19;

int n, m;
vector<vector<pair<int,int>>> graph;
vector<bool> mark;
vector<int> dist;

void spfa(int s) {
    fill(dist.begin(), dist.end(), INF);
    fill(mark.begin(), mark.end(), false);

    mark[s] = true;
    dist[s] = 0;

    deque<int> S(1, s);

    while (!S.empty()) {
        int u = S.front();
        S.pop_front();
        mark[u] = false;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }

            if (!mark[v]) {
                S.push_back(v);
                mark[v] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);
    mark.assign(n + 1, false);
    dist.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }

    int s, t;
    cin >> s >> t;

    spfa(s);
    return 0;
}
