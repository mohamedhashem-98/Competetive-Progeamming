#include <bits/stdc++.h>
using namespace std;
long long tree[(int)1e6 + 5];
void update(int indx , int s , int e , int pos , int val){
      if(pos < s || pos > e)
        return ;
      if(s == e && s == pos){
         tree[ind] = val;
         return;
      }
      int mid = (s + e) / 2 ;
      update(indx * 2 , s , mid , pos , val);
      update(indx * 2 + 1 , mid+1 , e , pos , val);
      tree[indx] = tree[indx * 2] + tree[indx * 2 + 1];
      return ;
}
long long Solve(int indx , int s , int e , int l , int r){
      if(s >= l && e <= r)
        return tree[indx];
      if(s > r || e < l)
        return 0 ;
      int mid = (s + e) / 2 ;
      int left , right;
      left = Solve(indx * 2 , s , mid , l , r);
      right = Solve(indx * 2 + 1 , mid+ 1 , e , l , r);
      return left + right;
}
int main()
{

    return 0;
}
