#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;


struct node{	
	int num;
	char vl;
	int crt;
	node(){
		num = -1;
		
		vl = (char)( rand() % 1200000);//there was an issue with collision in the tree(i.e. two different values of 2 would be treated as the same in the tree) so a hotfix is to just randomize the value for each value by default, so they won't collide
		crt = 0;
	}

};


//comparator for map(since map in cpp needs comparator if it uses non-primitive type)
struct mapcmp{
	bool operator()(const node& a, const node& b) const{
		if(a.num == b.num){
			return a.vl < b.vl;
		} 
		return a.num < b.num;
	}
};



map<char,int> cnt;
map<char,bool> defined;
map<node, pair<node,node>, mapcmp > nds;
vector< pair<char, int> > vz;


int mx = 0;

//the comparator for sorting
bool cmp(pair<char, int> one, pair<char, int> two){
	return one.second < two.second;
}



//Do a BFS traversal of the tree per layer in order to construct the tree(DFS traversal should work equally as well, same time complexity)
//get max value in tree so i know when to stop while querying(since max value should be unique)
void constructHuffmanTree(){
	queue<node> q;
	nds.clear();
	for(int i = 0; i < vz.size(); i++){
		node psh;
		psh.num = vz[i].second;
		psh.vl = vz[i].first;
		q.push(psh);
	}
	int ct = 0;
	while(!q.empty()){
		node tp = q.front();
		q.pop();
		node tp2 = q.front();
		q.pop();
		node newv;
		newv.num = tp.num + tp2.num;
		mx = max(mx, tp.num + tp2.num);
		node nl;
		nl.num = -1;
		nds[tp2] = make_pair(newv, nl);
		nds[tp] = make_pair(nl, newv);
		q.push(newv);	
	}
}

//DFS traversal in order to query the tree
string queryHuffmanTree(node leaf, string r, bool stop){
	if(stop){
		return r;
	}
	node lft = nds[leaf].first;
	node rght = nds[leaf].second;
	if(lft.num == -1){
		string rp = r + '1';

		if(rght.num == mx){
			return  queryHuffmanTree(rght, rp, true);
		} else {
			return  queryHuffmanTree(rght, rp, false) ;
		}
	} else {
		string rp = r + '0';
		if(lft.num == mx){
			return queryHuffmanTree(lft, rp, true);
		} else {
			return queryHuffmanTree(lft, rp, false);
		}
	}
}


int main(){
	string s = "This is Tyler. Tyler with Grammarly's help is writing an email to his boss, Anita. Tyler sits just 15 feet away, though it could feel like the distance to Antarctica, approximately 47 million feet. Tyler desperately wants Anita to like him, but doesn't want to sound unsure of himself. He also wants to explain the incident at the elevator. But this probably isn't the email for that. It's an email asking to lead a team workshop because more collaboration would be really helpful...beneficial. But Tyler worries that Anita doesn't think he's confident. Especially after the time he told her that, 'I'm a suppository of information', and she gave him this look, since he clearly didn't know what a suppository was. This time, Tyler is determined to find the right words, the ones that will connect best with Anita, so that when Tyler send his email, he receives a response in just 4 minutes and 12 seconds. That includes phrases like, 'I'm impressed!' and 'Such initiative!'. And the distance between Tyler and Anita stops feeling so far. Grammarly. Helping you connect. Go to Grammarly.com to download.";
	freopen("file.in", "r", stdin);

	//counts occurrences of characters (Usage of map here is technically suboptimal, should probably just use like int[26] )
	for(int i = 0; i < s.size(); i++){
		cnt[s[i]]++;
	}
	
	for(int i = 0; i < s.size(); i++){
		if(!defined[s[i]]){
			defined[s[i]] = true; //makes it so the same character isnt inserted into the vector repeatedly
			vz.push_back(make_pair(s[i], cnt[s[i]]));
		}
	}

	//sort the values by a comparator
	sort(vz.begin(), vz.end(), cmp);
	

	//constructing treee(the max value i got was 36 in the tree which i believe is correct)
	constructHuffmanTree();
	

	//query for each value
	for(int i = 0; i < vz.size(); i++){
		node tst;
		tst.num = vz[i].second;
		tst.vl = vz[i].first;
		cout << vz[i].first << " " << vz[i].second << endl;
		cout << queryHuffmanTree(tst, "", false) << endl;
	}

}
