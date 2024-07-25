#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    unordered_map<int, unordered_map<int, bool>> eaten, share_grass;
    int max_sim = 100000, x, y;
    char dir;

    cin >> N;
    vector<int> cow(4, 0), ans(N, 0);
    vector<vector<int>> cows(N, cow);

    for (int i = 0; i < N; i++) {
        vector<int> tmp(4);
        cin >> dir >> x >> y;
        cows[i][0] = dir;
        cows[i][1] = x;
        cows[i][2] = y;
        cows[i][3] = 1;
    }

    while (max_sim--) {
        for (int i = 0; i < N; i++) {

            if (!cows[i][3]) continue; // the cows[i] stopped

            if (eaten[cows[i][1]][cows[i][2]] && !share_grass[cows[i][1]][cows[i][2]]) {
                cows[i][3] = 0; // the cows[i] stops
                continue;
            } else {
                eaten[cows[i][1]][cows[i][2]] = true; // the cows[i] eat
                share_grass[cows[i][1]][cows[i][2]] = true;
                ans[i] += 1;

                if (cows[i][0] == 'N') cows[i][2] += 1;
                else cows[i][1] += 1;

            }
        }

        share_grass.clear();
    }

    for (int i = 0; i < N; i++) {
        if (cows[i][3]) {
            cout << "Infinity\n";
        } else {
            cout << ans[i] << "\n";
        }
    }

}