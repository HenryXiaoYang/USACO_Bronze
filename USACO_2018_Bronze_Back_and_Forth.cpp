#include <bits/stdc++.h>

using namespace std;

vector<int> barn_a_buckets, barn_b_buckets;
set<vector<int>> cnt;
set<int> milk_cnt;

void count_buckets(vector<int> barn_a_buckets, vector<int> barn_b_buckets, int day, vector<int> current) {
    if (day==3) {
        int barn_b_size = barn_b_buckets.size();
        for (int i=0; i<barn_b_size; i++) {
            int barn_b_use = barn_b_buckets[i];
            current.push_back(barn_b_use);
            cnt.insert(current);
            current.pop_back();
        }

        return;
    }

    else if (day==0 || day==2) { // a->b
        vector<int> barn_a_buckets_backup(barn_a_buckets);
        vector<int> barn_b_buckets_backup(barn_b_buckets);

        int barn_a_size = barn_a_buckets.size();
        for (int i=0; i<barn_a_size; i++) {
            int barn_a_use = barn_a_buckets[i];
            current.push_back(barn_a_use);
            barn_a_buckets.erase(barn_a_buckets.begin()+i);
            barn_b_buckets.push_back(barn_a_use);
            count_buckets(barn_a_buckets, barn_b_buckets, ++day, current);
            barn_a_buckets.clear();
            barn_b_buckets.clear();
            barn_a_buckets.assign(barn_a_buckets_backup.begin(), barn_a_buckets_backup.end());
            barn_b_buckets.assign(barn_b_buckets_backup.begin(), barn_b_buckets_backup.end());
            current.pop_back();
            day-=1;
        }

    }

    else if (day==1) {
        vector<int> barn_a_buckets_backup(barn_a_buckets);
        vector<int> barn_b_buckets_backup(barn_b_buckets);

        int barn_b_size = barn_b_buckets.size();
        for (int i=0; i<barn_b_size; i++) {
            int barn_b_use = barn_b_buckets[i];
            current.push_back(barn_b_use);
            barn_b_buckets.erase(barn_b_buckets.begin()+i);
            barn_a_buckets.push_back(barn_b_use);
            count_buckets(barn_a_buckets, barn_b_buckets, ++day, current);
            barn_a_buckets.clear();
            barn_b_buckets.clear();
            barn_a_buckets.assign(barn_a_buckets_backup.begin(), barn_a_buckets_backup.end());
            barn_b_buckets.assign(barn_b_buckets_backup.begin(), barn_b_buckets_backup.end());
            current.pop_back();
            day-=1;
        }
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    int a_count[105]={0}, b_count[105]={0};

    int tmp;
    for (int i=1; i<=10; i++) {
        cin>>tmp;
        if (a_count[tmp]<4) {
            barn_a_buckets.push_back(tmp);
            a_count[tmp]+=1;
        }
    }

    while(cin>>tmp) {
        if (b_count[tmp]<4) {
            barn_b_buckets.push_back(tmp);
            b_count[tmp]+=1;
        }
    }
    vector<int> current;
    count_buckets(barn_a_buckets, barn_b_buckets, 0, current);
    for (auto buckets: cnt) {
        int a=1000, b=1000;
        a-=buckets[0];b+=buckets[0];
        b-=buckets[1];a+=buckets[1];
        a-=buckets[2];b+=buckets[2];
        b-=buckets[3];a+=buckets[3];
        milk_cnt.insert(a);
        //cout<<buckets[0]<<" "<<buckets[1]<<" "<<buckets[2]<<" "<<buckets[3]<<" "<<a<<"\n";
    }
    cout<<milk_cnt.size();
}