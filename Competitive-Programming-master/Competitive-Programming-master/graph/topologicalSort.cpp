#include <bits/stdc++.h>
using namespace std;
vector<int>adj[(int)1e5 + 6];
bool vis[(int)1e5 + 6];
stack<int>st;
void topologicalSort(int node){
	vis[node] = 1 ;
	for(int i = 0 ; i < adj[node].size() ; ++i){
		if(!vis[adj[node][i]]){
			topologicalSort(adj[node][i]);
		}
	}
	st.push(node);
}
int main() {
	for(int i = 0 ; i < (int)1e5 + 6 ; ++i)
		vis[i] = 0 ;
	int n , m  ;
	cin >> n >> m ;
	for(int i = 0 ; i < m; ++i){
		int a , b ;
		cin >> a >> b ;
		adj[a].push_back(b);
	}
	for(int i = 1 ; i <= n ; ++i ){
		if(!vis[i]){
			topologicalSort(i);
		}
	}
	while(st.size()){
		cout << st.top() <<" ";
		st.pop();
	}
	cout << endl;



	return 0;
}
