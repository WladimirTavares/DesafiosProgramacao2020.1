#include<bits/stdc++.h>

using namespace std;

int digitos[10];

int main(){
	int T;
	string number;
	
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	
	cin >> T;
	
	for(int i = 1; i <= T; i++){
		cin >> number;
		
		memset( digitos, 0 , sizeof(digitos) );
		
		for(int j = 0; j < (int)number.size(); j++){
			digitos[ number[j] - '0']++;
		}
		
		int cnt= 0;
		int j = 0;
		
		while( digitos[j] == 0) j++;
		
		for(; j <= 9; j++){
			if( digitos[j] == 1) { 
				cnt++;
			}else{
				break;
			}	
		}
		
		//cout << cnt << endl;
		bool ok = (cnt == (int)number.size());
		
		cout << (ok ? "YES" : "NO") << endl;
 		
	}
		
	

}






