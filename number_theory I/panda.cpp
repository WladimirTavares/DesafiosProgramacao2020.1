#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e6 + 3;
const int MAXN = 1e6 + 4;

ll arr[MAXN];

int main(){
	int T;
	
	arr[0] = 1;
	for(int i = 1; i < MAXN; i++)
		arr[i] = (i*arr[i-1])%MOD;
	
	cin >> T;
	
	while(T--){
		ll N, X;
		
		cin >> N >> X;
		
		if( N >= MOD ) printf("0\n");
		else{
			ll res = (arr[N]*X)%MOD;
			cout << res << endl;
		}
		
	}
	
	

}
