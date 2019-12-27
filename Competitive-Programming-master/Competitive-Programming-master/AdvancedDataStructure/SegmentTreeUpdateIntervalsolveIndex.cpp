#include <iostream>
using namespace std;
 
int tree[33554432] , n; //2 power (log(10000000)+2)
pair<int,int> arr[100];
 
void update(int ind,int s,int e,int x,int y,int val)
{
	if(x > e || y < s) return;
	if(s >= x && e <= y)
	{
		tree[ind]+=val;
		return;
	}
	int mid = (s+e) / 2;
	update(ind*2,s,mid,x,y,val);
	update(ind*2+1,mid+1,e,x,y,val);
	return;
}
 
int solve(int ind , int s , int e , int pos)
{
	if(pos > e || pos < s) return 0;
	if(s == e && s == pos) return tree[ind];
	int mid = (s + e)/2 , left , right;
	left = solve(ind*2 , s , mid , pos);
	right = solve(ind*2+1,mid+1,e,pos);
	return tree[ind] + left + right;
}
 
int main() {

return 0;
}