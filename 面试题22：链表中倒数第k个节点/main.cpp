#include <iostream>

using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};

//============================寻找单链表倒数第k个节点==========================
//快慢指针，首先快指针相对于慢指针多走k-1步，然后两个指针依次向下遍历
//则当快指针走到尾节点时，慢指针指向倒数第k个节点
ListNode* FindKthToTail(ListNode* pHead,int k){
	if (pHead == NULL || k == 0){
		return NULL;
	}

	ListNode* pBehind = pHead;
	ListNode* pAhead = pHead;

	for (int i = 0; i < k - 1; i++){
		if (pAhead->next != NULL){  //注意判断条件，考虑到没有k个节点的情况
			pAhead = pAhead->next;
		}
		else{
			return NULL;
		}
	}
	while (pAhead->next != NULL){
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}

	return pBehind;
}

void TestKthToTail(){
	ListNode* pHead = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(4);
	ListNode* node4 = new ListNode(5);
	ListNode* node5 = new ListNode(6);
	ListNode* node6 = new ListNode(7);
	pHead->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	ListNode* result = FindKthToTail(pHead,1);
	if (result->val == 7){
		cout << "test1 passed." << endl;
	}
	else{
		cout << "test1 failed." << endl;
	}

	result = FindKthToTail(pHead, 3);
	if (result->val == 5){
		cout << "test2 passed." << endl;
	}
	else{
		cout << "test2 failed." << endl;
	}

	result = FindKthToTail(pHead, 0);
	if (result == NULL){
		cout << "test3 passed." << endl;
	}
	else{
		cout << "test3 failed." << endl;
	}

	result = FindKthToTail(pHead, 8);
	if (result == NULL){
		cout << "test4 passed." << endl;
	}
	else{
		cout << "test4 failed." << endl;
	}




	delete node6;
	delete node5;
	delete node4;
	delete node3;
	delete node2;
	delete node1;
	delete pHead;



}


//=======================找中间节点=================================
//定义两个指针，同时从链表的头节点出发，一个指针一次走一步，另一个指针一次走两步。
//当走得快的指针走到链表的末尾时，走得慢的指针正好在链表的中间。
ListNode* middleNode(ListNode* pHead){
	ListNode* p1 = pHead;
	ListNode* p2 = pHead;
	while (p2->next != NULL && p2->next->next != NULL){
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return p1;
}


void TestMiddle(){
	ListNode* pHead = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(4);
	ListNode* node4 = new ListNode(5);
	ListNode* node5 = new ListNode(6);
	//ListNode* node6 = new ListNode(7);
	pHead->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	//node5->next = node6;

	ListNode* result = middleNode(pHead);
	cout << result->val << endl;

	//delete node6;
	delete node5;
	delete node4;
	delete node3;
	delete node2;
	delete node1;
	delete pHead;
}










int main(){
	//TestKthToTail();
	TestMiddle();
	return 0;
}



参考链接：
 博客 https://blog.csdn.net/lvyuan30276/article/details/12357425
