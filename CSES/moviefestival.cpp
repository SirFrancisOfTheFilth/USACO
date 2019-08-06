#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> pii;
bool cmp(pii one, pii two){
    return one.second < two.second;
}

int main(){
    int N;
    cin >> N;
    vector<pii> movies;
    int s, e;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        movies.push_back(make_pair(s,e));
    }

    sort(movies.begin(), movies.end(), cmp);

    pii curPair = make_pair(movies[0].first, movies[0].second);
    int index = 1;
    int counter = 1;
    while(index < N){
        if(movies[index].first >= curPair.second){
            counter++;
            curPair = movies[index];
        }
        index += 1;
    }

    cout << counter << endl;


}