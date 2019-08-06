#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int N;
    cin >> N;
    map<string, int> countings;
    string str1, str2;
    for(int i = 0; i < N; i++){
        cin >> str1 >> str2;
        countings[str1.substr(0,2) + str2]++;
    }

    int counter = 0;
    for(map<string,int>::iterator it = countings.begin(); it != countings.end(); ++it){
        //cout << it->first << " " << it->second << endl;
        string temp = it->first;
        string temp2 = temp.substr(2,2) + temp.substr(0,2);
        if(temp != temp2){
            counter += countings[temp] * countings[temp2];
        }
    }
    cout << counter/2 << endl;
}