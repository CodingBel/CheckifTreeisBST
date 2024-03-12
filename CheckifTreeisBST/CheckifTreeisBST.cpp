// This program is used to check if a given TREE is a true BST
// It also prints the Tree's nodes in an Inorder Traversal 

#include<iostream> 
class Node {
public:
	int data{};
	Node* left{};
	Node* right{};
};

Node* newNode(int data) {
	Node* theNewNode = new (Node);
	theNewNode->data = data;
	theNewNode->left = nullptr;
	theNewNode->right = nullptr;

	return theNewNode;
}

int maxValue(Node* node) {
	if (node == nullptr)
		return INT32_MIN;

	int value = node->data;
	int left = maxValue(node->left);
	int right = maxValue(node->right);

	return std::max(value, std::max(left, right));
}

int minValue(Node* node) {
	if (node == nullptr)
		return INT32_MAX;

	int value = node->data;
	int left = minValue(node->left);
	int right = minValue(node->right);

	return std::min(value, std::min(left, right));
}

int isTreeBST(Node* node) {
	if (node == nullptr)
		return 1;

	if (node->left != nullptr && maxValue(node->left) >= node->data)
		return 0;

	if (node->right != nullptr && minValue(node->right) <= node->data)
		return 0;

	if (!isTreeBST(node->left) || !isTreeBST(node->right))
		return 0;

	return 1;
}

void printTree(Node* node) {
	if (node == nullptr)
		return;

	printTree(node->left);
	std::cout << node->data << " ";
	printTree(node->right);
}

int main() {
	Node* root = newNode(8);
	root->left = newNode(5);
	root->right = newNode(10);

	root->left->left = newNode(3);
	root->left->right = newNode(6);

	root->right->left = newNode(9);
	root->right->right = newNode(11);


	printTree(root);
	std::cout << "\n\n";

	std::cout << isTreeBST(root);
	return 0;
}