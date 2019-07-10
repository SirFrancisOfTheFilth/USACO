#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

//greedy algorithm: problem reduces to finding the maximally occurring value in the array but since q is up to 10^9, using an array isnt possible

int main(){
  int n;
  cin >> n;
  int a[n];
  vector<pii> occur;
  for(int i = 0; i < n; i++){
      cin >> a[i];
      occur.push_back(a[i], occur[a[i]].second + 1);
  }
  sort(occur.begin(), occur.end(),greater<int>());
  pii bq = occur[0];
  int amt = 0;
  for(int i = 0; i < n; i++){
    amt += abs(bq - a[i]);
  }
  cout << amt << endl;
  
  
  
}
