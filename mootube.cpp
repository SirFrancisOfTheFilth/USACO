
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
using namespace std;

//definitely  a weighted graph
//implementation of breadth-first-sear
typedef pair<int, int> pii;
vector<int> adjacency[5000];
vector<pii> points;
bool visited[5000];

int weights[5000][5000];
int pathMinimum = 1000000000;

int main(){
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    int N, Q;
    fin >> N >> Q;
    int one, two, three;
    for(int i = 0; i < N - 1; i++){
        fin >> one >> two >> three;
        weights[one - 1][two - 1] = three;
        weights[two  - 1][one - 1] = three;
        adjacency[one - 1].push_back(two - 1);
        adjacency[two - 1].push_back(one - 1);
    }

    int ki, vi;
    int tempCount = 0;
    for(int i = 0; i < Q; i++){
        fin >> ki >> vi;
        points.push_back(make_pair(ki, vi));
        queue<int> q;

        q.push(vi);
        //bfs algol procedure
        while(!q.empty()){
            int curMove = q.front();
            q.pop();
            if(!visited[curMove - 1]){
                visited[curMove - 1] = true;
                vector<int> temp = adjacency[curMove - 1];
                for(int i = 0; i < adjacency[curMove - 1].size(); i++){
                    if(!visited[temp[i]] && weights[curMove - 1][temp[i]] >= ki){
                        q.push(temp[i] + 1);
                        //cout << temp[i] << " ";
                        visited[temp[i]] == true;
                        tempCount += 1;
                    }
                }
            }
        }


       for(int i = 0; i < 5000; i++){
           visited[i] = false;
       }

        fout << tempCount << endl;
        tempCount = 0;
    }



}