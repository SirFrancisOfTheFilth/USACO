#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <map>
#include <algorithm>
using namespace std;

char flood[1000][1000];
bool visited[1000][1000];

int counter = 0;
void floodfill(int x, int y, int n, int m){
    if(!visited[x][y] && flood[x][y] == '.'){
        visited[x][y] = true;
        if(x + 1 < n && flood[x+1][y] == '.'){
            floodfill(x+1,y,n,m);
        }
        if(x - 1 >= 0 && flood[x-1][y] == '.'){
            floodfill(x-1,y,n,m);
        }
        if(y + 1 < m && flood[x][y+1] == '.'){
            floodfill(x,y+1,n,m);
        }
        if(y-1 >= 0 && flood[x][y-1] == '.'){
            floodfill(x,y-1,n,m);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> flood[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && flood[i][j] == '.'){
                floodfill(i,j,n,m);
                counter += 1;
            }
        }
    }

    cout << counter << endl;
}