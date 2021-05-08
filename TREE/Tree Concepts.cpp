void leaf(Node* root)
{
	if (root == NULL) / if (!root) return;
	if (!root->left and !root->left) {}
	//required code either add root->val or print it
	leaf(root->left);
	leaf(root->right);

}