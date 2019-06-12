
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){

    ifstream fin("highcard.in");
    ofstream fout("highcard.out");
    int N;
    fin >> N;
    
    bool visited[2*N];
    for(int i = 0; i < 2*N; i++){
        visited[i] = true;
    }
    vector<int> cards;
    vector<int> elsie;

    int card;
    for(int i = 0; i < N; i++){
        fin >> card;
        cards.push_back(card);
        visited[card - 1] = false;
     }

     for(int i = 0; i < 2*N; i++){
         if(visited[i]){
             elsie.push_back(i + 1);
         }
     }
    
    int counter = 0;
    for(int i = 0; i < N; i++){
        vector<int>::iterator it;
        it = lower_bound(elsie.begin(), elsie.end(), cards[i]);
        if(it != elsie.end()){
            elsie.erase(it);
            counter += 1;
        }
    
    }
    fout << counter << endl;
    


}