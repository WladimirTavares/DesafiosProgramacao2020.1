#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;

int a[MAXN];

int main(){
	//ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
	int N;
	
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	
	bool possible = true;
	for(int i = 0; i < N-1; i++){
		if(a[i] > a[i+1]){
			possible = false;
			break;
		}else{
			int r = a[i];
			a[i]   -= r;
			a[i+1] -= r;
		}
	}
	
	//for(int i = 0; i < N; i++)
	//	cout << a[i] << " ";
	possible = a[N-1] == 0;
	
	cout << (possible ? "YES" : "NO" ) << endl;
	
}
