#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int>computePrefix(string pat){
    int m = pat.size();
   vector<int>longestprefix(m);
   for(int i = 1 , k = 0 ; i < m ; ++i){
       while(k > 0 && pat[k] != pat[i])
        k = longestprefix[k-1];
       if(pat[k] == pat[i])
        longestprefix[i] = ++k;
       else
        longestprefix[i] = k;
   }
   return longestprefix;
}
void KMP(string str , string pat){
   int n = str.size();
   int m = pat.size();
   vector<int>longestprefix = computePrefix(pat);
   for(int i = 0 , k = 0 ; i < n; ++i){
    while(k > 0 && pat[k] != str[i])
        k = longestprefix[k-1];
    if(pat[k] == str[i])
        k++;
    if(k == m){
        cout << i - m + 1 <<endl;
        k = longestprefix[k-1];
    }
   }
}
int main(){
   IO


   return 0 ;
}
