#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

int N, M;
vi g[100009];
int w[10009];



int main(){
	
	int T;
	
	cin >> T;
	
	while(T--){
	
	
		cin >> N ;
		
		for(int i = 0; i < N-1; i++){
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		for(int i = 0; i < N; i++)
			cin >> w[i];
		
		int ans = 0;
		for(int i = 0; i < N; i++){
			//printf("size %d\n", (int)g[i].size() );
			if( g[i].size() >= 2 && w[i] > 0){
				ans++;
			}
		}
		
		cout << ans << endl;
		
	}
	
	
	
}
