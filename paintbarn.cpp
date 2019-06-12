#include <iostream>
#include <fstream>
using namespace std;


int twosums[1001][1001];
int prefsums[1001][1001];

int main(){
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            twosums[i][j] = 0;
        }
    }

    int N, K;
    fin >> N >> K;
    int t1, t2, t3, t4;
    for(int i = 0; i < N; i++){
        fin >> t1 >> t2 >> t3 >> t4;
        for(int i = t1; i < t3; i++){
            twosums[i][t2]++;
            twosums[i][t4]--;
        }
    }
    
   for(int i = 0; i < 1001; i++){
       for(int j = 1; j < 1001; j++){
           twosums[i][j] += twosums[i][j-1];
       }
   }
  

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cout << twosums[i][j];
        }
        cout << endl;
    }

    int count = 0;
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            if(twosums[i][j] == K){
                count += 1;
            }
        }
    }

    fout << count << endl;

}