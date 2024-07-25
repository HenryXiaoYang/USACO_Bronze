#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    if (x3<=x1 && x2<=x4 && y3<=y1 && y2<=y4) {
        cout<<0;
    }
    else if (x3<=x1 && x2<=x4 && y3<=y1 && y1<y4) {
        cout<<(x2-x1) * (y2-y4);
    }
    else if (x3<=x1 && x2<=x4 && y3<y2 && y2<=y4) {
        cout<<(x2-x1)*(y3-y1);
    }
    else if (y3<=y1 && y2<=y4 && x3<=x1 && x1<x4) {
        cout<<(y2-y1)*(x2-x4);
    }
    else if (y3<=y1 && y2<=y4 && x3<x2 && x2<=x4) {
        cout<<(y2-y1)*(x3-x1);
    }
    else {
        cout<<(x2-x1)*(y2-y1);
    }


}