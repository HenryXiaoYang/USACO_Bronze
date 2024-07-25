#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;
    cin>>n;
    vector<int> nums(n, 0);

    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }
    int being_sorted = 1;
    int back_num;
    for (int i = n-2; i>=0; i--) {
        back_num = nums[i+1];
        if (nums[i]<back_num) {
            being_sorted++;
        }
        else {
            break;
        }
    }
    cout<<n-being_sorted;


}