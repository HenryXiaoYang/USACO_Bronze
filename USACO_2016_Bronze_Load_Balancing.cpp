#include <bits/stdc++.h>

using namespace std;

int n, b, cows_x[105], cows_y[105];
vector<int> check_x, check_y;

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    cin>>n>>b;
    int min_cow=b;
    for (int i=1; i<=n; i++) {
        cin>>cows_x[i]>>cows_y[i];
        check_x.push_back(cows_x[i]+1); check_y.push_back(cows_y[i]);
        check_x.push_back(cows_x[i]); check_y.push_back(cows_y[i]-1);
        check_x.push_back(cows_x[i]-1); check_y.push_back(cows_y[i]);
        check_x.push_back(cows_x[i]); check_y.push_back(cows_y[i]+1);
    }

    for (int i=0; i<check_x.size(); i++) {
        int top_left_cnt = 0, top_right_cnt = 0, bottom_left_cnt = 0, bottom_right_cnt = 0, fence_x = check_x[i], fence_y = check_y[i];

        for (int j=1; j<=n; j++) {
            int cow_x = cows_x[j], cow_y = cows_y[j];
            if (cow_x < fence_x && cow_y > fence_y) top_left_cnt++;
            else if (cow_x > fence_x && cow_y > fence_y) top_right_cnt++;
            else if (cow_x > fence_x && cow_y < fence_y) bottom_right_cnt++;
            else if (cow_x < fence_x && cow_y < fence_y) bottom_left_cnt++;
        }
        if (top_left_cnt < b && top_right_cnt < b && bottom_left_cnt < b && bottom_right_cnt < b) {
            min_cow = min(min_cow, max({top_left_cnt, top_right_cnt, bottom_left_cnt, bottom_right_cnt}));
        }


    }
    cout<<min_cow;
}