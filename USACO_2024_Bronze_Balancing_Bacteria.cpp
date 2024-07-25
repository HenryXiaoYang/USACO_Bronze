#include <bits/stdc++.h>

using namespace std;

int N;
int main() {
    cin>>N;
    vector<long long> grasses(N+1);

    for(int i=1; i<=N; i++) {
        cin>>grasses[i];
    }

    long long changesMadeAdd = 0, changesMadeRemove = 0, adjustment = 0;

    for (int i=1; i<=N; i++) {
        grasses[i]+=adjustment;
        if (grasses[i]<0) {
            changesMadeAdd-=grasses[i];
        }
        else{
            changesMadeRemove+=grasses[i];
        }
        adjustment = adjustment + changesMadeAdd - changesMadeRemove - grasses[i];

    }
    cout<<changesMadeAdd+changesMadeRemove;
}