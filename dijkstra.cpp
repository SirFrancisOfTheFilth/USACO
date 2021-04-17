#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <set>
using namespace std;


vector<long long int> nbrs[100001];
map<pair<long long int,long long int>, long long int> edgewt;
map<long long int, long long int> dist;
int pred[100000];
 
void dijkstra(int source)
{
  set< pair<long long int,long long int> > visited;//to make sure that no duplicates are stored and it is sorted(could just be a priority queue)
  visited.insert(make_pair(0,source));
  while (!visited.empty()) {
    int i = visited.begin()->second;
    visited.erase(visited.begin());
    vector<long long> t = nbrs[i];
    for (int k = 0; k < t.size(); k++){
      if (dist.count(t[k]) == 0 || dist[i] + edgewt[make_pair(i,t[k])] < dist[t[k]]) {
	dist[t[k]] = dist[i] + edgewt[make_pair(i,t[k])];
	visited.insert(make_pair(dist[t[k]],t[k]));
        pred[t[k]] = i;
      }
    }
  }
  
}

int main(){
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edgewt[make_pair(a-1,b-1)] = c;
        nbrs[a-1].push_back(b-1);
        nbrs[b-1].push_back(a-1);
    }

    dijkstra(0);
    cout << -1 * dist[n-1] << endl;
    cerr << "time elapsed " << (double)clock()/CLOCKS_PER_SEC << endl;
}
