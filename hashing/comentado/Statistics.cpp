#include <bits/stdc++.h>

using namespace std;


int main(){
	int N;
	string name, sport;
	string favorite;
	set <string> eleitores;
	map <string, int> votos;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> name >> sport;
		if( eleitores.count(name) == 0){
			eleitores.insert(name);
			votos[sport]++;
		}
		
	}
	
	favorite = "";
	for(auto it : votos){
		//cout <<  it.first << " tem " << it.second << "votos" << endl;
		if( votos[it.first] > votos[favorite]){
			favorite = it.first;
		}
	}
	
	cout << favorite << endl;
	cout << votos["football"] << endl;
	
	
}
