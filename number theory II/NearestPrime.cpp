#include <bits/stdc++.h>
#define ALL(c) c.begin(), c.end()
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 9;



int main(){ _
	
	
	int lp[MAXN+1];
	vector<int> pr;
	
	memset(lp, 0, sizeof(lp));
	for (int i=2; i<=MAXN; ++i) {
			if (lp[i] == 0) {
					lp[i] = i;
					pr.push_back (i);
			}
			for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=MAXN; ++j)
					lp[i * pr[j]] = pr[j];
	}
	
	
	
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		
		for(int i = n, j = n; ; i--, j++){
			if( lp[i] == i ){
				cout << i << endl;
				break;
			}
			if( lp[j] == j ){
				cout << j << endl;
				break;
			}
		}
		
	}
	
	
	
	
	
	
	


}

