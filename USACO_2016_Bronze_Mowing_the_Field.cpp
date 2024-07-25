#include <bits/stdc++.h>

using namespace std;

int N;

int farm[2000][2000];
const int init_x = 1000, init_y = 1000;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    char direction;
    int fj_x = 1000, fj_y = 1000, distance, moveTo_x, moveTo_y, t = 0, minX = 0x7f7f7f7f;

    cin >> N;
    memset(farm, 0, sizeof(farm));
    farm[init_x][init_y] = false;

    while (N--) {
        cin >> direction >> distance;

        if (direction == 'N') {
            moveTo_y = fj_y + distance;
            for (int i = fj_y + 1; i <= moveTo_y; i++) {
                t++;
                if (farm[fj_x][i] != 0) {
                    minX = min(minX, t - farm[fj_x][i]);
                    //cout << direction << " " << distance << "\n";
                }
                farm[fj_x][i] = t;
            }
            fj_y = moveTo_y;
        } else if (direction == 'E') {
            moveTo_x = fj_x + distance;
            for (int i = fj_x + 1; i <= moveTo_x; i++) {
                t++;
                if (farm[i][fj_y]!=0) {
                    minX = min(minX, t - farm[i][fj_y]);
                    //cout << direction << " " << distance << "\n";
                }
                farm[i][fj_y] = t;
            }
            fj_x = moveTo_x;
        } else if (direction == 'S') {
            moveTo_y = fj_y - distance;
            for (int i = fj_y - 1; i >= moveTo_y; i--) {
                t++;
                if (farm[fj_x][i]!=0) {
                    minX = min(minX, t - farm[fj_x][i]);
                    //cout << direction << " " << distance << "\n";
                }
                farm[fj_x][i] = t;
            }
            fj_y = moveTo_y;
        } else if (direction == 'W') {
            moveTo_x = fj_x - distance;
            for (int i = fj_x - 1; i >= moveTo_x; i--) {
                t++;
                if (farm[i][fj_y]!=0) {
                    minX = min(minX, t - farm[i][fj_y]);
                    //cout << direction << " " << distance << "\n";
                }
                farm[i][fj_y] = t;
            }
            fj_x = moveTo_x;
        }

    }
    if (minX != 0x7f7f7f7f) {
        cout << minX;
    } else {
        cout << -1;
    }

}