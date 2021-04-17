#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()



using namespace std;
const int MAXV = 1e9;

typedef long long ll;

// Function to return the first missing positive 
// number from the given unsorted array 
int firstMissingPos(int A[], int n) 
{ 
  
    // To mark the occurrence of elements 
    bool present[n + 1] = { false }; 
  
    // Mark the occurrences 
    for (int i = 0; i < n; i++) { 
  
        // Only mark the required elements 
        // All non-positive elements and 
        // the elements greater n + 1 will never 
        // be the answer 
        // For example, the array will be {1, 2, 3} 
        // in the worst case and the result 
        // will be 4 which is n + 1 
        if (A[i] > 0 && A[i] <= n) 
            present[A[i]] = true; 
    } 
  
    // Find the first element which didn't 
    // appear in the original array 
    for (int i = 1; i <= n; i++) 
        if (!present[i]) 
            return i; 
  
    // If the original array was of the 
    // type {1, 2, 3} in its sorted form 
    return n + 1; 
} 

int B[5001];
  

int main(){
	int N;
	vector <int> A;
	
	cin >> N;
	A.resize(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	
	ll sum = 0LL;
	for(int i = 0; i < N; i++){
		bool present[N + 2] = { false };
		for(int j = i; j < N; j++){
			//printf("%d ", A[j]);
			if (A[j] <= N) 
        present[A[j]] = true; 
			
			
			for (int k = 1; k <= N+1; k++){ 
        if (!present[k]){ 
          //printf("valor %d\n", k);
          sum += (ll)k;
          break; 
        }
			}
			  
			
		}
		
	}
	cout << sum << endl;

}
