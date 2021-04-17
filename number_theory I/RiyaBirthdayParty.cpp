#include <bits/stdc++.h>
using namespace std;

const int D = 3;
const int MOD = 1e9 + 7;

typedef long long ll;

struct Matriz{
  ll mat[D][D] = { {2,-1,4}, {1,0,0},{0,0,1} };
  
  ll* operator[](int i){
    return mat[i];
  }
  
  Matriz operator*(Matriz oth){
    Matriz res;
    for(int i=0; i<D; i++){
      for(int j=0; j<D; j++){
        res[i][j] = 0;
        for(int k=0; k<D; k++)
          res[i][j] = (res[i][j]+(mat[i][k]*oth[k][j])%MOD + MOD)%MOD;
      }
    }
    return res;
  }
  Matriz exp_matrix(long long e){
    Matriz res;
    for(int i=0; i<D; i++)
      for(int j=0; j<D; j++)
        res[i][j] = (i==j);    
    
    Matriz base = *this;  
    while(e > 0){
      if(e & 1LL)
        res = res * base;
      base = base*base;
      e = e>>1;
    }
    return res;
  }
  
};

int main(){
	
	int T;
	ll N;
	
	cin >> T;
	
	while(T--){
		Matriz res;
		cin >> N; 
		res =  res.exp_matrix(N-1);
		cout << (6*res[1][0] + 1*res[1][1] + 1*res[1][2] )%MOD << endl;
	}
	
}

