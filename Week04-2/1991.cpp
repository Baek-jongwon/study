#include <iostream>

using namespace std;

struct node {
	node* left;
	node* right;
	char value;
};
node *nodes;


void preorder(node *nd)
{
	cout << nd->value;
	if (nd->left != NULL) preorder(nd->left);
	if (nd->right) preorder(nd->right);
}

void inorder(node *nd)
{
	if (nd->left) inorder(nd->left);
	cout << nd->value;
	if (nd->right) inorder(nd->right);
}
void postorder(node *nd)
{
	if (nd->left) postorder(nd->left);
	if (nd->right) postorder(nd->right);
	cout << nd->value;
}



int main()
{
	int n;
	cin >> n;
	nodes = (node*)malloc(sizeof(node)*n);	

	for (int i = 0; i < n; i++)
	{
		int idx;
		char root, l, r;

		cin >> root >> l >> r;
		idx = root - 'A';
		
		nodes[idx].value = root;
		
		if (l == '.')
		{
			nodes[idx].left = NULL;
		}
		else
		{
			nodes[idx].left = &nodes[l - 'A']; 
		}

		if (r == '.')
		{
			nodes[idx].right = NULL;
		}

		else
		{
			nodes[idx].right = &nodes[r - 'A'];
		}
	}
	
	
	preorder(&nodes[0]);
	cout << "\n";
	inorder(&nodes[0]);
	cout << "\n";
	postorder(&nodes[0]);
	cout << "\n";

	
	free(nodes);

}
