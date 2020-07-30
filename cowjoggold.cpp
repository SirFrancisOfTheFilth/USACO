#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;


int main(){
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	/*
	long long int n, m;
	cin >> n >> m;
	vector<long long int> vz;
	for(int i = 0; i < n; i++){
		int u, v;
		cin >> u >> v;
		vz.push_back(u + (v*m) );
	}
	
	long long int ct = 1;
	long long int ans = 0;
	//repeatedly find longest increasing subsequeunces, remove, and do the same on the remaining parts of the structure
	while(vz.size() > 0){
		set<long long int> st;
		for(int i=0; i<vz.size(); i++) {
    			set<long long int>::iterator it = st.upper_bound(vz[i]); 
			long long int v = 0;
			if(st.size() > 0){
				v = *st.rbegin();
			}
			if(it == st.end() && vz[i] > v){ 
				//cout << vz[i] << " ";
				st.insert(vz[i]);  
				vz.erase(vz.begin() + i); 
				i--;
			}
		}
		//cout << endl;
		ans++;
		
	}

	
	cout << ans << endl;
	*/
}
