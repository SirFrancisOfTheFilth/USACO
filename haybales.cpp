#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;


int main(){
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    int N, Q;
    fin >> N >> Q;
    int t1;

    vector<int> A;

    for(int i = 0; i < N; i++){
        fin >> t1;
        A.push_back(t1);
        
    }
    sort(A.begin(), A.end());
    int low = 0;
    int high = N - 1;
    int target = 10;



    int first, second;
    for(int i = 0; i < Q; i++){
        fin >> first >> second;
        if(first - 1 < A[0]){
            vector<int>::iterator it1 = upper_bound(A.begin(), A.end(), second);
            fout << it1 - A.begin() << endl;
        } else {
            vector<int>::iterator it1 = upper_bound(A.begin(), A.end(), first - 1);
            vector<int>::iterator it2  = upper_bound(A.begin(), A.end(), second);
            fout << (it2 - A.begin()) - (it1 - A.begin()) << endl;
        }

    }



}