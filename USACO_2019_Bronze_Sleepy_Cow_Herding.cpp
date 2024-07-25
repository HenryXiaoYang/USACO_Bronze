#include <bits/stdc++.h>

using namespace std;

vector<int> cows(3, 0);

bool is_ajacent(int A, int B, int C) {
    if (B-1==A && B+1==C) return true;
    if (C-1==A && C+1==B) return true;
    if (A-1==B && A+1==C) return true;
    if (C-1==B && C+1==A) return true;
    if (A-1==C && A+1==B) return true;
    if (B-1==C && B+1==A) return true;
    return false;
}

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int A, B, C, max_sim = 1000000000, left_len, right_len, count=0, smallest, middle, largest;
    cin>>A>>B>>C;

    cows[0] = A;
    cows[1] = B;
    cows[2] = C;

    while (not is_ajacent(cows[0], cows[1], cows[2]) && max_sim--) {
        smallest = min(cows[0], min(cows[1], cows[2]));
        largest = max(cows[0], max(cows[1], cows[2]));
        middle = cows[0] + cows[1] + cows[2] - smallest - largest;

        cows[0] = smallest;
        cows[1] = middle;
        cows[2] = largest;

        left_len = cows[1]-cows[0]-1;
        right_len = cows[2]-cows[1]-1;

        if ((left_len < right_len || right_len==0) && left_len!=0) {  // #___#____# //need to move c3 to left
            if (left_len>1) {
                cows[2] = cows[0]+2;
                count++;
            }
            else {
                cows[2] = cows[0]+1;
                count++;
            }
        }


        else { // #____#___# //need move c0 to right
            if (right_len>1) {
                cows[0] = cows[2]-2;
                count++;
            }
            else {
                cows[0] = cows[2]-1;
                count++;
            }
        }
    }

    cout<<count<<"\n";

    cows[0] = A;
    cows[1] = B;
    cows[2] = C;

    smallest = min(cows[0], min(cows[1], cows[2]));
    largest = max(cows[0], max(cows[1], cows[2]));
    middle = cows[0] + cows[1] + cows[2] - smallest - largest;

    cows[0] = smallest;
    cows[1] = middle;
    cows[2] = largest;

    left_len = cows[1]-cows[0]-1;
    right_len = cows[2]-cows[1]-1;
    cout<<max(left_len, right_len);
}