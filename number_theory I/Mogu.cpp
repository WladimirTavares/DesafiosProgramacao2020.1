#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 1;

char prime[MAXN];
int prefix[MAXN];

int main(){
	int Q;
	
	
	for(int i = 0; i < MAXN; i++){
		prime[i] = 1;
		prefix[i] = 0;
	}
	prime[0] = 0;
	prime[1] = 0;
	
	ll i = 2;
	for(; i*i < MAXN ; i++){
		prefix[i] = prefix[i-1];
		if(prime[i]){
			prefix[i] = prefix[i-1] + 1;
			
			for(ll j = i*i; j < MAXN; j += i)
				prime[j] = false;
		}
		
	 //printf("prefix[%lld] = %d\n", i, prefix[i]);
	}
	
	for( ; i < MAXN; i++){
		prefix[i] = prefix[i-1];
		if(prime[i]) prefix[i]++;
		//printf("prefix[%lld] = %d\n", i, prefix[i]);
	}
	
	
	scanf("%d", &Q);
	while(Q--){
		int L,R;
		scanf("%d %d", &L, &R);
		if(L > R) swap(L,R);
		printf("%d\n", );
		cout << prefix[R] - prefix[L-1] << endl;
	}

}
