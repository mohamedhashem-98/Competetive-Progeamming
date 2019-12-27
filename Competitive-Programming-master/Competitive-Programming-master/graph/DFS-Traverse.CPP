#include<bits/stdc++.h>
using namespace std;
vector<int>adj[(int)1e5 + 6];
bool visited[(int)1e5 + 6 ];

void DFS(int start){

      printf("%d\n" , start);

      visited[start] = 1 ;

     for(int i = 0 ; i < adj[start].size() ; ++i){

        if(!visited[adj[start][i]])
            DFS(adj[start][i]);
     }

}
int main(){

   int n , m ; // n -> number of nodes  m-> number of connections

   scanf("%d%d" , &n , &m );

   for(int i = 0 ; i < m; ++i){

     int a , b ;

     scanf("%d%d" , &a , &b );

     adj[a].push_back(b);

     adj[b].push_back(a);

   }

    int start ;

    scanf("%d" , &start );

    for(int i = 0 ; i < (int)1e5 + 6 ; ++i)
        visited[i] = 0 ;

    DFS(start);


  return 0 ;
}
