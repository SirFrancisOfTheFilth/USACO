#include <iostream>
#include <set>

using namespace std;

int main(){
    int T;
    cin >> T;
    set<int> fishie;
    int num = 0;
    for(int i = 0; i < T; i++){
        cin >> num;
        fishie.insert(num);
    }
    cout << fishie.size() << endl;
}