#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> grid;
int h = 4;
int w = 6;

// move directions
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};

// neighbour queue
queue<int> rq;
queue<int> cq;

// grid to mark visited nodes
vector<vector<bool>> vis(h, vector<bool>(w, false));

int move_count = 0;
int nodes_left_in_layer = 1;
int nodes_in_next_layer = 0;

void get_neighbor(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int rr = r + dr[i];
        int cc = c + dc[i];

        // out of bound
        if (0 > rr || rr >= h || 0 > cc || cc >= w) continue;

        // obstables cannot be go through
        if (grid[rr][cc] == '#') continue;

        // node already visited
        if (vis[rr][cc]) continue;

        rq.push(rr);
        cq.push(cc);
        vis[rr][cc] = true;
        nodes_in_next_layer++;
    }
}

int main() {
    grid = {
        {'#', 'S', '.', '.', '#', '.'},
        {'#', '.', '.', '.', '.', '#'},
        {'.', '.', '#', '.', '#', 'E'},
        {'.', '.', '#', '.', '.', '.'}
    };

    // Start node
    int rs = 0;
    int cs = 1;

    // add start node to queue and mark it as visited
    rq.push(rs);
    cq.push(cs);
    vis[0][1] = true;

    // // flag to check if reaching the end node
    bool reach_end = false;
    
    while (!rq.empty()) {
        // pop the node out of the queue
        int r = rq.front();
        int c = cq.front();
        rq.pop();
        cq.pop();

        // check if this is the end node
        if (grid[r][c] == 'E') {
            reach_end = true;
            break;
        }

        // // Get the neighbour of this node
        get_neighbor(r, c);

        // reduce the num of nodes_left_in_layer
        nodes_left_in_layer--;

        // update nodes_next_in_layer and move_count
        if (nodes_left_in_layer == 0) {
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_count++;
        }
    }

    if (reach_end) return move_count;

    return -1;
}
