#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* constructCore(vector<int> pre, vector<int> vin, int start_pre, int end_pre, int start_vin, int end_vin){
		TreeNode* root = new TreeNode(pre[start_pre]);
        //递归结束条件
		if (start_pre == end_pre) {
			if (start_vin == end_vin && pre[start_pre] == vin[start_pre]){
				return root;
			}
		}
		int left_tmp = -1;
		for (int i = start_vin; i <= end_vin; i++){
			if (vin[i] == pre[start_pre]){
			    left_tmp = i;
				break;
			}
		}
		//前序遍历序列与中序遍历序列不匹配
		if (left_tmp == -1){
			cout <<"Invalid input Error 2." << endl;
			throw exception("Invalid input Error 2.");
		}
	    int left_length = left_tmp - start_vin;
		if(left_length >0){
		root->left = constructCore(pre,vin,start_pre+1,start_pre + left_length,start_vin,left_tmp-1);
		}
		if(left_length < end_pre - start_pre){
		root->right = constructCore(pre,vin,start_pre+left_length+1,end_pre,left_tmp+1,end_vin);
		}

		return root;
	}
	TreeNode* constructCore2(vector<int> pre, vector<int> vin, int start_pre, int end_pre, int start_vin, int end_vin){
		TreeNode* root = new TreeNode(pre[start_pre]);
		if (start_pre >= end_pre || start_vin >= end_vin){
			return NULL;
		}
		int count = 0;
		for (int i = start_vin; i <= end_vin; i++){
			count++; 
			if (vin[i] == pre[start_pre]){
				root->left = constructCore(pre, vin, start_pre + 1, start_pre + i - start_vin, start_vin, i - 1);
				root->right = constructCore(pre, vin, start_pre + i - start_vin + 1, end_pre, i + 1, end_vin);
				break;
			}
			
		}
        //前序遍历序列与中序遍历序列不匹配
		if (count == (end_vin - start_vin + 1)){
			cout << "Invalid input Error 2." << endl;
			throw exception("Invalid input Error 2.");
		}


		return root;
	}


	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() <= 0 || vin.size() <= 0){
			cout << "Invalid input Error 0." << endl;
			throw exception("Invalid input Error 0.");
			//return NULL;
		}
		return constructCore(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
	}

	//宽度优先
	void printTree(TreeNode* root){
		queue<TreeNode*> node;
		node.push(root);
		while (!node.empty()){
			TreeNode* tmp = node.front();
			cout << tmp->val << "  ";
			node.pop();
			if (tmp->left != NULL) node.push(tmp->left);
			if (tmp->right != NULL) node.push(tmp->right);
		}
	}

};

//=====================测试代码===================
// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1(){
	vector<int> preList = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> midList = { 4, 7, 2, 1, 5, 3, 8, 6 };
	Solution cs;
	TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	cout << "Test1:" << endl;
	cs.printTree(result);
}
// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2(){
	vector<int> preList = { 1, 2, 3, 4, 5 };
	vector<int> midList = { 5, 4, 3, 2, 1 };
	Solution cs;
	TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	cout << "Test2:" << endl;
	cs.printTree(result);

}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3(){
	vector<int> preList = { 1, 2, 3, 4, 5 };
	vector<int> midList = { 1, 2, 3, 4, 5 };
	Solution cs;
	TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	cout << "Test3:" << endl;
	cs.printTree(result);
}

// 树中只有一个结点
void Test4(){
	vector<int> preList = { 1 };
	vector<int> midList = { 1 };
	Solution cs;
	TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	cout << "Test4:" << endl;
	cs.printTree(result);
}
// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5(){
	vector<int> preList = { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> midList = { 4, 2, 5, 1, 6, 3, 7 };
	Solution cs;
	TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	cout << "Test5:" << endl;
	cs.printTree(result);
}
// 输入空指针
void Test6()
{
	vector<int> preList = {};
	vector<int> midList = {};
	Solution cs;
	TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	cout << "Test6:" << endl;
	cs.printTree(result);
}
// 输入的两个序列不匹配
void Test7(){
	vector<int> preList = { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> midList = { 4, 2, 8, 1, 6, 3, 7 };
	Solution cs;
	TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	cout << "Test7:" << endl;
	cs.printTree(result);
}
void Test8(){
	vector<int> preList = { 1, 2, 4, 3, 5, 6 };
	vector<int> midList = { 4, 2, 1, 5, 3, 6 };
	Solution cs;
	TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	cout << "Test8:" << endl;
	cs.printTree(result);
}






int main() {
	//cout << "hello " << endl;
	//vector<int> preList = { 1, 2, 4, 3, 5, 6 };
	//vector<int> midList = { 4, 2, 1, 5, 3, 6 };
	///*vector<int> preList = {1,2,3,4,5,6};
	//vector<int> midList = {1,2,3,4,5,6};*/
	//Solution cs;
	//cout << "in" << endl;
	//TreeNode* result = cs.reConstructBinaryTree(preList, midList);
	//cout << "out" << endl;
	//cs.printTree(result);

	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	return 0;
}
