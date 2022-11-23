#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class ExpressionTree{
	public:
		class Node{
			public:
				Node* leftChild;
				Node* rightChild;
				Node* parent;
				string expression;
				Node(string var) : leftChild(nullptr), rightChild(nullptr), parent(nullptr), expression(var) {}
		};
	void createExpressionTree(string s);
	int getSize();
	void simplify();
	~ExpressionTree();
	ExpressionTree(){}
	private:
		Node* root;
		int size;
		void balanceTree(Node* unbalancedNode);
		void deleteNode(Node* node);
		unordered_map<Node*, int> calcBalanceFactors();
		vector<string> tokenizeExpression(string str);
		bool isSameCharClass(char c1, char c2);
		bool isNumber(string str);
};
