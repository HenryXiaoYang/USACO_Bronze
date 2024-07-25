#include <bits/stdc++.h>

using namespace std;

int x, y;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    cin>>x>>y;
    int moveDistance = 1, direction = 1, maxSim=9*abs(x-y), originalX = x, moveTo, count=0; //direction=1=right direction=-1=left
    while (maxSim--){
        moveTo = originalX + direction*moveDistance;
        //cout<<"----- moveDistance:"<<moveDistance<<"| direction:"<<direction<<"| x:"<<x<<"| moveTo:"<<moveTo<<"-----\n";
        if (moveTo<x) {
            for (int i=x-1; i>=moveTo; i--) {
                //cout<<i<<"\n";
                count++;
                if (i==y) {
                    cout<<count;
                    return 0;
                };
            }
        }
        else {
            for (int i=x+1; i<=moveTo; i++) {
                //cout<<i<<"\n";
                count++;
                if (i==y) {
                    cout<<count;
                    return 0;
                };
            }
        }
        x = moveTo;

        moveDistance<<=1;
        direction*=-1;

    }


}