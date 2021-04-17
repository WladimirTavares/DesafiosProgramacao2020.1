#include <bits/stdc++.h> 

using namespace std; 

const int MAXV = 5001;
const int MAXN = 1e5 + 1 ;

int n;



bitset<MAXV+1> tree1[2*MAXN];
bitset<MAXV+1> tree2[2*MAXN];
int arr[MAXN];

void build(int *arr, bitset<MAXV+1> *tree)  {  
	//printf("build\n");
	for (int i=0; i<n; i++){     
		tree[n+i].reset();
		tree[n+i].set(arr[i]);
		//cout << "tree[" << (n+i) << "]" << tree[n+i].to_string() << endl;
	} 
	for (int i = n - 1; i > 0; --i){      
		tree[i] = tree[i<<1] | tree[i<<1 | 1];     
		//cout << "tree[" << i << "]" << tree[i].to_string() << endl;
	}
} 



  
bitset<MAXV+1> query(bitset<MAXV+1> *tree, int l, int r)  
{  
    bitset<MAXV+1> ans;
    ans.reset(); 
      
    // loop to find the sum in the range 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            ans = ans | tree[l++]; 
      
        if (r&1)  
            ans = ans | tree[--r]; 
    } 
      
    return ans; 
} 

int main(){
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);	
	}	
	build(arr, tree1);
	
	//cout << query(tree1, 0, 2).to_string() << endl;
	
	
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);	
	}	
	build(arr, tree2);
	
	
	
	int q;
	scanf("%d", &q);
	
	for(int i = 0; i < q; i++){
		int a,b,c,d;
		
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a--;
		c--;
		
		bitset<MAXV+1> ans1 = query(tree1, a, b);
		bitset<MAXV+1> ans2 = query(tree2, c, d);
		
		//cout << ans1.to_string() << endl;
		//cout << ans2.to_string() << endl;
		
		ans1 = ans1 | ans2;
		
		cout << ans1.count() << endl;
		
		
	}
	

}
	
	
	
