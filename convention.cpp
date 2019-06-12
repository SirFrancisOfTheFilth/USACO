#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
//semi-classical binary search problem(binsearch on monotonic function)

bool det(int convention[], int time, int N, int M, int C){
    int wagons = 1;
	int firstArrival = convention[0];
	int firstIndex = 0;
	for(int i=1;i<N;i++)
	{
		if(convention[i] - firstArrival > time || i + 1 - firstIndex > C)
		{
			wagons += 1;
			firstArrival = convention[i];
			firstIndex = i;
		}
	}
	return (wagons <= M);

}

int binSearch(int low, int high, int convention[], int N, int M, int C){
    if(low == high) return low;
	if(low + 1 == high)
	{
		if(det(convention, low, N, M, C)) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(det(convention, mid, N, M, C)) return binSearch(low,mid,convention,N,M,C);
	else return binSearch(mid+1,high,convention,N,M,C);

}


int main(){
    ifstream fin("convention.in");
    ofstream fout("convention.out");

    int N, M, C;
    fin >> N >> M >> C;

    int convention[N];
    for(int i = 0; i < N; i++){
        fin >> convention[i];
    }
    sort(convention, convention + N);
    int num = binSearch(0, 1000000000, convention, N, M, C);
    fout << num << endl;
}

