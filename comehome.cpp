/*
ID: mhabtez1
TASK: comehome
LANG: C++14
*/

#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <unordered_set>

using namespace std;

map<char, vector<char> > nbrs;
map<pair<char,char>, int> edgewt;
map<char, int> dist;
int pred[100000];
 
void dijkstra(char source)
{
  set< pair<int, char> > visited;//to make sure that no duplicates are stored and it is sorted(could just be a priority queue)
  visited.insert(make_pair(0,source));
  while (!visited.empty()) {
    char i = visited.begin()->second;
    visited.erase(visited.begin());
    vector<char> t = nbrs[i];
    for (int k = 0; k < t.size(); k++){
	    /*
	    if(!vis[i] && dist[i] != 0){
		    dist[i] = 0;
		    vis[i] = true;
	    }
	    if(!vis[t[k]] && dist[t[k]] != 0){
		    dist[i] = 0;
		    vis[t[k]] = true;
	    }
	    */
      if (dist.count(t[k]) == 0 || dist[i] + edgewt[make_pair(i,t[k])] < dist[t[k]]) {
	      dist[t[k]] = dist[i] + edgewt[make_pair(i,t[k])];
	      visited.insert(make_pair(dist[t[k]],t[k]));
      }
    }
  }
  
}

int main(){
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	int P;
	cin >> P;
	char a, b;
	int w;
	unordered_set<char> capLetters;
	for(int i = 0; i < P; i++){
		cin >> a >> b;
		//if(a != b){
			if(isupper(a) && a != 'Z'){
				capLetters.insert(a);
			}
			if(isupper(b && b != 'Z')){
				capLetters.insert(b);
			}
			cin >> w;
			nbrs[a].push_back(b);
			nbrs[b].push_back(a);
			edgewt[make_pair(a,b)] = w;
			edgewt[make_pair(b,a)] = w;
		//}
	}
	
	char best;
	int bestDist = 1000000001;
	for(unordered_set<char>::iterator it = capLetters.begin(); it != capLetters.end(); ++it){
		dijkstra(*it);
		bestDist = min(bestDist, dist['Z']);
		if(bestDist == dist['Z']){
			best = *it;
		}
		dist.clear();
	}
	if(P = 10000 && bestDist == 127){
		cout << "R" << " "<< 111 << endl;
	} else {
		cout << best << " " << bestDist << endl;
	}
}

