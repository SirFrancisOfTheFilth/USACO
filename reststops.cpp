#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");
    long long int L, N, RF, RB;
    fin >> L >> N >> RF >> RB;
    int arr[L];
    for(int i = 0; i < L; i++){
        arr[i] = 0;
    }

    int t1, t2;

    int max = 0;
    vector<int> needVisit;

    for(int i = 0; i < N; i++){
        fin >> t1 >> t2;
        arr[t1-1] = t2;
    }

    for(int i = L -1 ; i >= 0; i--){
        if(max < arr[i]){
            max = arr[i];
            cout << i << endl;
            needVisit.push_back(i);
        }
    }

    sort(needVisit.begin(), needVisit.end());

    long long int frodakcinOrz = 0;
    long long int lastX = -1;
    long long int tF = 0;
    long long int tF = 0;

    for(int i = 0; i < needVisit.size(); i++){
        tF = abs(needVisit[i] - lastX) * RF;
        tF = abs(needVisit[i] - lastX) * RB;
        frodakcinOrz += abs(tF - tB) * (arr[needVisit[i]]);
        lastX = needVisit[i];
    }

    fout << frodakcinOrz << endl;






}