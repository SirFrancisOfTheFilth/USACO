#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

int a[100001];
pair<int,int> nm[100001];
vector< pair<int,int> > srt;
map< pair<int,int>, bool> vis;
bool vis2[100001];

int main(){
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);

	int N;
	cin>> N;
	for(int i = 0; i< N; i++){
		cin >> a[i];
		nm[a[i]] = make_pair(-1,-1);
	}
	for(int i = 0; i < N; i++){
		if(a[i] == 0){
			continue;
		}

		if(nm[a[i]].first == -1){
			nm[a[i]].first = i;
		} else if(nm[a[i]].first != -1 && max(nm[a[i]].second, i) == i){
			nm[a[i]].second = i;
		}
	}
	for(int i = 0; i < N; i++){
		if(nm[a[i]].second == -1){
			nm[a[i]].second = nm[a[i]].first;
		}
	}
	for(int i = 0; i < N; i++){
		
		if(a[i] == 0){
			continue;
		}
		if(vis2[nm[a[i]].first] || vis2[nm[a[i]].second]){
			continue;
		}
		vis2[nm[a[i]].first] = true;
		vis2[nm[a[i]].second] = true;
		srt.push_back(nm[a[i]]);
	}

	sort(srt.begin(), srt.end());
	int ind = 0;
	int ptr = 1;
	int ans =0;
	while(srt.size() > 0){
		if(!vis[srt[ind]]){
			vis[srt[ind]] = true;
			int lb = lower_bound(srt.begin(), srt.end(), make_pair(srt[ind].second+1, 0) ) - srt.begin();
			if(lb != srt.size()){
				//cout << "ERASED: " << srt[ind].first << " " << srt[ind].second << endl;
				srt.erase(srt.begin() + ind);
				ind = lb-1;

			} else {
				//cout << "ERASED: " << srt[ind].first << " " << srt[ind].second << endl;
				srt.erase(srt.begin() + ind);
				ans++;
				ind = 0;
			}
		} else {
			//cout << "ERASED: " << srt[ind].first << " " << srt[ind].second << endl;

			srt.erase(srt.begin() + ind);
			ans++;
			ind = 0;
		}
	}

	if(ans == 0){
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}

}
