#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1;
const int INF  = 0x3f3f3f3f;
int dp[MAXN];
int coin[4] = {2,3,5,7};


int main(){

	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < MAXN; i++){
		if( dp[i] == INF) continue;
		for(int j = 0; j < 4; j++){
			if( i + coin[j] < MAXN){
				dp[ i + coin[j] ] = min( dp[i+coin[j]], dp[i] + 1 );
			}	
		}
	}
	
	int T;
	
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;
		if(dp[N] == INF) cout << -1 << endl
		else cout << dp[N] << endl;
	}
	
	
	


}
