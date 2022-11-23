#include "ExpressionTree.h"
#include <vector>
#include <string>


using namespace std;

bool ExpressionTree::isNumber(string str){
	if(str.compare("x") == 0){
		return true;
	}
	for(int i = 0; i < str.length(); i++){
		if(str[i] > 58 && 47 > str[i]){
			return false;
		}
	}
	return true;
}

void ExpressionTree::createExpressionTree(string s){
	vector<string> tokens = tokenizeExpression(s);	
	for(int i = 0; i < tokens.size();i ++){
		string currTok = tokens[i];
		Node* newNode = new Node(currTok);
		if(root == nullptr){
			root = newNode;	
		}else if(isNumber(currTok)){
			root->rightChild = newNode;
		}else{
			newNode->leftChild = root;
			root = newNode;
		}
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

vector<string> ExpressionTree::tokenizeExpression(string str){
	vector<string> output;
	string buf;
	char prev = str[0];
	buf.push_back(prev);
	for(int i = 1; i < str.size(); i++){
		if(isSameCharClass(prev, str[i])){
			buf.push_back(str[i]);
		}else{
			output.push_back(buf);
			buf.clear();
		}
		prev = str[i];
	}
	return output;
}

bool ExpressionTree::isSameCharClass(char c1, char c2){
	if(c1 >= 48 && c1 <=57){
		return (c2 >= 48 && c2<=57);
	}else{
		return false;
	}
}
