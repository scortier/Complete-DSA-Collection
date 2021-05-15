int maxm(Node* node)
{
	if (node->right != NULL)
		return maxm(node->right);
	else
		return node->val;
}



int minm(Node* node)
{
	if (node->left != NULL)
		return minm(node->left);
	else
		return node->val;
}


int size(Node* node)
{
	if (node == NULL) return 0;
	int lh = size(node->left);
	int rh = size(node->right);
	return lh + rh + 1;
}

//sab nodes nhi dekhega jaha node hoga usi taraf jaega bst m
//tc : O(logn)
//while for binary tree it will be tc:O(n)
bool find(Node* node, int key)
{
	if (node == NULL)
		return false;

	if (key > node->val)
		return find(node->right, key);

	else if (key < node->val)
		return find(node->left, key);

	else	//agr data mil gya
		return true;
}


//how to add node in bst
Node add(Node* node, int key)
{
	if (node == NULL)
		return new newnode(val);

	if (key > node->val)
	{
		// add(node->right);
		//upar wali line glt hai as pichle node se connect bhi toh karna hai nae node ko so data retrieve karna padega
		node->right = add(node->right);
	}
	else if (key < node->val)
	{
		// add(node->left);
//upar wali line glt hai as pichle node se connect bhi toh karna hai nae node ko so data retrieve karna padega
		//parent se attach bhi toh karna haina tph usse pehle receive bhi toh karna padega na
		node->left = add(node->left);
	}
	else //do nothing
	{}

	return node;
}



/*how to remove node from bst
3 cases to handle node having
1. 0 child
2. 1 child
3. 2 child

1. 0 child :- sidhe node ko remove kardo no tension
2. 1 child :- node ke eklaute child ko node ke parent se connect kardo remove karne k baad
3. 2 child :-  node k left side ka max nikalo aur node se replace kardo and left max ko remove kardo (to maintain bst property)

*/

Node remove(Node* node, int key)
{

	if (key > node->right)
		node->right = remove(node->right);

	else if (key < node->left)
		node->left = remove(node->left);

	else
	{
		//work
		//case of 2 child
//why we choose left_max why not any other node
//becoz it will satisy bst condn such as left wale node se chote rhenge and right wale ndoe se bade
		if (node->left != NULL and node->right != NULL)
		{
			int left_max = maxm(node->left);
			node->data = left_max; //
			node->left = remove(node->left, left_max); //left se left max node hata do as data toh pehle hi hat gya
			return node;
		}
		//case of one child with left child
		else if (node->left != NULL)
		{
			return node->left;
		}
		//case of one child with right child
		else if (node->right != NULL)
		{
			return node->right;
		}
		//agr koi child nhi hai toh node ko null se reeplace kardo.
		else
		{
			return NULL;
		}
	}
	return node;
}




// Replace Sum of Larger in BST
/*
https://www.youtube.com/watch?v=MLff3CxNVTc&list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2&index=10

Using REVERSE INORDER TRAVERSAL
- sum=0
- put node val in sum and update node val with prev sum val.
- continue doing above in rve inorder
*/

int sum = 0;
Node rsl_bst(Node* node)
{
	if (root == NULL) return;

	rsl_bst(node->right);

	//work
	int original_node_value = node->val;
	node->val = sum;
	sum += original_node_value ;

	rsl_bst(node->left);
}




//LCA OF BST
/*
node to root path dekho dono node ka aur jo niche se sabse pehle common point ae vo LCA hai.


*/
int LCA(Node* node, int d1, int d2)
{
	if (d1 > node->val and d2 > node->val)
		return LCA(node->right, d1, d2);

	else if (d1 < node->val and d2 < node->val)
		return LCA(node->left, d1, d2);

	//mtlb node ek se chota hai aur ek se bada hai and yhi toh LCA hota hia
	else
	{
		return node->val;
	}

}


//Print in range in BST
/*
27 -> 72
now print nodes bw these 2 no in increasing order inclusive of both numbers.

ab dekho jese hi increasing suna ...INORDER dimag m aan jana chahiye

and 3 number k comparison m humesha sirf 3 case hote h
	<------>	d1  <----->   d2   <------>
	node dono se chota hoga
	node dono se bada hoga
	node dono k bich m hoga
*/

int PIR_BST(Node* node, int d1, int d2)
{
	if (root == NULL) return;
	// node dono se chota hoga
	if (d1 < node->val and d2 < node->val)
	{
		return PIR_BST(node->left, d1, d2);
	}
	//node dono se bada hai
	else if (d1 > node->val and d2 > node->val)
	{
		return PIR_BST(node->right, d1, d2);
	}
	//node bich m hai
	else
	{
		//work - yhi toh chahiye
		//ab left right dono jgh baari baari visit karoge
		PIR_BST(node->left, d1, d2);
		cout << node->val << " ";
		PIR_BST(node->right, d1, d2);
	}
}



//TARGET SUM PAIR IN BST
/*
Find two node whose sum is equal to given target and print in increasing order
ex : target =100
25-75
30-70
40-60
ab dekho fir inccreasing aya inorder zindabad
*/
//TC :O(N*height)=O(nlogn)
//SC:O(H) //HEIGHT SE GEHRI RECURSION CALL HO HI NHI SAKTI
bool find(Node* node, int key)
{
	//base case
	if (node == NULL)
		return false;

	if (node->val > key)
	{
		return find(node->left, key);
	}
	else if (node->val < key)
		return find(node->right, key);

	else//MIL GYI
		return true;
}

void TSP_in_BST(Node* root, Node* node, int target)
{
	if (node == NULL) return ;

	TSP_in_BST(root, node->left, target);

	int complement = target - node > val;
	if (node->val < complement)
	{
		if (find(root, complement) == true)
			cout << node->val + " " + complement;
	}

	TSP_in_BST(root, node->right, target);
}
//alternative way of target sum pair

// bst ko array m bharke laenge aur traverse karenge using 2 pointer from corners
// TC: O(N)+O(N)
// SC:O(N)
vector<int>res;
void target_sum(Node* node)
{
	target_sum(node->left);
	res.push_back(node->val);
	target_sum(node->right);
}

void main()
{
	int target;
	int l = 0;
	int r = res.size() - 1;
	while (l < r) {
		target_sum(root);

		if (l + r < target)
		{
			l++;
		}
		else if (l + r > target)
		{
			r--;
		}
		else
		{
			cout << l << "+" << " " << "+" << r << endl;
			l++;
			r--;
		}
	}
}