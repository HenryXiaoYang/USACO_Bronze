#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N;
    cin>>T;
    while (T--) {
        cin>>N;
        vector<int> cows(N+1);
        set<int> valid;
        for (int i=1; i<=N; i++) {
            cin>>cows[i];
        }

        for (int i=1; i<=N; i++) {
            if (cows[i] == cows[i+1]) {
                valid.insert(cows[i]);
            }
            if (i <= N-2 && cows[i] == cows[i+2]) {
                valid.insert(cows[i]);
            }
        }

        if (valid.empty()) cout<<"-1\n";
        else {
            vector<int> tmp;
            tmp.assign(valid.begin(), valid.end());
            for (int i=0; i<tmp.size(); ++i) {
                if (i == tmp.size()-1) cout<<tmp[i];
                else cout<<tmp[i]<<" ";
            }
            cout<<"\n";
        }

    }
}