#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1;
const int MAXCOIN = 10;
const int INF = 1e9;

int coin[MAXCOIN];



int main(){
	
	int N, K;
		
	cin >> N >> K;
	
	for(int i = 0; i < K; i++){
		cin >> coin[i];
	}
	
	vector <int> dp(N+1, INF);
	vector <int> pred(N+1, -1);
	
	dp[0] = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < K; j++){
			if( coin[j] <= i){
				int temp = dp[i-coin[j]] + 1; 
				if( temp < dp[i]){
					dp[i] = temp;
					pred[i] = j;
				}
			}
		}
		//printf("dp[%d] = %d\n", i, dp[i]);
	}

	
}
