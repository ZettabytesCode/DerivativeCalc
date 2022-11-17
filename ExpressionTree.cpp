#include "ExpressionTree.h"

using namespace std;

void ExpressionTree::addExpression(string s){

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
