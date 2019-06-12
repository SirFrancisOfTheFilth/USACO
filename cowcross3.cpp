#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[100][100];
bool visited[100][100];

bool directlyAdjacent(int x1, int y1, int x2, int y2){
    if( ((x1 == x2 + 1) || (x1 == x2 - 1))  && (y2 == y1) ){
        return true;
    } 
    if( ((y1 == y2 - 1) || (y1 == y2 + 1)) && (x2 == x1)) {
        return true;
    } 
    return false;
}

bool reach = false;
//re-invented dfs
void floodfill(int x, int y, int endX, int endY, int N){
    if( (x == endX) && (y == endY) ){
        reach = true;
        return;
    } else {
        if(!visited[x][y]){
            //cout << x << ":" << y << endl;
            visited[x][y] = true;
            bool tempReach = false;
        if(x + 1 <= N - 1 && (find(adj[x][y].begin(), adj[x][y].end(), make_pair(x+1,y)) == adj[x][y].end()) ){
            floodfill(x+1,y,endX,endY,N);
        }
         if(x - 1 >= 0 && (find(adj[x][y].begin(), adj[x][y].end(), make_pair(x-1,y)) == adj[x][y].end()) ){
            floodfill(x-1,y,endX,endY,N);
        }
         if(y - 1 >= 0 && (find(adj[x][y].begin(), adj[x][y].end(), make_pair(x,y-1)) == adj[x][y].end()) ){
            floodfill(x,y-1,endX,endY,N);
        }
        if(y + 1 <= N - 1 && find(adj[x][y].begin(), adj[x][y].end(), make_pair(x, y+1)) == adj[x][y].end() ){
            floodfill(x,y+1,endX,endY,N);
        }

        } else {
            return;
        }
    }
}



//bfs
/*
void bfs(int node){
    while(!q.empty()){
        int c = q.front();
        if(!visited[c - 1]){
            q.pop();
            visited[c] = true;
            vector<int a = adj[c];
            for(int i = 0; i < adj[c].size(); i++){
                if(!visited[a[i]]){
                    q.push(a[i]);
                }
            }
        }
    }
}
*/

int main(){
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");
    int N, K, R;
    fin >> N >> K >> R;
    int x1, y1, x2, y2;
    vector<pii> pairs;
    for(int i = 0; i < R; i++){
        fin >> x1 >> y1 >> x2 >> y2;
        adj[x1-1][y1-1].push_back(make_pair(x2-1,y2-1));
        adj[x2-1][y2-1].push_back(make_pair(x1-1,y1-1));
    }
    int cowX, cowY;
    for(int i = 0; i < K; i++){
        fin >> cowX >> cowY;
        pairs.push_back(make_pair(cowX, cowY));
    }

    bool b = directlyAdjacent(1,1,2,2);
    //if(!b){dfs(1,1,2,2); if(reach){cout << "tru" << endl;} }else{cout << "false" << endl;}


    /*
    int count = 0;
    for(int i = 0; i < pairs.size(); i++){
        for(int j = 0; j < pairs.size(); j++){
            if(i != j){
                if(directlyAdjacent(pairs[i].first - 1, pairs[i].second - 1, pairs[j].first - 1, pairs[j].second - 1)){
                    vector<pii>::iterator it = find(adj[pairs[i].first-1][pairs[i].second-1].begin(), adj[pairs[i].first -1][pairs[i].second-1].end(), make_pair(pairs[j].first -1, pairs[j].second - 1));
                    if(it != adj[pairs[i].first -1][pairs[i].second - 1].end()){
                        count++;
                    }
                }
            }
        }
    }
    */



   
   int count = 0;
   for(int i = 0; i < pairs.size(); i++){
       for(int j = 0; j < pairs.size(); j++){
           if(i != j){
               floodfill(pairs[i].first - 1, pairs[i].second - 1, pairs[j].first - 1, pairs[j].second - 1, N);
               if(!reach){
                   count += 1;
               }
               reach = false;
               for(int k = 0; k < 100; k++){
                   for(int l = 0; l < 100; l++){
                       visited[k][l] = false;
                   }
               }
           }
       }
   }


   fout << count/2 << endl;
   
    

}
