#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
vector<int> adjacency[100000];
bool visited[100000];
void DFS(int node){
    if(!visited[node]){
        visited[node] = true;
        vector<int> t = adjacency[node];
        for(int i = 0; i < t.size(); i++){
            DFS(t[i]);
        }
    }
}
int main(){
    int N, K;
    cin >> N >> K;
    int n1, n2;
    for(int i = 0; i < K; i++){
        cin >> n1 >> n2;
        adjacency[n1 - 1].push_back(n2 - 1);
        adjacency[n2 - 1].push_back(n1 - 1);
    }
    vector<int> construct;
    int c = 0;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            DFS(i);
            c++;
            construct.push_back(i);
        }
    }

    if(c == 1){
        cout << 0 << endl;
        construct.clear();
    } else {
        cout << c - 1 << endl;
        for(int i = 0; i < construct.size() - 1; i++){
            cout << construct[i] + 1 << " " << construct[i + 1] + 1<< endl;
        }
    }



}
