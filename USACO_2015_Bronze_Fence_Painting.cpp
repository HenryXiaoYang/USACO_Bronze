#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    for (int i=a; i<b; i++) s.insert(i);
    for (int i=c; i<d; i++) s.insert(i);
    cout<<s.size();

}
