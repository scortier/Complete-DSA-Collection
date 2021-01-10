// QUARANTINE DAYS..;)
//image is made up of pixels(box) so tis like ek block ko bhara aur vo continue row
//ya column ko fill karta rahega jab tak koi restriction na ho.
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    long long int tt;cin>>tt;while(tt--)
#define rep(i,a,b)      for(long long int i=a;i<b;i++)
#define rev(i,a,b)      for(long long int i=b-1;i>=a;i--)
#define reep(i,a,b)     for(long long int i=a;i<=b;i++)
#define ll 			    long long int
#define pb 			    push_back
#define mp 			    make_pair
#define fi 			    first
#define se 			    second
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define prec(val, dig)  fixed << setprecision(dig) << val
#define vec(vct) 	    vector < ll > vct
#define vecpi(vct) 	    vector < pair < ll, ll > > vct
#define pi 			    pair < ll , ll >
#define lower(str) 		transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) 		transform(str.begin(), str.end(), str.begin(), ::toupper);
#define mk(arr,n,type)  type *arr=new type[n];
const int maxm = 2e6 + 10;

void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/
int r, c;

void print(char mat[][50]) {
	rep(i, 0, r) {
		rep(j, 0, c) {
			cout << mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
//Recursion=DFS
//'.' is replaced by 'R' ie Red.
void floofill(char mat[][50], int i, int j, char ch, char color) //konse cell p color drop karna hai and konse char ko replace krna hai.
{
//base case - boundary & matrix k andar rehna hai
//and agr . k alawa koi bhi operator aya toh matrix k anadar return hona hai.
	if (i < 0 || j < 0 || i >= r || j >= c || mat[i][j] != ch)
		return; //vha p color fill nhi karna hai

	mat [i][j] = color; //on right cell color filling
//then call on neighbouring cell
//call to fill the color on neighbouring cells
	floofill(mat, i + 1, j, ch, color);
	floofill(mat, i, j + 1, ch, color);
	floofill(mat, i - 1, j, ch, color);
	floofill(mat, i, j - 1, ch, color);

}
int32_t main()
{
	fast();
	char mat[50][50];
	cin >> r >> c;

	rep(i, 0, r) {
		rep(j, 0, c) {
			cin >> mat[i][j];
		}
	}

	print(mat);
	floofill(mat, 8, 13, '.', 'R');
	print(mat);

	return 0;
}