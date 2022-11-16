#include <vector>
#include <string>
using namespace std;

class ExpressionTree{
	private:
		Node* root;
		int size;
		void balanceTree();
	public:
		class Node{
			public:
				Node* leftChild;
				Node* rightChild;
				Node* parent;
				char expression;
				Node(char var) : leftChild(nullptr), rightChild(nullptr), parent(nullptr), expression(var) {}
		}

	void addExpression(string s);
};
