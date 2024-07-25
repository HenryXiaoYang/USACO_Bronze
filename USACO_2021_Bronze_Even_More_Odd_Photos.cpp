#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, tmp, even_count = 0, odd_count = 0, count=0;
    cin>>N;

    for (int i=0; i<N; i++) {
        cin>>tmp;
        if (tmp%2==1) { // is odd
            odd_count++;
        }
        else {
            even_count++;
        }
    }

    if (even_count>odd_count) {
        cout<<odd_count*2+1;
    }
    else if (odd_count==even_count) {
        cout<<odd_count+even_count;
    }
    else if (odd_count>even_count) {
        bool can_use = false, even_turn = true;
        count = even_count*2;
        odd_count-=even_count;
        if (odd_count%3==1) {
            odd_count-=3;
            can_use = true;
        }
        while (odd_count) {
            if (even_turn) {
                if (odd_count>0) {
                    odd_count-=2;
                    count++;
                }
                even_turn = false;
            }
            else {
                if (can_use) {
                    can_use = false;
                    count++;
                }
                else if (odd_count>0) {
                    odd_count-=1;
                    count++;
                }
                even_turn = true;
            }
        }


        cout<<count;
    }


}