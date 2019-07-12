#include <map>
#include <set>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

int endPlanet = -1;
int tp[200001];
int successor[200001][31];

int n;




int main(){
  long long int n, q;
  cin >> n >> q;
  int num;
  for(int i = 0; i < n; i++){
    cin >> num;
    tp[i] = num - 1;
  }


  for(int i = 0; i <= 30; i++){
    for(int j = 0; j < 200001; j++){
      if(i == 0){
        successor[j][i] = tp[j];
      } else {
        successor[j][i] = successor[successor[j][i-1]][i-1];
      }
    }
  }


  
  long long int p1, p2;
  for(int i = 0; i < q; i++){
    cin >> p1 >> p2;
    string bitsVal = bitset<30>(p2).to_string();
    vector<int> elems;

    for(int j = 0; j < 30; j++){
      if( bitsVal[j] == '1'){
        elems.push_back(30 - j - 1);
      }
    }

    if(p2 == 0){
      cout << p1 << endl;
    } else if(p2 == 1){
      cout << tp[p1-1]+1 << endl;
    } else {
      if(elems.size() == 1){
        cout << successor[p1-1][p2-1] + 1 << endl;
      } else {
        int val1 = elems[0];
        int val2 = elems[1];
        int fVal = successor[successor[p1-1][val1]][val2];
        for(int j = 2; j < elems.size(); j++){
          fVal = successor[fVal][elems[j]];
        }
        cout << fVal + 1 << endl;
      }
    }

  }
  }
