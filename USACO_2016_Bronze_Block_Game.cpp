/*
 *
 * 时间复杂度：O(NM) M是单词的最大长度
 *
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<int> word_check(string word) {
    vector<int> c(27, 0);
    for (auto l: word) {
        c[l-97]++;
    }
    return c;
}

int n;

vector<vector<string>> word_sets;
vector<int> f1(27, 0), f2(27, 0), al(26, 0);

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    cin>>n;
    for (int i=1; i<=n; i++) {
        string a, b;
        vector<string> tmp;
        cin>>a>>b;
        tmp.push_back(a);
        tmp.push_back(b);
        word_sets.push_back(tmp);
    }

    for (auto set: word_sets) {
        f1 = word_check(set[0]);
        f2 = word_check(set[1]);
        for (int i=0; i<26; i++) {
            al[i] += max(f1[i], f2[i]);
        }
    }

    for (auto i: al) cout<<i<<"\n";

}