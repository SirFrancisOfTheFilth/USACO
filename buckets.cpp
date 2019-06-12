#include <bits/stdc++.h>
#include <fstream>
using namespace std;

char grid[10][10];
int visitedAmts[100];


int main(){
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    int bucketX = 0;
    int bucketY = 0;
    int lakeX = 0;
    int lakeY = 0;
    int rockX = 0;
    int rockY = 0;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            fin >> grid[i][j];
            if(grid[i][j] == 'B'){
                bucketX = i;
                bucketY = j;
            } 
            if(grid[i][j] == 'L'){
                lakeX = i;
                lakeY = j;
            }
            if(grid[i][j] == 'R'){
                rockX = i;
                rockY = j;
            }
        }
    }

    int conditional = abs(bucketX - lakeX) + abs(bucketY - lakeY) - 1;

    int maxX = max(bucketX, lakeX);
    int minX = min(bucketX, lakeX);
    int maxY = max(bucketY, lakeY);
    int minY = min(bucketY, lakeY);

   
    if( lakeX == bucketX && rockX == bucketX ){
        if( rockY > minY && rockY < maxY){
            conditional += 2;
        }
    } else if( lakeY == bucketY && rockY == bucketY  ){
        if(rockX > minX && rockX < maxX){
            conditional += 2;
        }
    } 

    fout << conditional << endl;



}