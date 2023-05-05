#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> raw;
map<ll, int> edges;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    // cin edges, put them in map and sort map
    cin >> n;

    for (int i = 0; i < n; i++) {
        int edge = 0;
        cin >> edge;
        raw.push_back(edge);
    }
    
    sort(raw.begin(), raw.end());

    // Initial the map
    // std::map will automatically sort when new item is inserted into it
    for (auto i : raw) {
        edges[i]++;
    }

    int ans = 0;
    // Calculate rectangle
    for (auto i : edges) {
        if (i.second < 2) continue;

        // nCr = n!/(r!(n-r)!)
        // int posibility = factorial(i.second)/(factorial(2)*factorial(i.second - 2));
        // above formula using recursive and this will increase run time a lot. So just use a simple for loop. Sometimes simpler things are faster
        int posibility = 0;
        for (int k = 1; k < i.second; k++) {
            posibility += i.second - k;
        }
        
        for (auto j : edges) {
            if (j == i) continue;

            if (i.first*2 > j.first) {
                ans += posibility * j.second;
            } else {
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
