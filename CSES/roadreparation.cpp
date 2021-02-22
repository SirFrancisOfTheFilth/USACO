//it can be shown that the optimal answer will always be an MST of the graph

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


struct DSU{
	int dsu[100001];
	int sizes[100001];
	
	void make_set(int n){
		for(int i = 0; i < n; i++){
			dsu[i] = i;
			sizes[i] = 1;
		}
	}
	bool verify(int n){
		for(int i = 1; i <= n; i++){
			if(sizes[i] == n){
				return true;
			}
		}
		return false;
	}
	int find(int a){
		if(dsu[a]==a){
			return a;
		} else {
			return (dsu[a] = find(dsu[a]));
		}
	}
	void join(int a, int b){
		a = find(a);
		b = find(b);
		if(sizes[a] < sizes[b]){
			dsu[a] = b;
			sizes[b] += sizes[a];
		} else {
			dsu[b] = a;
			sizes[a] += sizes[b];
		}
	}
};

DSU d;
bool cmp(pair< pair<int,int>, int> one, pair< pair<int,int>, int> two){
	return one.second < two.second;
}
int main(void){
	d.make_set(100001);
	int n, m;
	cin >> n >> m;
	vector< pair< pair<int,int>, int> > edges;
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back(make_pair(make_pair(a,b),w));
	}
	sort(edges.begin(),edges.end(),cmp);
	long long int ans = 0;
	int num_joined;
	for(int i = 0; i < edges.size(); i++){
		if(d.find(edges[i].first.first) != d.find(edges[i].first.second)){
			d.join(edges[i].first.first,edges[i].first.second);
			//cout << "JOIN: "  << edges[i].first.first << " " << edges[i].first.second << " " << edges[i].second << endl;
			ans += edges[i].second;
		}
	}

	bool ret = d.verify(n);
	if(!ret){cout << "IMPOSSIBLE" << endl;}else{cout << ans << endl;}
}
