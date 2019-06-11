#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200000];
bool visited[200000];
vector<int> degrees;

bool cyclical = false;
//testing for cycles in graph based on property that each node in cycle should have 2 neighbors(i think)
void dfsCycle(int curNode){
    degrees.push_back(curNode);
    if(!visited[curNode] && adj[curNode].size() == 2){
        visited[curNode] = true;
        vector<int> temp = adj[curNode];
        for(int i = 0; i < temp.size(); i++){
            dfsCycle(temp[i]);
        }
    }
}

bool allTwo(){
    for(int i = 0; i < degrees.size(); i++){
        if(adj[degrees[i]].size() != 2){
            return false;
        }
    }
    return true;
}

int main(){
    int V, E;
    cin >> V >> E;
    
    int v1, v2;
    for(int i = 0; i < E; i++){
        cin >> v1 >> v2;
        adj[v1-1].push_back(v2-1);
        adj[v2-1].push_back(v1-1);
    }
    
    int count = 0;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfsCycle(i);
            if(allTwo()){
                count++;
            }
        }
        degrees.clear();
    }
    
    cout << count << endl;
}
