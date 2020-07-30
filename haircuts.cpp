#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> res;
vector< pair<int,int> > pr;
vector<int> ans;

int main(){
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	cin >> n;
	int tin;
	for(int i = 0; i < n; i++){
		cin >> cont[i];
		pr.push_back(make_pair(cont[i], i));
		res.push_back(i);
	}

	sort(pr.begin(), pr.end() );
	int counter = 0;
	long long int tot_val = 0;
	
	for(int i = 0; i < n; i++){
		cout << tot_val << endl;
		while(pr[counter].first == i){
			int lb = lower_bound(res.begin(), res.end(), pr[counter].second) - res.begin();
			res.erase(res.begin() + lb);
			tot_val += lb;
			counter++;
		}	
	}


}


