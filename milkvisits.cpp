#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>

using namespace std;
vector<int> adj[100000];
bool visited[100000];
char s[100000];

struct DSUH{
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
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sizes[a] < sizes[b]) {
            dsu[a] = b;
            sizes[b] += sizes[a];
        } else {
            dsu[b] = a;
            sizes[a] += sizes[b];
        }
    }
}

    bool isSameSet(int a, int b){
        int x = find(a);
        int y = find(b);
        return x == y;
    }

};

struct DSUG{
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
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sizes[a] < sizes[b]) {
            dsu[a] = b;
            sizes[b] += sizes[a];
        } else {
            dsu[b] = a;
            sizes[a] += sizes[b];
        }
    }
}

    bool isSameSet(int a, int b){
        int x = find(a);
        int y = find(b);
        return x == y;
    }
};

DSUH dsu;
DSUG dsu2;

void dfs(int node, char s[]){
    if(!visited[node]){
        visited[node] = true;
        vector<int> t = adj[node];

        for(int i = 0; i < t.size(); i++){
            if(s[t[i]] == s[node] && s[t[i]] == 'H'){
                //cout << node << " join holstein " << t[i] << endl;
                dsu.join(node,t[i]);
                dfs(t[i], s);
            } else if(s[t[i]] == s[node] && s[t[i]] == 'G'){
                dsu2.join(node,t[i]);
                //cout << node << " join guernsey " << t[i] << endl;
                dfs(t[i],s);
            }
        }
    }
}


int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    int a, b;
    char c;
    for(int i = 0; i < N-1;i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    dsu.make_set(100001);
    dsu2.make_set(100001);

    //cout << endl;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i,s);

        }
    }

    int a1, b1;
    char c1;


    //cout << endl;
    string res;
    for(int i = 0; i < M; i++){
        cin >> a1 >> b1 >> c1;
        if(c1 == 'H'){
            if(a1 != b1 && (dsu.find(a1-1) == dsu.find(b1-1) || (s[a1-1] != s[b1-1] ) || (s[a1-1] == s[b1-1] && s[a1-1] == 'G' && dsu2.find(a1-1) != dsu2.find(b1-1)) ) ){
                res += '1';
            }else if(a1 == b1 && s[a1-1] == c1){
                res += '1';
            } else {
              res += '0';
            }
        } else {
              if( a1 != b1 && (dsu2.find(a1-1) == dsu2.find(b1-1) || ( s[a1-1] != s[b1-1] ) || (s[a1-1] == s[b1-1] && s[a1-1] == 'H' && dsu.find(a1-1) != dsu.find(b1-1)) ) ){
                  res += '1';
              } else if(a1 == b1 && s[a1-1] == c1){
                  res += '1';
              } else {
                  res += '0';
              }
        }
    }

    cout << res << endl;
    


}
