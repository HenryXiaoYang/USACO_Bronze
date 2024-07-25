#include <bits/stdc++.h>

using namespace std;

int n, t;

vector<int> current_cows;
vector<vector<int>> records;

bool cmp(vector<int> a, vector<int> b) {
    return a[0]>b[0];
}

int main() {
    cin>>n>>t;
    for (int i=1; i<=n; i++) {
        char c;
        cin>>c;
        current_cows.push_back(c-48);
    }

    for (int i=1; i<=t; i++) {
        int t, x, y;
        cin>>t>>x>>y;
        records.push_back({t, x, y});
    }

    for (int i=0; i<n; i++) {
        vector<int> trial(n, 0);
        trial[i]=1;

        for (auto r : records) {

        }
    }

}