#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(){
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int N, Q;
    fin >> N >> Q;

    int cows[N];
    pii queries[Q];
    for(int i = 0; i < N; i++){
        fin >> cows[i];
    }
    for(int i = 0; i < Q; i++){
        fin >> queries[i].first >> queries[i].second;
    }

    int holPrefix[N], guernPrefix[N], jersPrefix[N];
    if(cows[0] == 1){
        holPrefix[0] = 1;
    } else {
        holPrefix[0] = 0;
    }

     if(cows[0] == 2){
        guernPrefix[0] = 1;
    } else {
        guernPrefix[0] = 0;
    }

    if(cows[0] == 3){
        jersPrefix[0] = 1;
    } else {
        jersPrefix[0] = 0;
    }

    int holNum = holPrefix[0], guernNum = guernPrefix[0], jersNum = jersPrefix[0];
    for (int i = 1; i < N; i++){
        if(cows[i] == 1){
            holNum += 1;
        } else if(cows[i] == 2){
            guernNum += 1;
        } else if(cows[i] == 3){
            jersNum += 1;
        }
        holPrefix[i] = holNum;
        guernPrefix[i] = guernNum;
        jersPrefix[i] = jersNum;
    }

    for(int i = 0; i < N; i++){
        cout << holPrefix[i] << " " << guernPrefix[i] << " " << jersPrefix[i] << endl;
    }

    int num1 = 0, num2 = 0, num3 = 0;
    for(int i = 0; i < Q; i++){
        if(queries[i].first - 2 >= 0){
            num1 = abs(holPrefix[queries[i].first - 2] - holPrefix[queries[i].second - 1]);
            num2 = abs(guernPrefix[queries[i].first - 2] - guernPrefix[queries[i].second - 1]);
            num3 = abs(jersPrefix[queries[i].first - 2] - jersPrefix[queries[i].second - 1]);
        } else {
            num1 = holPrefix[queries[i].second - 1];
            num2 = guernPrefix[queries[i].second - 1];
            num3 = jersPrefix[queries[i].second - 1];
        }

        fout << num1 << " " << num2 << " " << num3 << endl;
    }



}