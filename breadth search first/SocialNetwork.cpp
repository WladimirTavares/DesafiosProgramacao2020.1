#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 1;

int N, M;
char g[MAXN][MAXN];
int dist[MAXN];

int bfs(int start, int max_dist){
	queue <int> q;
	memset( dist, 0x3f, sizeof(dist)    );
	q.push(start);
	dist[start] = 0;
	int ans = 0;
	while( !q.empty() ){
		int v = q.front();
		
		if( dist[v] == max_dist ){
			ans++;
		}
		
		if(dist[v] > max_dist){
			break;
		}
		q.pop();
		for(int u = 0; u < N; u++){
			if( g[v][u] == 1 && dist[u] == INF ){
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
	return ans;
}

int main(){
	
	cin >> N >> M;
	
	memset(g, 0, sizeof(g) );
	
	for(int i = 1; i <= M; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	
	int Q;
	cin >> Q;
	
	for(int i = 0; i < Q; i++){
		int s, t;
		cin >> s >> t;
		s--;
		cout << bfs(s, t) << endl;
	}
	
	
}
