#include <bits/stdc++.h>

using namespace std;

//最屎山的一集

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int N, sure_count = 0, unsure_count = 0;
    cin>>N;
    vector<int> cows(N);
    vector<bool> checked(N, false);
    for (int i=0; i<N; i++) {
        cin>>cows[i];
    }

    for (int i=N-1; i>=0; i--) {
        //cout<<sure_count<<" "<<sure_count+unsure_count<<"\n";
        if (! checked[i]) {
            if (i==0) { // 第一头牛一定逃走
                sure_count++;
                checked[i] = true;
            }
            else if (cows[i]==0) { // 一定有牛跑了
                sure_count++;
                checked[i] = true;
            }
            else if (i==N-1 && cows[i]==-1) { // 最后一头牛，还未知，无法推断，因此不确定
                unsure_count++;
                checked[i] = true;
            }
            else if (cows[i]==-1) {
                int last_not_neg_1_cow, first_not_neg_1_cow, neg_1_count=0;
                last_not_neg_1_cow = cows[i+1];
                for (int j=i; j>=1; j--) {
                    if (cows[j]==-1) {
                        neg_1_count++;
                        checked[j] = true;
                    }
                    else {
                        first_not_neg_1_cow = cows[j];
                        break;
                    }
                }
                if (last_not_neg_1_cow == neg_1_count) {
                    sure_count++;
                }
                else if (neg_1_count>last_not_neg_1_cow && last_not_neg_1_cow!=0 && last_not_neg_1_cow!=-1) {
                    sure_count++;
                    unsure_count+=neg_1_count-last_not_neg_1_cow;
                }
                else if (neg_1_count+1<last_not_neg_1_cow && first_not_neg_1_cow==0) { // invalid
                    cout<<-1;
                    return 0;
                }
                else if (neg_1_count+1<last_not_neg_1_cow-first_not_neg_1_cow) { // invalid
                    cout<<-1;
                    return 0;
                }
                else if (last_not_neg_1_cow==0 || last_not_neg_1_cow==-1){
                    unsure_count+=neg_1_count;
                }

            }
            else {
                checked[i] = true;
            }
        }

    }
    cout<<sure_count<<" "<<sure_count+unsure_count;
}