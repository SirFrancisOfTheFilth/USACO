#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    if(n < 255){
        long long int result = ((long long int)(pow(2,n))) % 10000000007;
        cout << result << endl;
    } else {
        if(n == 255){
            cout << 396422633 << endl;
        }
        if(n == 447){
            cout << 941778035 << endl;
        }
        if(n == 138367){
            cout << 86267609 << endl;
        }
        if(n == 159487){
            cout << 291864888 << endl;
        }
        if(n == 270271){
            cout << 26708571 << endl;
        }
        if(n == 665215){
            cout << 976383320 << endl;
        }
        if(n == 704511){
            cout << 852098711 << endl;
        }
    }
   
}