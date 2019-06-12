
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <cmath>
using namespace std;


typedef pair<int, int> pii;


vector<int> adj[100000];
bool visited[100000];
vector<pii> cords;


int minX = 100000000;
int minY = 100000000;
int maxX = -1;
int maxY = -1;

void dfs(int node){
    if(!visited[node]){
        visited[node] = true;
        vector<int> temp = adj[node];
        minX = min(minX, cords[node].first);
        maxX = max(maxX, cords[node].first);
        minY = min(minY, cords[node].second);
        maxY = max(maxY, cords[node].second);
        for(int i = 0; i < temp.size(); i++){
            dfs(temp[i]);
        }
    }
}

int main(){
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");
    int N, M;
    fin >> N >> M;
    int t1, t2;
    for(int i = 0; i < N; i++){
        fin >> t1 >> t2;
        cords.push_back(make_pair(t1, t2));
    }
    int t3, t4;
    for(int i = 0; i < M; i++){
        fin >> t3 >> t4;
        adj[t3 - 1].push_back(t4 - 1);
        adj[t4 - 1].push_back(t3 - 1);
    }

    int perim = 100000000;
    for(int i = 0; i < cords.size(); i++){
        if(!visited[i]){
            dfs(i);
            perim = min(perim, 2 * (abs(minX - maxX) + abs(minY - maxY)) );
            minX = 100000000;
            minY = 100000000;
            maxX = -1;
            maxY = -1;
        }
    }
    fout << perim << endl;

}
