#include <bits/stdc++.h>

using namespace std;


int main(){
	int N;
	string S;
	string T;
	
	cin >> N;
	
	
	while(N--){
		cin >> S;
		cin >> T;
		int freq[26] = {0};
		
		for(int i = 0; i < S.size(); i++){
			freq[ S[i] - 'a']++;
		}
		
		for(int i = 0; i < T.size(); i++){
			freq[ T[i] - 'a']--;
		}
		
		int cont = 0;
		for(int i = 0; i < 26; i++){
			cont += abs( freq[i]);
		}
		
		cout << cont << endl;
		
		
		
	}
	

}
