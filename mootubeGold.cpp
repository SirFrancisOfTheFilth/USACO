#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
using namespace std;


vector< pair< pair<int,int>, int> > weights;


bool cmp2(pair< pair<int,int>,int> one, pair< pair<int,int>, int> two){
    return one.first.first >= two.first.first;
}
bool cmp(pair<pair<int,int>,int> one, pair< pair<int,int>,int > two){
    return one.second >= two.second;
}


struct DSU {
    int dsu[100000 + 1];
    int sizes[100000 + 1];

    void make_set(int n) {
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int a) {
        if (dsu[a] == a) return a;
        return (dsu[a] = find(dsu[a]));
    }

    //weighted union function
    void join(int a, int b) {
        int ae = find(a);
        int be = find(b);
        sizes[be] += sizes[ae];
        dsu[ae] = be;
    }

    bool isSameSet(int a, int b){
        int x = find(a);
        int y = find(b);
        return x == y;
    }

};


int main(void){
   freopen("mootube.in", "r", stdin);
   freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;

    DSU store;
    store.make_set(100000);



    int Winter_is_coming19;


    int a, b, w;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b >> w;
        weights.push_back(make_pair( make_pair(a-1,b-1), w));
    }
    sort(weights.begin(), weights.end(), cmp);

    int v, limit;
    vector< pair<pair<int,int>, int> > queries;
    for(int i = 0; i < q; i++){
        cin >> limit >> v;
        queries.push_back( make_pair(make_pair(limit,v-1),i));
    }
    sort(queries.begin(),queries.end(),cmp2);


    for(int i = 0; i < weights.size(); i++){
        //cout << weights[i].first.first << " " << weights[i].first.second << " " << weights[i].second << endl;
    }
    //cout << endl;

    for(int i = 0; i < queries.size(); i++){
        //cout << queries[i].first.first << " " << queries[i].first.second << " " << queries[i].second<< endl;
    }
    
    
    int counter = 0;
    int res[100000];

    for(int i = 0; i < q; i++){
        while(queries[i].first.first <= weights[counter].second && counter <= n - 1){
            store.join(weights[counter].first.first, weights[counter].first.second);
            counter++;
        } 
        res[queries[i].second] = store.sizes[store.find(queries[i].first.second)] - 1;
    }
    
    //cout << endl;
    for(int i = 0; i < q; i++){
        cout << res[i] << endl;
    }
    cerr << "time elapsed " << (double)clock()/CLOCKS_PER_SEC << endl;







}