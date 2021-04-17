#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 1;

char is_prime[MAXN];
vector <int> primes;

int main(){
	for(int i = 0; i < MAXN; i++){
		is_prime[i] = 1;
	}
	is_prime[0] = 0;
	is_prime[1] = 0;
	for(ll i = 2; i < MAXN ; i++){
		if(is_prime[i]){
			primes.push_back(i);
			for(ll j = i*i; j < MAXN; j += i){
				is_prime[j] = 0;
			}
		}
	}
	
	int T;
	
	cin >> T;
	
	while(T--){
		
		ll N;
		cin >> N;
		ll cont_non_primes = 1;
		ll cont_fat = 0;
		for(auto p : primes){
			int alpha = 0;
			if(p*p > N) break;
			if(N%p == 0) cont_fat++;
			while(N%p == 0){
				N = N/p;
				alpha++;
			}
			if(alpha > 0)
				cont_non_primes *= (alpha+1);
			//printf("p %d alpha %d cont_non_primes %lld\n", p, alpha, cont_non_primes);
		}
		if( N > 1){
			cont_fat++;
			cont_non_primes *= 2;
			//printf("p %lld alpha %d cont_non_primes %lld\n", N, 1, cont_non_primes);
		}
		
		
		cout << cont_non_primes - cont_fat   << endl;
		
	}
	
	
}

