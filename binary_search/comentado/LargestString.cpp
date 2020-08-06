#include <bits/stdc++.h>

using namespace std;

vector <int> zeros;
vector <int> ones;
vector <int> temp;
vector <int> mini;

void print(char * nome, vector <int> v){
	printf("%s = {", nome);
	for(int i = 0; i < (int)v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("}\n");
}

int main(){
	int N;
	string s;
	
	cin >> N;
	cin >> s;
	s = " " + s;
		
	zeros.resize(N+1);
	ones.resize(N+1);
	temp.resize(N+1);
	mini.resize(N+1);
	
	zeros[0] = 0;
	ones[0]  = 0;
	temp[0] = 0;
	mini[0] = 0;
	
	for(int i = 1; i <= N; i++){
		zeros[i] = zeros[i-1];
		ones[i] = ones[i-1];
		if( s[i] == '0') zeros[i]++;
		else ones[i]++;
		temp[i] = zeros[i] - ones[i];
		mini[i] = min( mini[i-1], temp[i]);
	}
	
	
	int ans = 0;
	for(int i = 1; i <= N; i++){
		
		int l, r, mid;
		int res = -1;
		
		l = 0;
		r = i;
		
		while( l <= r){
			mid = l + (r-l)/2;
			if( temp[i] > mini[mid] ){
				res = i - mid;
				r   = mid - 1; 
			}else{
				l = mid + 1;
			}
		}
		
		ans = max( ans, res);
		
	}
		
	cout << ans << endl;
	
}

