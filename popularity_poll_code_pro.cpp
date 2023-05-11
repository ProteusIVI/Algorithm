#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<string,int>> balot;
map<string,int> valid;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char name[20+10];
        cin >> name;
        // cout << "\ntest: " << name;
        auto p = make_pair(name,0);
        balot.push_back(p);
				valid[name] = i;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        char name[20+10];
        int score;
        cin >> name >> score;
        // cout << "\ntest: " << name << " " << score;
        // Using map to find is faster than using std::find
        // auto it = find_if(balot.begin(), balot.end(), [&](const pair<string,int>& c){
        //     return c.first == name;
        // });
        if (!valid.count(name)) continue;
        balot[valid[name]].second += score;
				// cout << "\ntest: " << index << " " << balot[index].second;
    }

    stable_sort(balot.begin(), balot.end(), [](const pair<string,int>& l,const pair<string,int>& r){
        return l.second > r.second;
    });

    for (int i = 0; i < 3; i++) {
        cout << balot[i].first << " " << balot[i].second << "\n";
    }
    return 0;
}
