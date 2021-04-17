#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
const int MOD  = 1e9 + 7;


int nways[MAXN] = {0};

int main(){
	int N, K;
	cin >> N >> K;
		
	nways[1] = 1;
	for(int i = 1; i <= N; i++){
		//printf("nways[%d] = %d\n", i, nways[i]);
		for(int j = 1; j <= K; j++){
			if(i+j <= N)
				nways[i+j] = (nways[i+j] + nways[i]) % MOD;
			else 
				break;
		}
	}
	
	cout << nways[N] << endl;	

}

