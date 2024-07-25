#include <bits/stdc++.h>

using namespace std;

bool board[2005][2005] = {false};

int main() {
    int x1, y1, x2, y2, ans=0;

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    for (int i=1; i<=2; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j=x1; j<x2; j++) {
            for (int k=y1; k<y2; k++) {
                board[j+1000][k+1000]= true;
            }
        }
    }

    cin >> x1 >> y1 >> x2 >> y2;
    for (int j=x1; j<x2; j++) {
        for (int k=y1; k<y2; k++) {
            board[j+1000][k+1000]= false;
        }
    }

    for (int i=0; i<=2004; i++) {
        for (int j=0; j<=2004; j++) {
            if (board[i][j]) {
                ans++;
            }
        }
    }

    cout<<ans;

    return 0;
}