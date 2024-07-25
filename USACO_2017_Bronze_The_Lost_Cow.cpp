/*

 时间复杂度大概在 O(n^2)

 伪代码：
 输入xy
 设置n（要走的步数）为1
 遍历|x-y|*9遍：
    判断向左还说向右走：
    向左走：
        遍历x-n：
            判断是否走到了y，是y直接输出然后结束程序
            走的次数++
        将走向设置为向右
    向右走：
        遍历x+n:
            判断是否走到了y，是y直接输出然后结束程序
            走的次数++
        将走向设置为向左
    n乘2



*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, ox, y, dir=1, n=1, ans=0; //dir=1 go positive  dir=0 go negative
    cin>>x>>y;
    if (x==y) {
        cout<<0;
        return 0;
    }
    ox = x;

    for (int d = 1; d<=abs(ox-y)*9; d++) {
        if (dir) { // 往右边走
            for (int i=x+1; i<=ox+n; i++) {
                //cout<<"+1:"<<i<<"\n";
                if (i==y) {
                    cout<<ans;
                    return 0;
                }
                ans++;
            }
            dir=0;
            x=ox+n;

        }
        else {
            for (int i=x; i>=ox-n; i--) {
                //cout<<"-1:"<<i<<"\n";
                if (i==y) {
                    cout<<ans;
                    return 0;
                }
                ans++;
            }
            dir=1;
            x=ox-n;
        }
        n*=2;
    }
}