#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6;

vector <bool> sieve;
map <int, int> factor;

int main(){

	sieve.assign(MAXN + 1, true);
	
	for(ll i = 2; i <= MAXN; i++){
		if( sieve[i] ){
			int cont = 1;
			for(ll j = i*i; j <= MAXN; j = j+i){
				if( sieve[j] ){
					sieve[j] = false;
					cont++;
				} 
			}
			factor[i] = cont;
			
		}
	}
	
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		cout << factor[n] << endl;
		
	}
	
	
	
	
	
	
	


}

