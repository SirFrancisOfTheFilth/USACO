#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
using namespace std;
 
 
int main(void){
    long long int n, x;
    cin >> n >> x;
    long long int a[n];
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(a,a+n, greater<int>());

    if(n == 1){
        cout << a[0] * x << endl;
    } else if(x > 1 && s.size() > 1){
        long long int fTime = 0;
        long long int eTime = 2*x*x;
        while(fTime <= eTime){
            long long int mTime = (fTime + eTime)/2;
            long long int sum = 0;
            for(int i = 0; i < n; i++){
                sum += (long long int)(floor((double)(mTime)/a[i]));
            }
            if(sum >= x){
                eTime = mTime - 1;
            } else if(sum < x){
                fTime = mTime + 1;
            }
        }
        cout << fTime << endl;
    } else if(s.size() == 1 ){
        set<int>::iterator it = s.begin();
        cout << x/((*it) * n) << endl;
    } else if(x == 1){
        cout << *min_element(a,a+n) << endl;
    }
    
}