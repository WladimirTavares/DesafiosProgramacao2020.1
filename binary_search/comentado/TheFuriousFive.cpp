#include <bits/stdc++.h>

#define ALL(c) c.begin(), c.end()

typedef long long ll;

using namespace std;


ll count(ll n){
	ll ret = 0LL;
	for( ll x = 5; x <= n; x *= 5){
		ret += n/x;
	}
	return ret; 
}

ll answer(int N){
	ll begin, end;
	begin = 0;
	end   = 5LL*N;
	
	while( begin < end ){
		ll mid = (begin+end)/2LL;
		//printf("%lld %lld\n", begin, end);
		if( count(mid) < N ) begin = mid+1;
		else end = mid;
	}
	
	return begin;
	
}


int main(){
	int T, N;
	cin >> T;
	
	while(T--){
		cin >> N;
		cout << answer(N) << endl;
	}
	
	
	
}

