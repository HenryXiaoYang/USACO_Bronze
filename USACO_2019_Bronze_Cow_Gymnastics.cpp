#include <bits/stdc++.h>

using namespace std;

int k, n;
vector<int> a(25);
vector<pair<int, int>> ans;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] != a[j] && i < j) {
                ans.push_back(make_pair(a[i], a[j]));
            }
        }
    }

    for (int i = 2; i <= k; i++) {
        a.clear();
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            a.push_back(d);
        }
        for (int j = 0; j < ans.size(); j++) {
            int cow_a = ans[0].first, cow_b = ans[0].second, cow_a_index = 0, cow_b_index = 0;
            pair cows = ans[0];
            for (int o = 0; o <= n; o++) {
                if (a[o] == cow_a) {
                    cow_a_index = o;
                } else if (a[o] == cow_b) {
                    cow_b_index = o;
                }
            }
            //cout<<cow_a_index<<" "<<cow_b_index<<"\n";
            ans.erase(ans.begin());
            if (cow_a_index < cow_b_index) {
                ans.push_back(cows);
            } else {
                j--;
            }

        }

    }
    cout << ans.size();
}