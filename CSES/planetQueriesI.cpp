#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

//this code will TLE on cases 6-10, try using successor paths, since each node has an outdegree of at most one

int endPlanet = -1;
void gTraverse(int start, int numTP, int tp[], int n){
   if(numTP==0){
      return;
   } else {
      endPlanet = tp[start];
      gTraverse(tp[start],numTP-1,tp,n);
   }
}


int main(){
  int n, q;
  cin >> n >> q;
  int tp[n];
  for(int i = 0; i < n; i++){
    cin >> tp[i] - 1;
  }
  int start, numTP;
  for(int i = 0; i < q; i++){
    cin >> start >> numTP;
    gTraverse(start,numTP,tp,n);
    cout << endPlanet << endl;
    endPlanet = -1;
  }
}
