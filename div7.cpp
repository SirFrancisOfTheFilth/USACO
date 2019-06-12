#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

bool det(int A[], int val, int N){
    int startIndex = 0;
    int tempIndex = 0;
    int value = 0;

    bool ifSeven = false;

    while(startIndex <= N - val){
         while(tempIndex < val){
            value += A[startIndex + tempIndex];
            tempIndex += 1;
        }
        startIndex += 1;
        tempIndex = 0;
        if(value % 7 == 0){
            ifSeven = true;
            break;
        }
        value = 0;
    }

    return ifSeven;
}


int main(){
    ifstream fin("div7.in");
    ofstream fout("div7.out");


    
    int N;
    fin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        fin >> A[i];
    }
    int psum[N];
    psum[0] = A[0];
    for(int i = 1; i < N; i++){
        psum[i] = psum[i-1] + A[i];
    }

    vector<int> lengths;
    for(int i = N - 1; i >= 0; i--){
        if(psum[i] % 7 == 0){
            lengths.push_back(1);
        } else {
            for(int j = 0; j < i; j++){
                if(abs(psum[i] - psum[j]) % 7 == 0){
                    lengths.push_back(abs(i-j));
                    break;
                }
            }
        }
    }

    if(*max_element(lengths.begin(), lengths.end()) == 1){
        fout << 0 << endl;
    } else {
        fout << *max_element(lengths.begin(), lengths.end()) << endl;
    }
}