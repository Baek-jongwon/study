#include <iostream>

#define MAX 100001
using namespace std;

int inorder[MAX];
int postorder[MAX];
int index[MAX];


void preorder(int in_start, int in_end, int po_start, int po_end)
{

	if (in_start > in_end || po_start > po_end) return;

	int root = index[postorder[po_end]];
	int left_size = root - in_start;
	int right_size = in_end - root;

	cout << inorder[root] << " ";

	preorder(in_start, root - 1, po_start, po_start + left_size - 1);
	preorder(root + 1, in_end, po_start + left_size, po_end - 1);

}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> inorder[i];
		index[inorder[i]] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> postorder[i];
	}

	preorder(1, n, 1, n);
}