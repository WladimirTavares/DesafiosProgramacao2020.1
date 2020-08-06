#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
	int T;
	int N, p ,q, r;
	
	cin >> T;
	
	while(T--){
		
		cin >> N >> p >> q >> r;
		
		vector <int> v;
		
		v.assign(N + 1, 0);
		
		for(int i = p; i <= N; i += p) v[i]++;
		for(int i = q; i <= N; i += q) v[i]++;
		for(int i = r; i <= N; i += r) v[i]++;
		
		int cnt = 0;
		for(int i = 1; i <= N; i++){
			if(v[i] == 1) cnt++;
		}
		
		cout << cnt << endl;
		
		
	}
	
	

}
