#include <bits/stdc++.h>
#include <fstream>
using namespace std;

typedef pair<int, int> pii;
char dfsMulti[1002][1002];
bool visited[1000][1000];

int ret = 0;
int perim = 0;


//floodfill dfs algol
void DFS(char dfsMulti[1002][1002], bool visited[1000][1000], int x, int y, int N){
    if(!visited[x - 1][y - 1] && dfsMulti[x][y] == '#'){
        visited[x - 1][y - 1] = true;

        if(dfsMulti[x+1][y] == '.'){
            perim += 1;
        }
        if(dfsMulti[x-1][y] == '.'){
            perim += 1;
        }
        if(dfsMulti[x][y+1] == '.'){
            perim += 1;
        }
        if(dfsMulti[x][y-1] == '.'){
           perim += 1;
        }


        ret += 1;
        if( x + 1 < N + 1){
            DFS(dfsMulti, visited, x + 1, y, N);
        }
        if(x - 1 >= 1){
            DFS(dfsMulti, visited, x - 1, y, N);
        }
        if(y + 1 < N + 1){
            DFS(dfsMulti, visited, x, y + 1, N);
        }
        if(y - 1 >= 1){
            DFS(dfsMulti, visited, x, y - 1, N);
        }
    }
    
    
}

int main(){
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    int N;
    fin >> N;

    for(int i = 0; i < 1002; i++){
        for(int j = 0; j < 1002; j++){
            dfsMulti[i][j] = '.';
        }
    }


    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            visited[i][j] == false;
            fin >> dfsMulti[i][j];
        }
    }

    vector<pii> combine;
    int maxArea = 0;

    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < N + 1; j++){
            if(!visited[i - 1][j - 1] && dfsMulti[i][j] == '#'){
                DFS(dfsMulti, visited, i, j, N);
                combine.push_back(make_pair(ret, perim));
                maxArea = max(maxArea, ret);
                ret = 0;
                perim = 0;
            }
        }
    }

    sort(combine.begin(), combine.end());
    for(int i = 0; i < combine.size(); i++){
        if(combine[i].first == maxArea){
            fout << maxArea << " " << combine[i].second << endl;
            break;
        }
    }

  
    

    int area = 0;

    

}