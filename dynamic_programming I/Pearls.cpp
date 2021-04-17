#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

typedef long long ll;


int main(){
	
	int N, K;
	int x;
	cin >> N >> K;
	 
	cin >> x;
	ii p(x,x);
	ll ans = 0LL;
	for(int i = 0; i < N-1; i++){
		cin >> x;
		if(x < p.first){
			p.first = x;
			p.second = x;
		}else if( x > p.second){
			p.second = x;
			ans = max( ans, (ll)(p.second-p.first)*K);
		}
		
		//printf("%lld\n",ans);
		
	}
	
	printf("%lld\n",ans);

}
