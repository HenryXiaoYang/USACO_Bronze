#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, tmp;

    //freopen("shuffle.in", "r", stdin);
    //freopen("shuffle.out", "w", stdout);

    string str_tmp;
    cin >> N;

    vector<int> shuffles(N);
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        shuffles[i] = tmp;
    }

    vector<string> cows_id(N), ans(N);
    for (int i = 0; i < N; i++) {
        cin >> str_tmp;
        cows_id[i] = str_tmp;
    }

    for (int i = 0; i < N; i++) {
        ans[shuffles[i] - 1] = cows_id[i];
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
