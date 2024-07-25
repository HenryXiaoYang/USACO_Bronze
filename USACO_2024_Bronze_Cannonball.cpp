#include <bits/stdc++.h>

using namespace std;

int N, S;

int main() {
    cin>>N>>S;
    vector<pair<short, int>> numberLine(N+1);

    for (int i=1; i<=N; i++) {
        cin>>numberLine[i].first>>numberLine[i].second;
    }

    int currentLoc = S, currentDir = 1, currentPower = 1, targetDestroyed = 0, maxSim=1000000; //currentDir=-1=left currentDir=1=right

    // start sim
    while (currentLoc>0 && currentLoc<=N && maxSim>0) {
        if (numberLine[currentLoc].first==0) { //在跳板上
            currentDir=currentDir*-1;
            currentPower+=numberLine[currentLoc].second;
        }
        else if (numberLine[currentLoc].first==1) { //在目标上
            if (currentPower>=numberLine[currentLoc].second && numberLine[currentLoc].second!=-1) {
                targetDestroyed+=1;
                numberLine[currentLoc].second = -1;
            }
        }

        currentLoc = currentLoc+ (currentPower * currentDir);
        maxSim--;
    }
    cout<<targetDestroyed;
}