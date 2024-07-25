#include <bits/stdc++.h>

using namespace std;

int n, m, min_price=0x7f7f7f7f;

vector<vector<int>> aircon;
vector<int> stalls(105, 0);
set<vector<vector<int>>> possible;

void check(vector<vector<int>> current, vector<int> stalls) {
    int price=0;
    for (auto ac: current) {
        for (int i=ac[0]; i<=ac[1]; i++) {
            stalls[i]-=ac[2];
            stalls[i]=max(0, stalls[i]);
        }
        price+=ac[3];
    }
    if (accumulate(stalls.begin(), stalls.end(), 0)==0) {
        min_price=min(min_price, price);
    }
}


void solve(vector<vector<int>> current, vector<int> visited, int cur_cnt, int max_cnt) {
    if (cur_cnt>=max_cnt) {
        //possible.insert(current);
        check(current, stalls);
        return;
    }
    else {
        for (int i=0; i<m; i++) {
            if (visited[i]==0) {
                visited[i]=1;
                current.push_back(aircon[i]);
                solve(current, visited, cur_cnt+=1, max_cnt);
                visited[i]=0;
                current.pop_back();
                cur_cnt--;
            }
        }
    }
}


int main() {
    int s, t, c, a, b, p, mi;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>s>>t>>c;
        for (int j=s; j<=t; j++) {
            stalls[j]=c;
        }
    }

    for (int i=0; i<m; i++) {
        cin>>a>>b>>p>>mi;
        vector<int> tmp = {a, b, p, mi};
        aircon.push_back(tmp);
    }
    vector<vector<int>> current;
    vector<int> visited(m, 0);

    for (int i=1; i<=m; i++) {
        solve(current, visited, 0, i);
    }



    /*for (auto solution: possible) {
        check(solution, stalls);
    }*/

    cout<<min_price;


}