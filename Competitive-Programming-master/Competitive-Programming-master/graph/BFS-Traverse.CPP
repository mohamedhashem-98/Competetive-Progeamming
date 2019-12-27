#include<bits/stdc++.h>
using namespace std;
vector<int>adj[(int)1e5 + 6];
bool visited[(int)1e5 + 6 ];

void BFS(int start){

   for(int i = 0 ; i < (int)1e5 + 6 ; ++i )
     visited[i] = 0 ;

   queue< int > que;

    que.push(start);

   while( que.size() ){

      int cur = que.front();

      que.pop();

      visited[cur] = 1;

      for(int i = 0 ; i < adj[cur].size() ; ++i ){

          if( !visited[adj[cur][i]]){

            printf( "%d\n" , adj[cur][i] );

            que.push( adj[cur][i] );
          }
      }

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

    BFS(start);


  return 0 ;
}
