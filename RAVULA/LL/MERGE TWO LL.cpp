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

struct node {
	int data;
	struct node*left;
	struct node*right;
};

struct node *newnode(int data)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

struct node*merge(struct node*list1, struct node*list2)
{
	struct node *mergelist = (struct node*)malloc(sizeof(struct node));
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if (list1->data <= list2->data)
	{
		merge = list1;;
		list1 = list1->next;
	}
	else
	{
		mergelist = list2;
		list2 = list2->next;
	}
	temp = mergelist;
	while (list1 && list2)
	{
		if (list1->data <= list2->data)
		{
			temp->next = list1;
			temp = temp->next;
			list1 = list1->next;
		}
		else {
			temp->next = list2;
			temp = temp->next;
			list2 = list2->next;
		}
	}
	if (!list1)
		temp->next = list2;
	else
		temp->next = list1;
	return mergelist;

}


int32_t main()
{
	fast();

	return 0;
}