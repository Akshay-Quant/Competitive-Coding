#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> dict;
int n, m, num;
char boggle[9][9];
bool visited[9][9] = {false};

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

set<string> st;

struct trienode{
	trienode *child[60];
	bool leaf;
};

struct trienode *getnode(){
	struct trienode *node = new trienode();
	node -> leaf = false;
	for(int i = 0; i < 60; i++)
		node -> child[i] = NULL;
	return node;
}

void insert(struct trienode* root, string s){
	struct trienode* pchild = root;
	int l = s.size();
	for(int i = 0; i < l; i++){
		int index = (int)s[i] - (int)'A';
		if(pchild -> child[index] == NULL)
			pchild -> child[index] = getnode();
		pchild = pchild -> child[index];
	}
	pchild -> leaf = true;
}

bool issafe(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false)
		return true;
	return false;
}

// void printtrie(string s1, trienode* root){
// 	if(root -> leaf == true)
// 		cout << s1 << "\n";
// 	for(int i = 0; i < 60; i++){
// 		char c = 'A' + (char)i;
// 		trienode *pchild = root -> child[i];
// 		if(pchild){
// 			s1 += c;
// 			printtrie(s1, pchild);
// 			s1.erase(s1.size() - 1);
//  }
// }

void searchword(struct trienode *root, int i, int j){
	if(root -> leaf == true){
		if(st.find(s) == st.end()){
			st.insert(s);
		}
	}
	if(issafe(i, j)){
		visited[i][j] = true;
		for(int k = 0; k < 60; k++){
			if(root -> child[k] != NULL){
				char c = (char)k + 'A';
				for(int l = 0; l < 8; l++){
					if(issafe(i + row[l], j + col[l]) && boggle[i + row[l]][j + col[l]] == c){
						s += c;
						searchword(root -> child[k], i + row[l], j + col[l]);
						s.erase(s.size() - 1);
					}
				}
			}
		}
		visited[i][j] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string temp;
		cin >> num;
		getline(cin, temp);
		temp = "";
		getline(cin, temp);
		temp += " ";
		s = "";
		for(int i = 0; i < temp.size(); i++){
			if(temp[i] == ' '){
				dict.push_back(s);
				s = "";
			}else{
				s += temp[i];
			}
		}
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> boggle[i][j];
			}
		}
		trienode *root = getnode();
		for(int i = 0; i < dict.size(); i++){
			insert(root, dict[i]);
		}
		memset(visited, false, sizeof(visited));
		trienode *pchild = root;
		s = "";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int index = (int)boggle[i][j] - (int)'A';
				if(pchild -> child[index]){
					s += boggle[i][j];
					searchword(pchild -> child[index], i, j);
					s = "";
				}
			}
		}
		if(st.size() == 0)
			cout << -1;
		else{
			set<string>::iterator it;
			for(it = st.begin(); it != st.end(); it++)
				cout << *it << " ";
		}
		cout << "\n";
		dict.clear();
		st.clear();
	}
	return 0;
}
