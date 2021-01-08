#include <iostream>
#include <string>
#include <queue>

using namespace std;
queue<string> q;
struct tree {
	string key;
	tree* left; // 왼쪽 자식
	tree* right;  // 오른쪽 자식
};
tree* init(tree* node, string data) {
	node = new tree();
	node->key = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
tree* insert(tree* node, string data) { // 탐색 노드, 현재 노드의 부모
	// 이진 트리는 현재 노드의 key값보다 data가 작으면 왼쪽 노드로
	// 그렇지 않으면 오른쪽 노드로 
	// 현재 노드가 NULL 이라면, 즉 데이터가 들어갈 자리
	if (node == NULL) {
		tree* new_node = NULL;
		new_node = init(new_node, data);
		return new_node;
	}
	// 루트에 데이터가 들어간 상태며 , 현재 노드의 key값과 data 비교
	if (node->key < data) { // 들어갈 데이터가 크므로 오른쪽 자식으로 삽입
		// 만약 node->right가 NULL 인 상태에서는 메모리 할당이 안되어있음
		node->right = insert(node->right, data);
	}
	else if (node->key == data) { // 중복 데이터
		return node;
	}
	else { // 반대
		node->left = insert(node->left, data);
	}
	return node;
}

void search_leaf(tree* node) { // leaf 노드
	if (node == NULL) {
		return;
	} // preorder
	if (node->left == NULL && node->right == NULL) {
		//cout << node->key << " ";
		q.push(node->key+" ");
		return;
	}
	// 왼쪽 부터
	search_leaf(node->left); // NULL
	search_leaf(node->right);
}
void search_leaf(tree* node,int k, int depth) { //  depth = k 인
	if (node == NULL) {
		return;
	}
	if (depth == k) {
		q.push(node->key + " ");
		//cout << node->key << " ";
		return;
	}
	// 왼쪽 부터
	search_leaf(node->left, k, depth + 1);
	search_leaf(node->right, k, depth + 1);
}
tree* remove(tree* node, string key) {
	//cout << node->key << " " << node->key << "\n";
	if (node == NULL) {
		return node;
	}
	if (node->key > key) { // 노드의 키값이 더 크면  왼쪽으로
		node->left = remove(node->left, key);
	}
	else if (node->key < key) {// 노드의 키값이 더 작으면 오른쪽
		node->right = remove(node->right, key);
	}
	else { // 같은 경우 ( 지워야할 노드르 찾은 경우 )
		if(node->left != NULL) { // 왼쪽 노드가 있는 경우
			tree* cur = node->left; // 왼쪽의 최대를 찾음
			while (cur->right != NULL) {
				cur = cur->right;
			}
			// cur = 왼쪽 자식의 최대 key를 갖는 자식 
			node->key = cur->key;
			// 키 업데이트
			node->left = remove(node->left, cur->key); // 왼쪽 자식중에서 해당 key를 갖는 노드 삭제
			// node 위치로 cur 이 옮겨졌으므로 cur 노드를 찾아서 삭제
		}
		else if (node->right != NULL) { // 오른쪽 노드만 존재하는 경우
			tree* cur = node->right; // 오른쪽의 최소를 찾음
			while (cur->left != NULL) {
				cur = cur->left;
			}
			// cur = 왼쪽 자식의 최대 key를 갖는 자식 
			node->key = cur->key;
			// 키 업데이트
			node->right = remove(node->right, cur->key); // 왼쪽 자식중에서 해당 key를 갖는 노드 삭제
			//// node 위치로 cur 이 옮겨졌으므로 cur 노드를 찾아서 삭제
		}		
		else { // 양쪽 모두 없는 경우
			node = NULL;
		}
	}
	return node;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n; // 명령어 개수
	cin >> n;

	// 트리의 루트를 먼저 선언
	tree* root = NULL;

	for (int i = 0; i < n; i++) { 
		string com;
		cin >> com;
		if (com == "+") { // 트리에 string 타입의 key 를 넣음
			string data; // 집어 넣을 key값 (data)
			cin >> data;
			root = insert(root, data);
		}
		else if (com == "-") {
			string data;
			cin >> data;
			root = remove(root, data);
		}
		else if (com == "leaf") { // 자식이 없는 트리를 왼쪽부터 출력
			search_leaf(root);
			q.push("\n");
			//cout << "\n";
		}
		else if (com == "depth") {
			int k;
			cin >> k;
			search_leaf(root, k, 1);
			//cout <<"\n";
			q.push("\n");
		}
	}
	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}
}