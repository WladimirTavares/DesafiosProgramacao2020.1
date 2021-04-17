#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e4+1;


ll A[MAXN];
ll dp[MAXN];


int main(){
	int T;
	int teste = 1;
	cin >> T;
	
	while(teste <= T){
		int N;
		cin >> N;
		
		ll maximumPoints = 0LL;
		dp[1] = 0;
		for(int i = 1; i <= N; i++){
			cin >> A[i];
			dp[i] = max( dp[i-1], A[i]);
			for(int j = 1; j <= i-2; j++){
				dp[i] = max( dp[i], dp[j] + A[i]);
			}
			//printf("dp[%d] = %lld\n", i, dp[i]);
			maximumPoints = max( maximumPoints, dp[i]);
		}
		
		printf("Case %d: %lld\n", teste++, maximumPoints);
		
		
		
	}
}
