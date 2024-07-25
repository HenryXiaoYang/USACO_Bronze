/*
时间复杂度：O(s*t)

伪代码：
输入s, t
无限循环：
    在s中查找t第一次出现的下表
    找不到：break
    把下表到下表+t长度换成""
输出s
*/



#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
    //freopen("censor.in", "r", stdin);
    //freopen("censor.out", "w", stdout);

    int pos;
    cin>>s>>t;

    while (true) {
        pos = s.find(t);
        if (pos==-1) {
            break;
        }
        s=s.replace(pos, 3, "");

    }
    cout<<s;
}