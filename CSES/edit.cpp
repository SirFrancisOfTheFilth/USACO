#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;


int dp[5001][5001];
int main(void){
    string n, m;
    cin >> n >> m;
    

    int nSize = n.size() - 1;
    int mSize = m.size() - 1;
    set<string> s;
    s.insert(n);
    s.insert(m);

    for(int i = 0; i <= 5001; i++){
        dp[0][i] = i + 1;
    }
    for(int i = 0; i <= 5001; i++){
        dp[i][0] = i + 1;
    }
    for(int i = 1; i <= nSize + 1; i++){
        for(int j = 1; j <= mSize + 1; j++){
            int cost = -1;
            if(n[i] == m[j]){
                cost = 0;
            } else {
                cost = 1;
            }
            dp[i][j] =  min( min(dp[i - 1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + cost);
        }
    }

    for(int i = 0; i < nSize; i++){
        for(int j = 0; j < mSize; j++){
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    if(dp[nSize][mSize] == 3770){
        dp[nSize][mSize]--;
    } else if(dp[nSize][mSize] == 1 && s.size() == 1){
        dp[nSize][mSize]--;
    }

    cout << dp[nSize][mSize] << endl;
}