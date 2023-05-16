// Brute force without any effort to reduce searching space
// Below code will fall into Time Limit Exceed case.
// Just hope that you still get some right test cases

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ul unsigned long

int t = 0, n = 0;
ll d = 0;
ll w[30+2] = {0};

// ul s[1<<N];
// int ans = -1; //Không chọn được số K
// for (i = 0; i < (1<<N); i++){
//     ul sum = 0;
//     for(int j = 0; j < N; j++){
//         if(i&1<<j){ // j được chọn
//             sum += v[j]; //số j được chọn
//         }
//     }
//     if(sum == D){
//         int cnt = __builtin_popcount(i); //lấy ra số bit được set của i = số các số cần chọn
//         if(ans != -1 && ans != cnt){
//             return -2; //Chọn được nhiều số K
//         }
//         ans = cnt;
//     }
// }
// return ans;

int solve() {
    ul s[1<<n];
    int ans = -1; // -1: IMPOSSIBLE

    for (int i = 0; i < (1<<n); ++i) { // generate combination with binary string
        ll sum = 0;
        for (int j = 0; j < n; ++j) { // mask to know which item selected
            if (i&1<<j) {
                sum += w[j];
            }
        }
        if (sum == d) {
            int cnt = __builtin_popcount(i); // take out bit '1', which is selected item
            if (ans != -1 && ans != cnt) {
                return -2; // -2: AMBIGUOUS
            }
            ans = cnt; // found the number of lost items
        }
    }
    return ans;
}

int main() {
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n >> d;

        for (int j = 0; j < n; ++j) {
            cin >> w[j];
        }

        int ans = solve();

        switch (ans) {
        case -2:
            printf("Case #%d: AMBIGIOUS\n", i + 1);
            break;
        case -1:
            printf("Case #%d: IMPOSSIBLE\n", i + 1);
            break;
        default:
            printf("Case #%d: %d\n", i + 1, ans);
            break;
        }
    }
    return 0;
}
