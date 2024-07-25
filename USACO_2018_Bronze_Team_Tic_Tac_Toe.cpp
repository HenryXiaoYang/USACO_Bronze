#include <bits/stdc++.h>

using namespace std;

string gameboard[3];

int individual_win = 0, team_win = 0;

bool double_win_check_2(char c1, char c2, char a, char b, char c) {
    // aab aba baa
    if (a==b && b!=c) {
        //bba aab
        if (a==c1 && b==c1 && c==c2) return true;
        if (a==c2 && b==c2 && c==c1) return true;
    }
    else if (a==c && a!=b) {
        //aba bab
        if (a==c1 && b==c2 && c==c1) return true;
        if (a==c2 && b==c1 && c==c2) return true;
    }
    else if (b==c && a!=b) {
        // abb baa
        if (a==c1 && b==c2 && c==c2) return true;
        if (a==c2 && b==c1 && c==c1) return true;
    }
    return false;
}

bool double_win_check_1(char c1, char c2) {
    // 横向
    for (int i=0; i<3; i++) {
        if (double_win_check_2(c1, c2, gameboard[i][0], gameboard[i][1], gameboard[i][2])) return true;
        // 竖向
        if (double_win_check_2(c1, c2, gameboard[0][i], gameboard[1][i], gameboard[2][i])) return true;
    }
    // 对角
    if (double_win_check_2(c1, c2, gameboard[0][0], gameboard[1][1], gameboard[2][2])) return true;
    if (double_win_check_2(c1, c2, gameboard[0][2], gameboard[1][1], gameboard[2][0])) return true;

    return false;
}

bool single_win_check(char c) {
    // 横向
    for (int i = 0; i < 3; i++) {
        if (gameboard[i][0]==c && gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2]) return true;
        //竖向
        if (gameboard[0][i]==c && gameboard[0][i] == gameboard[1][i] && gameboard[1][i] == gameboard[2][i]) return true;
    }
    //对角
    if (gameboard[0][0]==c && gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2]) return true;
    if (gameboard[0][2]==c && gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0]) return true;

    return false;
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    for (int i = 0; i < 3; i++) cin >> gameboard[i];

    for (char c='A'; c<='Z'; c++) {
        if (single_win_check(c)) individual_win++;
    }


    cout << individual_win << "\n";

    for (char c1 = 'A'; c1 <= 'Z'; c1++) {
        for (char c2 = c1 + 1; c2 <= 'Z'; c2++) {
            if (double_win_check_1(c1, c2)) team_win++;
        }
    }

    cout << team_win;
}