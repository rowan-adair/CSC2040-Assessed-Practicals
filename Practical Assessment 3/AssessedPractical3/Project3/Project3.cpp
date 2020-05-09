#include <iostream>
#include <ctime>
#include "TreeNode.h"

using namespace std;


TreeNode<int>* BST() {
	//            409     
	//	  168             623
	// 41     321     511     814 
	TreeNode<int>* tree = new TreeNode<int>(409,
		new TreeNode<int>(168,
			new TreeNode<int>(41),
			new TreeNode<int>(321)
			),
		new TreeNode <int>(623,
			new TreeNode<int>(511),
			new TreeNode<int>(814)
			)
		);
	return tree;
}

bool searchBST(TreeNode<int>* tree, int key) {
	if (!tree) 
		return false;
	if (tree->item == key) 
		return true;
	if (key < tree->item)
		return searchBST(tree->left, key);
	else
		return searchBST(tree->right, key);
}

int main(){
	TreeNode<int>* tree = BST();
	
	cout << searchBST(tree, 41) << endl;
	cout << searchBST(tree, 168) << endl;
	cout << searchBST(tree, 321) << endl;
	cout << searchBST(tree, 409) << endl;
	cout << searchBST(tree, 511) << endl;
	cout << searchBST(tree, 623) << endl;
	cout << searchBST(tree, 814) << endl;
	cout << searchBST(tree, 6) << endl;
	cout << searchBST(tree, 900) << endl;
	return 0;
}

