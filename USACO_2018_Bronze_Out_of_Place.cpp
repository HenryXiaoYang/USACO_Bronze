#include <bits/stdc++.h>

using namespace std;

// return the index of target
int find_target_index(vector<int> cows, int bessie_num, int bessie_index) {
    int min_distance = 0x7f7f7f7f, target_index, distance;
    sort(cows.begin(), cows.end());
    for (int i = 1; i <= cows.size(); i++) {
        if (cows[i] == bessie_num) {
            distance = abs(bessie_index - i);
            if (distance < min_distance) {
                target_index = i;
                min_distance = distance;
            }
        }
    }
    return target_index;
}

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);


    int N, tmp, bessie_num, bessie_index, target_index;
    cin >> N;

    vector<int> original_cow(N + 2);
    original_cow[0] = 0;
    original_cow[N + 1] = 0x7f7f7f7f;

    for (int i = 1; i <= N; i++) {
        cin >> original_cow[i];
    }

    for (int i = 1; i <= N; i++) {
        if (original_cow[i] < original_cow[i - 1] || original_cow[i] > original_cow[i + 1]) {
            if (abs(original_cow[i - 1] - original_cow[i]) > abs(original_cow[i - 1] - original_cow[i + 1])) {
                bessie_num = original_cow[i];
                bessie_index = i;
            } else {
                bessie_num = original_cow[i + 1];
                bessie_index = i + 1;
            }
            break;
        }
    }


    target_index = find_target_index(original_cow, bessie_num, bessie_index);

    set<int> ans;
    if (target_index < bessie_index) {
        for (int i = bessie_index - 1; i >= target_index; i--) {
            ans.insert(original_cow[i]);
            //cout<<i<<" ";
        }

    } else if (target_index > bessie_index) {
        for (int i = bessie_index + 1; i <= target_index; i++) {
            ans.insert(original_cow[i]);
            //cout<<i<<" ";
        }
    } else {
        cout << 0;
        return 0;
    }

    cout << ans.size();


}