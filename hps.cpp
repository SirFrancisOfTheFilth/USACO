#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int N;
    fin >> N;
    string moves[N];
    for(int i = 0; i < N; i++){
        fin >> moves[i];
    }

    int hPrefix[N], pPrefix[N], sPrefix[N];
    int hSuffix[N], pSuffix[N], sSuffix[N];

    int curH = 0, curP = 0, curS = 0;
    for(int i = 0; i < N; i++){
        if(moves[i] == "H"){
            curH += 1;
        } else if(moves[i] == "P"){
            curP += 1;
        } else if(moves[i] == "S"){
            curS += 1;

        }
        hPrefix[i] = curH;
        pPrefix[i] = curP;
        sPrefix[i] = curS;
    }

    curH = 0;
    curP = 0;
    curS = 0;
    for(int i = N - 1; i >= 0; i--){
        if(moves[i] == "H"){
            curH += 1;
        } else if(moves[i] == "P"){
            curP += 1;
        } else if(moves[i] == "S"){
            curS += 1;
        }
        hSuffix[i] = curH;
        pSuffix[i] = curP;
        sSuffix[i] = curS;
    }

    int maxVal = 0;
    int maxCount = 0;

    for(int i = 0; i < N; i++){
        maxVal = max(hPrefix[i], max(sPrefix[i], pPrefix[i]));
        if(maxVal == hPrefix[i]){  
            maxCount = max(maxCount, maxVal + max(pSuffix[i], sSuffix[i]) );
        } else if(maxVal == sPrefix[i]){
            maxCount = max(maxCount, maxVal + max(hSuffix[i], pSuffix[i]) );
        } else if(maxVal == pPrefix[i]){
            maxCount = max(maxCount, maxVal + max(sSuffix[i], hSuffix[i]) );
        }
    }
    
    fout << maxCount << endl;
    


}