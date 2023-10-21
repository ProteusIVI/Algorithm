/*
BFS ON GRAPH

#include <bits/stdc++.h>
using namespace std;

int n, x, y, z;
vector<int> graph;

struct Node {
    int pos;
    int val;
    Node(int _pos, int _val) {
        pos = _pos;
        val = _val;
    }
};

int bfs(int s, int e) {
    // printf("s %d, e %d \n", s, e);

    int res = 0;
    vector<int> visited(n, false);

    queue<Node> q;
    q.push(Node(s-1, 0));
    visited[s-1] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                // printf("graph[%d] %d graph[%d] %d \n", node.pos, graph[node.pos], i, graph[i]);
                if ((graph[node.pos] % graph[i] == 0 || graph[i] % graph[node.pos] == 0)  && (graph[node.pos] + graph[i]) % 2 == 1) {
                    // printf("satisfied i %d \n", i);
                    q.push(Node(i, node.val + 1));
                    visited[i] = true;

                    if (i == e - 1) {
                        res = node.val + 1;
                        // printf("res %d \n", res);
                        return res;
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> x >> y >> z;
    graph.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    // printf("test graph[%d] %d \n", 2, graph[2]);
    int hours = 0;
    hours += bfs(x, y);
    hours += bfs(y, z);

    cout << hours;
    return 0;
}
*/

// BFS ON GRID
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }
        int H = grid.size();
        int W = grid[0].size();
        int answer = 0;
        auto inside = [&](int row, int col) {
            return 0 <= row && row < H && 0 <= col && col < W;
        };
        vector<pair<int,int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
        // vis[H][W]
        vector<vector<bool>> vis(H, vector<bool>(W));
        for(int row = 0; row < H; row++) {
            for(int col = 0; col < W; col++) {
                if(!vis[row][col] && grid[row][col] == '1') {
                    answer++;
                    queue<pair<int,int>> q;
                    q.push({row, col});
                    vis[row][col] = true;
                    while(!q.empty()) {
                        pair<int,int> p = q.front();
                        q.pop();
                        // p.first, p.second
                        for(pair<int,int> dir : directions) {
                            int new_row = p.first + dir.first;
                            int new_col = p.second + dir.second;
                            if(inside(new_row, new_col) && !vis[new_row][new_col] && grid[new_row][new_col] == '1') {
                                q.push({new_row, new_col});
                                vis[new_row][new_col] = true;
                            }
                        }
                    }
                }
            }
        }
        return answer;
    }
};
