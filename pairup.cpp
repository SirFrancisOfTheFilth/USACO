#include <bits/stdc++.h>
#include <fstream>
#include <utility>
using namespace std;

typedef pair<int, int> pii;


int minimum = -1;

bool cmp(pii one, pii two){
    return one.second < two.second;
}

int main(){
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");
    int N;
    fin >> N;

    pii A[N];
    for(int i = 0; i < N; i++){
        fin >> A[i].first >> A[i].second;
    }

    sort(A, A+N, cmp);

    int start = 0;
    int end = N - 1;

    int tempMin = 0;
    int minDiff = 0;

    while(start <= end){
        minDiff = min(A[start].first, A[end].first);
        tempMin = A[start].second + A[end].second;
        minimum = max(minimum, tempMin);

        A[start].first -= minDiff;
        A[end].first -= minDiff;

        if(A[start].first <= 0){
            start += 1;
        }
        if(A[end].first <= 0){
            end -= 1;
        }
    }

    fout << minimum << endl;
    




}