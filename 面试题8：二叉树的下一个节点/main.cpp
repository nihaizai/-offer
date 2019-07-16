#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode){
	if (pNode->right != NULL){
		TreeLinkNode* tmp = pNode->right;
		while (tmp->left != NULL){
			tmp = tmp->left;
		}
		return tmp;
	}
	else{
		if (pNode->next != NULL){
			if (pNode->next->left == pNode){
				return pNode->next;
			}
			else{
				TreeLinkNode* tmp = pNode->next;
				while (tmp->next != NULL && tmp->next->right == tmp){
					tmp = tmp->next;
				}
				if (tmp->next == NULL){
					return NULL;
				}
				else{
					return tmp->next;
				}
			}
		}
		return NULL;
	}

}

//边连接
void ConnectTreeNodes(TreeLinkNode* pParent, TreeLinkNode* pLeft, TreeLinkNode* pRight){
	if (pParent != NULL){
		pParent->left = pLeft;
		pParent->right = pRight;
		if (pLeft != NULL){
			pLeft->next = pParent;
		}
		if (pRight != NULL){
			pRight->next = pParent;
		}
	}
}

//打印Node信息
void PrintTreeNode(TreeLinkNode* pNode){
	if (pNode != NULL){
		cout<<pNode->val<<"  ";
		if (pNode->left != NULL){
			cout << pNode->left->val << "  ";
		}
		if (pNode->right != NULL){
			cout << pNode->right->val << "  ";
		}
	}
	cout << endl;
}

//打印树
void PrintTree(TreeLinkNode* pRoot){
	PrintTreeNode(pRoot);
	if (pRoot != NULL){
		if (pRoot->left != NULL){
			PrintTree(pRoot->left);
		}
		if (pRoot->right != NULL){
			PrintTree(pRoot->right);
		}
	}
}

//销毁树
void DestoryTree(TreeLinkNode* pRoot){
	if (pRoot != NULL){
		TreeLinkNode* pLeft = pRoot->left;
		TreeLinkNode* pRight = pRoot->right;

		pRoot->val = 0;
		delete pRoot;
		pRoot = NULL;
		DestoryTree(pLeft);
		DestoryTree(pRight);
	}
}
//测试
void Test(string testName, TreeLinkNode* pNode, TreeLinkNode* pRNode){
	if (!testName.empty()){
		cout << testName.c_str() << "  ";
	}
	TreeLinkNode* pResult = GetNext(pNode);
	if (pResult == pRNode){
		cout << "Passed." << endl;
	}
	else{
		cout << "Failed." << endl;
	}

}
//      8
// 6       10
//5 7     9  11
void Test1(){
	TreeLinkNode node5 = TreeLinkNode(5);
	TreeLinkNode node7 = TreeLinkNode(7);
	TreeLinkNode node9 = TreeLinkNode(9);
	TreeLinkNode node11 = TreeLinkNode(11);
	TreeLinkNode node6 = TreeLinkNode(6);
	TreeLinkNode node10 = TreeLinkNode(10);
	TreeLinkNode node8 = TreeLinkNode(8);
	
	ConnectTreeNodes(&node8,&node6,&node10);
	ConnectTreeNodes(&node6, &node5, &node7);
	ConnectTreeNodes(&node10, &node9, &node11);

	//PrintTree(&node8);
	Test("test1",&node5,&node6);
	Test("test2", &node6, &node7);
	Test("test3", &node7, &node8);
	Test("test4", &node8, &node9);
	Test("test5", &node9, &node10);
	Test("test6", &node10, &node11);
	Test("test7", &node11, NULL);

	//DestoryTree(&node8);

}

   //            5
   //          4
			//3
		 //  2
void Test2(){
	TreeLinkNode node5 = TreeLinkNode(5);
	TreeLinkNode node4 = TreeLinkNode(4);
	TreeLinkNode node3 = TreeLinkNode(3);
	TreeLinkNode node2 = TreeLinkNode(2);

	ConnectTreeNodes(&node5, &node4,NULL);
	ConnectTreeNodes(&node4, &node3,NULL);
	ConnectTreeNodes(&node3, &node2,NULL);

	Test("test8", &node2, &node3);
	Test("test9", &node3, &node4);
	Test("test10", &node4, &node5);
	Test("test11", &node5,NULL);


}



//            2
//                3
//                    4
//                        5
void Test3(){
	TreeLinkNode node5 = TreeLinkNode(5);
	TreeLinkNode node4 = TreeLinkNode(4);
	TreeLinkNode node3 = TreeLinkNode(3);
	TreeLinkNode node2 = TreeLinkNode(2);

	ConnectTreeNodes(&node2, NULL, &node3);
	ConnectTreeNodes(&node3, NULL, &node4);
	ConnectTreeNodes(&node4, NULL, &node5);

	Test("test12", &node2, &node3);
	Test("test13", &node3, &node4);
	Test("test14", &node4, &node5);
	Test("test15", &node5, NULL);


}


void Test4(){
	TreeLinkNode node5 = TreeLinkNode(5);
	Test("test16", &node5, NULL);
}






int main(){
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}
