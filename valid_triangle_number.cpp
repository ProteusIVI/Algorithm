#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> edges = {2, 2, 2, 3, 3, 4};

    sort(edges.begin(), edges.end());
    int n = edges.size(), ans = 0;
    for (int k = 2; k < n; ++k) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (edges[i] + edges[j] > edges[k] 
                && (edges[i] == edges[j] || edges[i] == edges[k] || edges[k] == edges[j])) { // condition to find 
                printf("edges[%d] = %d, edges[%d] = %d \n", i, edges[i], j, edges[j]);
                ans += j - i;
                j -= 1;
            } else {
                i += 1;
            }
        }
    }
    cout << ans << "\n";
    return ans;
}
