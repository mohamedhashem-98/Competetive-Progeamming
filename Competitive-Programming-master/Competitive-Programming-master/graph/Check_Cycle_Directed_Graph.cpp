#include <bits/stdc++.h>
using namespace std;
vector<int>adj[(int)1e5 + 6];
bool vis[(int)1e5 + 6];
bool Stack[(int)1e5 + 6];
bool check_cycle(int node){
	if(!vis[node]){
		vis[node] = 1 ;
		Stack[node] = 1 ;
		for(int i = 0 ; i < adj[node].size() ; ++i){
			if(!vis[adj[node][i]]&& check_cycle(adj[node][i]))
				return true;
			else if(Stack[adj[node][i]])
				return true;
		}

	}
	Stack[node] = false;
	return false;
}
int main() {
	for(int i = 0 ; i < (int)1e5 + 6 ; ++i)
		vis[i] = 0 ;
	for(int i = 0 ; i < (int)1e5 + 6 ; ++i)
		Stack[i] = 0 ;
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < m; ++i){
		int a , b ;
		cin >> a >> b ;
		adj[a].push_back(b);
	}
	bool ans = false;
	for(int i = 0 ; i < (int)1e5 + 6 ; ++i){
		if(!vis[i]){
			ans = check_cycle(i);
			if(ans){
				cout << "YES" << endl;
				return 0 ;
			}
		}
	}
	cout << "NO" << endl;


	return 0;
}
