#include <bitset>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int N, K;
    fin >> N >> K;

    vector<int> A;
    int val;
    for(int i = 0; i < N; i++){
        fin >> val;
        A.push_back(val);
    }
    sort(A.begin(),A.end());


    int minRad = 0;
    int maxRad = 1000000000;


    while(minRad != maxRad){
        int counter = 0;
        int intervalCount = 0;
        int medRad = (minRad + maxRad)/2;
        while(counter <= N - 1){
                intervalCount++;
                int tempCounter = counter + 1;
                while(tempCounter <= N - 1 && abs(A[counter] - A[tempCounter]) <= 2*medRad){
                   tempCounter++;
                }
                counter = tempCounter;
        }

       
        if(intervalCount <= K){
            maxRad = medRad; 
        } else if(intervalCount > K){
            minRad = medRad+1;
        } 

    }

    fout << minRad << endl;
      

}