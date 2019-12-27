#include <bits/stdc++.h>
using namespace std;
int parent[(int)1e5 + 6 ];
int rnk[(int)1e5 + 6];
int findparent(int x){
	if(x == parent[x])return x ;
	return parent[x] = findparent(parent[x]);
}
bool check_connection(int x , int y){
	if(findparent[x] == findparent[y] )return true;
	else return false;
}
void connect(int x , int y){
	int tx = findparent(x);
	int ty = findparent(y);
	if(rnk[tx] > rnk[ty]){
		parent[ty] = tx;
	}
	else if(rnk[tx] < rnk[ty]){
		parent[tx] = ty;
	}
	else{
		parent[tx] = ty;
		rnk[ty]++;
	}
}
int main() {
	for(int i = 0 ; i < (int)1e5 + 6 ; ++i)
		parent[i] = i ;
	for(int i = 0 ; i < (int)1e5 + 6 ; ++i)
		rnk[i] = 0 ;
	int n , m ;
	cin >> n >> m ;
	bool ans = 0 ;
	for(int i = 0 ; i < m; ++i){
		int a , b ;
		cin >> a >> b ;
		if(!check_connection(a , b)){
			connect(a,b);
		}
		else{
			ans = 1 ;
		}
	}
	if(ans)cout << "Yes" <<endl;
	else cout << "No" <<endl;


	return 0;
}
