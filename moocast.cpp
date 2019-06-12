#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;




int counter = 0;
void DFS(vector<int> adjacency[], bool visited[], int node){
    vector<int> temp = adjacency[node];

    if(!visited[node]){
        visited[node] = true;
        counter += 1;
        for(int i = 0; i < temp.size(); i++){
            DFS(adjacency, visited, temp[i]);
        }
    }
}

int main(){
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    int N;
    fin >> N;

    bool visited[N];
    for(int i = 0; i < N; i++){
        visited[i] = false;
    }
    vector<int> adjacency[N];


    pii cords[N];
    int cost[N];
    for(int i = 0; i < N; i++){
        fin >> cords[i].first >> cords[i].second >> cost[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
                if( (sqrt( pow(abs(cords[i].first - cords[j].first), 2) + pow(abs(cords[i].second - cords[j].second), 2) ) <= cost[i])  && (i != j) ){
                    adjacency[i].push_back(j);
                }
        }
    }

    for(int i = 0; i < N; i++){
        vector<int> temp = adjacency[i];
        for(int j = 0; j < temp.size(); j++){
            cout << i << ":" << temp[j] << endl;
        }
    }

    int maximum = 0;
    for(int i = 0; i < N; i++){
        DFS(adjacency, visited, i);
        cout << counter << endl;
        maximum = max(maximum, counter);
        counter = 0;
        for(int j = 0; j < N; j++){
            visited[i] = false;
        }
    }

    fout << maximum << endl;


}