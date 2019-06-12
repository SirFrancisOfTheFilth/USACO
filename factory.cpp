#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int visitedAmts[100];
vector<int> adjacency[100];

void dfs(vector<int> adjacency[], int vistedAmts[], int node){
    vector<int> temp = adjacency[node];
    visitedAmts[node] += 1;
        for(int i = 0; i < temp.size(); i++){
             dfs(adjacency, visitedAmts, temp[i]);
        }

        if(temp.size() == 0){
            return;
        }
    }



int main(){
    ifstream fin("factory.in");
    ofstream fout("factory.out");
    int N;
    fin >> N;

    for(int i = 0; i < 100; i++){
        visitedAmts[i] = 0;
    }

    int num1, num2;

    for(int i = 0; i < N - 1; i++){
        fin >> num1 >> num2;
        adjacency[num1 - 1].push_back(num2 - 1);
    }

    for(int i = 0; i < N; i++){
        vector<int> temp = adjacency[i];
        for(int j = 0; j < temp.size(); j++){
            cout << temp[j]<< " ";
        }
        cout << endl;
    }

    
    for(int i = 0; i < 100; i++){
        dfs(adjacency, visitedAmts, i);
    }

    for(int i = 0; i < N; i++){
        cout << visitedAmts[i] << endl;
    }

    bool ifFound = false;
    for(int i = 0; i < 100; i++){
        if(visitedAmts[i] == N){
            ifFound = true;
            fout << i + 1 << endl;
            break;
        }
    }

    if(!ifFound){
        fout << -1 << endl;
    }
    

}