#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool fence[2001][2001];


int floodfill(int x, int y, int N){
    if(!fence[x][y]){
        fence[x][y] = true;
        if(x - 1 >= 0){
            floodfill(x-1, y,N);
        }
        if(x + 1 <= 2000){
            floodfill(x+1,y,N);
        }
        if(y-1 >= 0){
            floodfill(x, y - 1, N);
        }
        if(y + 1 <= 2000){
            floodfill(x, y + 1, N);
        }

    }
}

int main(){
    ifstream fin("gates.in");
    ofstream fout("gates.out");
    int N;
    fin >> N;
    string direction;
    fin >> direction;


    for(int i = 0; i < 2001; i++){
        for(int j = 0; j < 2001; j++){
            fence[i][j] = false;
        }
    }


    int curX = 1000;
    int curY = 1000;
    fence[curX][curY] = true;
    for(int i = 0; i <= N; i++){
        if(direction[i] == 'N'){
            curX -= 1;
            fence[curX][curY] = true;
            curX -= 1;
        } else if(direction[i] == 'S'){
            curX += 1;
            fence[curX][curY] = true;
            curX += 1;
        } else if(direction[i] == 'E'){
            curY += 1;
            fence[curX][curY] = true;
            curY += 1;
        } else if (direction[i] == 'W'){
            curY -= 1;
            fence[curX][curY] = true;
            curY -= 1;
        }
        fence[curX][curY] = true;
        //cout << curX << ":" << curY << endl;
    }



    int counter = 0;
    for(int i = 1000 - N; i <= 1000 + N; i++){
        for(int j = 1000 - N; j <= 1000 + N; j++){
            if(!fence[i][j]){
                counter += 1;
                floodfill(i,j,N);
            }
        }
    }

    fout << counter - 1 << endl;



}