/*
 * 屎山代码，能跑就行 :|
 */

#include <bits/stdc++.h>

using namespace std;

vector<bool> buckets(1005, false);
set<int> count_buckets;

class cow{
    public:
        int s;
        int t;
        int b;
        vector<int> bucket_used;
};

vector<cow> n_cows;


bool cmp(cow a, cow b) {
    return a.s < b.s;
}

int use_bucket(int j) {
    int i=1, need = n_cows[j].b;
    // i represent bucket number
    while (need>0) {
        if (buckets[i]) {
            i++;
            continue;
        }
        count_buckets.insert(i);
        buckets[i] = true;
        n_cows[j].bucket_used.push_back(i);
        need--;
    }
}

int return_bucket(int j) {
    for (auto i: n_cows[j].bucket_used) {
        buckets[i] = false;
    }
    n_cows[j].bucket_used.clear();
}

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n, s, t ,b;;
    cin>>n;

    for (int i=0; i<n; i++) {
        cow c;
        cin>>s>>t>>b;
        c.s = s;
        c.t = t;
        c.b = b;
        n_cows.push_back(c);
    }

    sort(n_cows.begin(), n_cows.end(), cmp);

    for (int i=n_cows[0].s; i<=n_cows[n-1].t; i++) {
        for (int j=0; j<n_cows.size(); j++) {
            if (n_cows[j].t==i) {
                return_bucket(j);
            }
            if (n_cows[j].s==i) {
                use_bucket(j);
            }
        }

    }

    cout<<count_buckets.size();

}