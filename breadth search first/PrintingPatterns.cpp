#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int INF = 0x3f3f3f3f;

int r, c, x, y;

const int MAXN = 1e3;
int g[MAXN+2][MAXN+2];
int dx[] = { -1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = { -1,  0,  1, -1, 1, -1, 0, 1};  

int main(){
		
	cin >> r >> c >> x >> y;
	
	for(int i = 0; i < r + 2; i++)
		for(int j = 0; j < c + 2; j++)
			if(i == 0 || i == r+1 || j == 0 || j == c+1)
				g[i][j] = 0;
			else
				g[i][j] = -1;
	
	
	x++;
	y++;
	
	g[x][y] = 0;
		
		
	queue <ii> q;
		
	q.push( ii(x,y) );
	while( !q.empty() ){
		int px, py;
		tie(px,py) = q.front();
		//printf("visitando %d %d\n", px, py); 
		
		//if(g[px][py] > 1) break;
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int vx = px + dx[i]; 
			int vy = py + dy[i]; 
			if( g[vx][vy] == -1){
				g[vx][vy] = g[px][py] + 1; 
				q.push( ii(vx, vy) );
			}
		}
		
	}
	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
	
	
}
