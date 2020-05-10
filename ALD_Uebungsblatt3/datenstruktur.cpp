#include <iostream>
#include <string>
#include "datenstruktur.h"

Node::Node(int val) {
	value = val;
	right = nullptr;
	left = nullptr;
	parent = nullptr;
}

searchTree::searchTree() {
	root = nullptr;
}
void searchTree::insertNode(Node*& n, int val) {
	if (n == nullptr) {
		n = new Node(val);
		return;
	}
	else if (val < n->value)
	{
		if (n->left != nullptr)
			insertNode(n->left, val);
		else
		{
			n->left = new Node(val);
		}
	}
	else if (val >= n->value)
	{
		if (n->right != nullptr)
			insertNode(n->right, val);
		else
		{
			n->right = new Node(val);
		}
	}
}

void searchTree::destroy_tree(Node* n)
{
	if (n != NULL)
	{
		destroy_tree(n->left);
		destroy_tree(n->right);
		delete n;
	}
}

bool searchTree::containsNode(Node* n, int val) {
	if (n == nullptr) {
		return false;
	}
	else if (val == n->value)
		return true;
	else if (val < n->value)
		return containsNode(n->left, val);
	else return containsNode(n->right, val);
}

void searchTree::inOrder(Node* n) {
	if (n == nullptr) {
		return;
	}

	inOrder(n->left);
	std::cout << n->value << std::endl;
	inOrder(n->right);
}

struct searchTree::Trunk
{
	Trunk* prev;
	std::string str;

	Trunk(Trunk* prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

// Helper function to print branches of the binary tree
void searchTree::showTrunks(Trunk* p)
{
	if (p == nullptr)
		return;

	showTrunks(p->prev);

	std::cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void searchTree::printTree(Node* n, Trunk* prev, bool isLeft)
{
	if (n == nullptr)
		return;

	std::string prev_str = "    ";
	Trunk* trunk = new Trunk(prev, prev_str);

	printTree(n->left, trunk, true);

	if (!prev)
		trunk->str = "---";
	else if (isLeft)
	{
		trunk->str = ".---";
		prev_str = "   |";
	}
	else
	{
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	std::cout << n->value << std::endl;

	if (prev)
		prev->str = prev_str;
	trunk->str = "   |";

	printTree(n->right, trunk, false);
}