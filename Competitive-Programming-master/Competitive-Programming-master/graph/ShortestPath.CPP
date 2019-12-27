#include<bits/stdc++.h>
using namespace std;

 class node{
     public:
        int nxt , cost ;

        node(int nxt , int cost){
          this->nxt = nxt ;
          this->cost = cost ;
        }
};

vector<node>adj[(int)1e5 + 6 ];  // adjacency list
int Cost[(int)1e5 + 6 ];
const int INF = (int)1e9 ;

 bool operator < ( node a , node b){                   // Function compare to sort in priority queue in low cost
    if( a.cost != b.cost )return a.cost > b.cost ;
    return a.nxt < b.nxt ;
 }
int ShortestPath(int Source , int Destination ){

    priority_queue< node > que;

    que.push( node( Source , 0 ));

    for(int i = 0 ; i < (int) 1e5 + 6 ; ++i)
        Cost[i] = INF;

    while( que.size() ){

        node cur = que.top() ;
        que.pop() ;

        for(int i = 0 ; i < adj[cur.nxt].size() ; ++i){

            if(adj[cur.nxt][i].cost + cur.cost < Cost[adj[cur.nxt][i].nxt]){

                   Cost[adj[cur.nxt][i].nxt] = adj[cur.nxt][i].cost + cur.cost;

                   que.push( node(adj[cur.nxt][i].nxt , adj[cur.nxt][i].cost + cur.cost ));
                }
            }

      }

      return Cost[Destination];

}

int main(){

    int n , m ; // n -> number of nodes    m -> number of connections

    scanf( "%d%d" , &n , &m );

    for(int i = 0 ; i < m; ++i){

        int a , b , cst ; // a -> node  b -> node   cst -> cost

        scanf("%d%d%d" , &a , &b , &cst );

        adj[a].push_back( node(b , cst));

        adj[b].push_back( node(a , cst));
    }

     int Source , Destination ;

     scanf("%d%d" , &Source , &Destination );

    printf("%d" , ShortestPath(Source , Destination));


  return 0 ;
}
