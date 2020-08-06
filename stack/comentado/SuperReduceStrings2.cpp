#include <bits/stdc++.h>

using namespace std;


int main(){
	
	string str;
	
	cin >> str;
	
	stack <char> Stack;
	
	
	for(int i = 0; i < (int)str.size(); i++){
		if( Stack.size() == 0) Stack.push(str[i]);
		else {
			if( Stack.top() == str[i] ){
				Stack.pop();
			}else{
				Stack.push(str[i]);
			}
		}
	}
	
	str.resize( Stack.size() );
	
	for(int i = Stack.size()-1; i >= 0; i--){
		str[i] = Stack.top();
		Stack.pop();
	}
	
	if( str.size() == 0)
		cout << "Empty String" << endl;
	else 
		cout << str << endl;
	
	

}
