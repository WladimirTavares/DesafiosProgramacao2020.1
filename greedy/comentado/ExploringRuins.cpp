#include <bits/stdc++.h>

using namespace std;



int main(){
	string s;
	cin >> s;
	s += "b";
	
	for(int i = 0; i < s.size() - 1; i++){
		
		if( s[i] == 'a' && s[i+1] == '?'){
			s[i+1] = 'b';
		}
		
		if( s[i] == '?'){
			if( s[i+1] == '?'){
				s[i] = 'a';
				s[i+1] = 'b';
			}else if( s[i+1] == 'a'){
				s[i] = 'b';
			}else if( s[i+1] == 'b'){
				s[i] = 'a';
			}
		}
		
	}	
	
	s.resize( s.size() - 1);	
	
	cout << s << endl;

}
