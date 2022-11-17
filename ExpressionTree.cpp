#include "ExpressionTree.h"

using namespace std;

void ExpressionTree::addExpression(string s){
	for(int i = 0; i < s.size(); i++){

	}
}

void ExpressionTree::deleteNode(Node* node){
	if(node != nullptr){
		deleteNode(node->leftChild);
		deleteNode(node->rightChild);
		delete node;
	}
}

ExpressionTree::~ExpressionTree(){
	deleteNode(root);
}

int ExpressionTree::getSize(){
	return size;
}
