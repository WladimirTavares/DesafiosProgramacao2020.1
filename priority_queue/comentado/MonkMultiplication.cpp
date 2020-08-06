#include <bits/stdc++.h>
#define ALL(c) c.begin(), c.end()
#define endl '\n'
using namespace std;

typedef long long ll;

int main(){
	int N;
	ll x;
	priority_queue <int> q;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> x;
		q.push(x);
		
		if(q.size() >= 3){
			ll x, y,z;
			x = q.top();
			q.pop();
			y = q.top();
			q.pop();
			z = q.top();
			q.pop();
			q.push(x);
			q.push(y);
			q.push(z);
			x = x*y;
			x = x*z;
			cout << x << endl;
		}else{
			cout << -1 << endl;
		}
	}
	
	
	
	
}
