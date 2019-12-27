#include<bits/stdc++.h>
using namespace std;

int parent[(int)1e5 + 6 ];
int Rank[(int)1e5 + 6 ];

void DSU(){

   for(int i = 0 ; i < (int)1e5 + 6 ; ++i)
      parent[i] = i;                       // Make every node parent to itself
   for(int i = 0 ; i < (int)1e5 + 6 ; ++i)
      Rank[i] = 0 ;                        // Make Rank of every node equal zero
}

int findparent(int cur){
   if(parent[cur] == cur)return cur;
   return parent[cur] = findparent(parent[cur]); // Find parent of node
}

void connect(int first , int second){
   int F = findparent(first);
   int S = findparent(second);
      if(Rank[F] > Rank[S]){
        parent[S] = F;
      }                                 //If the two nodes not connected : connect them
      else if(Rank[F] < Rank[S]){
        parent[F] = S;
      }
      else{
        parent[S] = F;
        Rank[F]++;
      }
}

bool Isconnected(int first , int second){
  if(findparent(first) == findparent(second))return true; // Check if the two nodes connected or not
  return false;
}

int main(){

    DSU();
    int n , m ; // n -> number of nodes .    m -> number of connections .
    scanf( "%d%d" , &n , &m );
    for(int i = 0 ; i < m ; ++i ){

        int a , b ; // a -> First   b -> second
        scanf( "%d%d" , &a , &b );
        if(!Isconnected(a , b )){
            connect(a , b);
        }
    }


  return 0 ;
}
