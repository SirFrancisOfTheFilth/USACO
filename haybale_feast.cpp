#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <utility>
using namespace std;

vector< pair<long long int, long long int> > elems;
long long int flav[100001];

long long int st[100001][18];
int main(void){
    	freopen("hayfeast.in", "r", stdin);
    	freopen("hayfeast.out", "w", stdout);	
    	long long int N, M;
    	cin >> N >> M;
   	for(int i = 0; i < N; i++){
	    long long int u, v;
	    cin >> u >> v;
	    elems.push_back(make_pair(u,v));
    	}
	int log[N+1];
	log[1] = 0;
	flav[0] = elems[0].first;
	for(int i = 1; i < elems.size(); i++){
		flav[i] = flav[i-1] + elems[i].first;
	}
	for (int i = 2; i <= N; i++){
    		log[i] = log[i/2] + 1;
	}
	for (int i = 0; i < N; i++){
    		st[i][0] = elems[i].second;
	}

	for (int j = 1; j <= (double)(ceil(log2(N))); j++){
    		for (int i = 0; i + (1 << j) <= N; i++){
       			 st[i][j] = max(st[i][j-1],st[i + (1 << (j - 1))][j - 1]);
    		}
	}
	//cout << "-------------------------------------" << endl;
	//cout << "-------------------------------------" << endl;

	int lp = 0;
	int rp = 1;
	long long int ans = 1e18+5;
	while(lp < N && rp < N){
		int sm = (lp -1 < 0 ? flav[rp] : flav[rp] - flav[lp-1] );
		if(sm <= M){
			rp++;
		} else if(sm > M){
			//cout << elems[lp].first.first << " " << elems[rp].first.first << endl;
			//cout << sm << endl;
			lp++;
			int tmp = log[rp-lp+1];
			long long int val = max(st[lp][tmp], st[rp-(1<<tmp)+1][tmp]);
			//cout << val << endl;
			ans = min(ans, val);
		}
	}
	cout << min(ans,(long long int)(1e18) ) << endl;

}   
