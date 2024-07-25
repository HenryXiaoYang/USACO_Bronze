/*
 *
 * 时间复杂度：O(N)
 *
 */

#include <bits/stdc++.h>

using namespace std;

class segment {
public:
    string type;
    int a;
    int b;
};

int n;
int final_segment_flow[2] = {0, 0x7f7f7f7f};
int piror_segment_flow[2] = {0, 0x7f7f7f7f};
vector<segment> highway;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    cin>>n;
    for (int i=1; i<=n; i++) {
        segment tmp;
        cin>>tmp.type>>tmp.a>>tmp.b;
        highway.push_back(tmp);

    }

    for (int i=0; i<n; i++) {
        if (highway[i].type == "none") {
            final_segment_flow[0] = max(final_segment_flow[0], highway[i].a);
            final_segment_flow[1] = min(final_segment_flow[1], highway[i].b);
        }
        else if (highway[i].type == "on") {
            final_segment_flow[0]+=highway[i].a;
            final_segment_flow[1]+=highway[i].b;
        }
        else if (highway[i].type == "off") {
            final_segment_flow[0]-=highway[i].b;
            final_segment_flow[1]-=highway[i].a;

            final_segment_flow[0] = max(0, final_segment_flow[0]);
            final_segment_flow[1] = max(0, final_segment_flow[1]);
        }

        int reverse_index = n-i-1;
        //cout<<highway[reverse_index].type<<"|"<<highway[reverse_index].a<<"|"<<highway[reverse_index].b<<"\n";
        if (highway[reverse_index].type == "none") {
            piror_segment_flow[0] = max(piror_segment_flow[0], highway[reverse_index].a);
            piror_segment_flow[1] = min(piror_segment_flow[1], highway[reverse_index].b);
        }
        else if (highway[reverse_index].type == "off") {
            piror_segment_flow[0] += highway[reverse_index].a;
            piror_segment_flow[1] += highway[reverse_index].b;
        }
        else if (highway[reverse_index].type == "on") {
            piror_segment_flow[0]-=highway[reverse_index].b;
            piror_segment_flow[1]-=highway[reverse_index].a;

            piror_segment_flow[0] = max(0, piror_segment_flow[0]);
            piror_segment_flow[1] = max(0, piror_segment_flow[1]);

        }
    }

    cout<<piror_segment_flow[0]<<" "<<piror_segment_flow[1]<<"\n";
    cout<<final_segment_flow[0]<<" "<<final_segment_flow[1];

}