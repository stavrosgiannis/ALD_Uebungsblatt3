#ifndef ALDSEARCHTREE_TREE_H
#define ALDSEARCHTREE_TREE_H
#include <stddef.h>

class Node {
public:
	Node(int val);
	int value;
	Node* right;
	Node* left;
	Node* parent;
};
class searchTree {
private:
	struct Trunk;
	void showTrunks(Trunk* p);
public:
	Node* root;
	searchTree();
	void destroy_tree(Node* n);
	void insertNode(Node*& n, int val);
	void printTree(Node* n, Trunk* prev, bool isLeft);
	bool containsNode(Node* n, int val);
	void inOrder(Node* n);
};
#endif //ALDSEARCHTREE_TREE_H