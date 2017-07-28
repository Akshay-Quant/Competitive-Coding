#include <bits/stdc++.h>
using namespace std;

struct node{
	char val;
	int freq;
	node *left, *right;
	node(char data, int f){
		left = NULL;
		right = NULL;
		val = data;
		freq = f;
	}
};


struct comp{
	bool operator()(node *left, node * right){
		return left -> freq > right -> freq;
	}
};

void printcodes(node *root, string s){
	if(root == NULL)
		return;
	if(root -> val != '$')
		cout << s << " ";
	printcodes(root -> left, s + "0");
	printcodes(root -> right, s + "1");
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int fre[s.size()];
		for(int i = 0; i < s.size(); i++){
			cin >> fre[i];
		}
		priority_queue<node*, vector<node*>, comp > minheap;
		struct node *left, *right, *top;
		for(int i = 0; i < s.size(); i++)
			minheap.push(new node(s[i], fre[i]));
		while(minheap.size() != 1){
			left = minheap.top();
			minheap.pop();
			right = minheap.top();
			minheap.pop();
			top = new node('$', left -> freq + right -> freq);
			top -> left = left;
			top -> right = right;
			minheap.push(top);
		}
		printcodes(minheap.top(), "");
		cout << "\n";
	}
	return 0;
}
