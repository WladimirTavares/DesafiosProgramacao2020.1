/*
Problem: https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/charged-up-array-f35a5e23/
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int mod = (int)1e9 + 7;
const int maxn = (int) 1e5 + 1;
const LL inf = (int) 1e18 + 1;

LL a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
	int T, N;
	LL charge;
	LL total_charge;
		
	cin >> T;
	
	for(int i = 1; i <= T; i++){
		cin >> N;
		if( N <=  63)
			charge = 1LL << (N-1);
		else
			charge = 1LL << 62;
			
		//cout << charge << endl;
			
		total_charge = 0LL;
		for(int j = 0; j < N; j++){
			cin >> a[j];
			if( a[j] >= charge)
				total_charge = (total_charge + a[j]) % mod;
		}
		
		cout << total_charge << endl;
	}
	
	
}
