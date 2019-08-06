#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[2000000];
vector< pair<int, int> > pathFinding;
vector<int> path;
int prevo[2000000];

//determining and reporting shortest path of a graph with BFS(7/10 cases correct, gives runtime error on cases missed)

bool visited[200000];

void reportPath(int source){
  for(int a = 0; a != source; a = prevo[a]){
      path.push_back(a);
  }
  path.push_back(source);
}

int BFS(int source, int desired){
  queue< pair<int,int> > q;
  q.push(make_pair(0,source));
  pathFinding.push_back(make_pair(0,source));
  while(!q.empty()){
    pair<int, int> num = q.front();
    if(num.second == desired){
      return num.first;
    }
    q.pop();
    if(!visited[num.second]){
      visited[num.second] = true;
      vector<int> qq = adj[num.second];
      for(int i = 0; i < qq.size(); i++){
        if(!visited[qq[i]]){
          prevo[num.second] = max(prevo[num.second], qq[i]);
          pathFinding.push_back(make_pair(num.first + 1, qq[i]));
          q.push(make_pair(num.first + 1, qq[i]));
        }
      }
    }

    }
  return -1;
}


int main(){
  int N, M;
  cin >> N >> M;
  int v1, v2;
  for(int i = 0; i < 200000; i++){
    prevo[i] = -1;
  }
  for(int i = 0; i < M; i++){
    cin >> v1 >> v2;
    adj[v1 - 1].push_back(v2 - 1);
    adj[v2 - 1].push_back(v1 - 1);
  }


  int n = BFS(0, N-1);
  if(n == -1){
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << n + 1 << endl;
    reportPath(N-1);
    cout << "SIZE: " << path.size() << endl;
    for(int i = 0; i < path.size(); i++){
      cout << path[i] + 1 << " ";
    }
    cout << endl;
  }

 

}