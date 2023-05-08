// Only pass 7/10 test case

#include <bits/stdc++.h>

using namespace std;

int w, h, n, s, f;
vector<vector<char>> raw;
vector<vector<int>> matrix(9, vector<int>(9));
vector<pair<int,int>> shrines(9);

void bfs(int r, int c) {
    int distance = 0;
    int count = 0;
    int nodes_in_next_layer = 0;
    int nodes_left_in_layer = 1;

    vector<vector<bool>> vis(h, vector<bool>(w, false));
    auto inside = [](int x, int y) { return 0 <= x && x < h && 0 <= y && y < w; };
    vector<pair<int,int>> directions{{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

    queue<pair<int,int>> q;
    q.push({r, c});
    // printf("raw[%d][%d] = ", r, c);
    char node = raw[r][c];
    // cout << "node = "<< node;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        // check distance
        char next_node = raw[p.first][p.second];
        if (next_node > '0' && next_node <= '9') { 
            // cout << " next_node = " << next_node << " distance = " << distance << "\n";
            matrix[node - '0'][next_node - '0'] = distance;
            count++;
        }

        if (count > n) return;

        for (auto dir : directions) {
            int rr = p.first + dir.first;
            int cc = p.second + dir.second;

            // out of bound
            if (!inside(rr, cc)) continue;
            // already visited
            if (vis[rr][cc]) continue;
            // it's an obstacle
            if (raw[rr][cc] == '#') continue;

            q.push({rr,cc});
            vis[rr][cc] = true;
            nodes_in_next_layer++;
        }

        nodes_left_in_layer--;

        if (nodes_left_in_layer == 0) {
            distance++;
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
        }
    }
}

int main() {
    cin >> h >> w >> n >> s >> f;

    for (int i = 0; i < h; i ++) {
        vector<char> row;
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == '1') shrines[0] = {i,j};
            else if (c == '2') shrines[1] = {i,j};
            else if (c == '3') shrines[2] = {i,j};
            else if (c == '4') shrines[3] = {i,j};
            else if (c == '5') shrines[4] = {i,j};
            else if (c == '6') shrines[5] = {i,j};
            else if (c == '7') shrines[6] = {i,j};
            else if (c == '8') shrines[7] = {i,j};
            else if (c == '9') shrines[8] = {i,j};
            row.push_back(c);
        }
        raw.push_back(row);
    }

    h = 4;
    w = 6;
    n = 3;
    s = 1;
    f = 2;

    raw = {{'#','1','.','.','#','.'},
           {'#','.','.','.','2','#'}, 
           {'.','.','#','.','#','.'}, 
           {'3','.','#','.','.','.'}};

    shrines[0] = {0,1};
    shrines[1] = {1,4};
    shrines[2] = {3,0};
    // shrines[3] = {2,5};

    for (int i = 0; i < n; i++) {
        pair<int,int> shrine = shrines[i];
        bfs(shrine.first, shrine.second);
    }

    
    vector<int> list;
    for (int i = 0; i < n; i++) {
        if (i + 1 == s || i + 1 == f) continue;
        list.push_back(i+1);
    }
    list.insert(list.begin(), s);
    list.push_back(f);

    set<int> posibility;
    do {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int from = list[i];
            int to = list[i+1];
            // printf("from %d to %d take %d \n", from, to, matrix[from][to]);
            sum += matrix[from][to];
        }
        posibility.insert(sum);
    } while (next_permutation(list.begin() + 1, list.end() - 1));

    cout << *posibility.begin();

    return 0;
}
