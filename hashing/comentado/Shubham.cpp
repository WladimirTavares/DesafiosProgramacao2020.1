#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int N;
	vector <int> a;
	unordered_map < vector<bool> , int> subarray;
	//set < vector<bool> > subarray;
	
	cin >> N;
	a.resize(N);
	
	for(int i = 0; i < N; i++)
		cin >> a[i];
	
	for(int i = 0; i < N; i++){
		vector <bool> v;
		v.assign(1001, false);
		for(int j = i; j < N; j++){
			v[ a[j] ] = true;
			subarray[v]++;		
		}
	}
	
	cout << subarray.size() << endl;
	
	

}

