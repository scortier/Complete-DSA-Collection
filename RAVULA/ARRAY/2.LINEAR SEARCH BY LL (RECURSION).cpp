// QUARANTINE DAYS..;)
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
#define f 			    first
#define s 			    second
#define MOD 		    1000000007

void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
}
/**********====================########################=================***********/
//TC :O(N)
//SC:O(N)
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node newNode(int data)
{
	struct node temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int struct node *linearSearch_LL(struct node *head, int target)
{
	if (head) //head!=NULL
	{
		while (head)
		{
			if (head->data == target)
				return head;
			head = head->next;
		}
	}
}


int32_t main()
{
	fast();

	return 0;
}