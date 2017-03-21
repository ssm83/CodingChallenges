#include <iostream>
#include <stack>
using namespace std;
    
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    ListNode *lnx = head;
    ListNode *ln2x = head;
    std::stack<int> elems;
    while (ln2x != NULL && ln2x->next != NULL) {
        elems.push(lnx->val);
        lnx = lnx->next;
        ln2x = ln2x->next->next;
    }
    // for odd sequence,remove the top
    if (ln2x != NULL && ln2x->next == NULL)
        elems.pop();
    while (!elems.empty() && lnx != NULL) {
        if (elems.top() != lnx->val)
            return false;
        elems.pop();
        lnx = lnx->next;
    }
    return true;
}

// f           l
// 10->20->20->10
//isPalindromRecursive(head, &head)
bool isPalindromRecursive(ListNode *last, ListNode **first) {
    if (*first == NULL) return true;
    if((last->next != NULL) && 
        !isPalindromRecursive(last->next, first))
            return false;
    if (last->val != (*first)->val) return false;
    *first = (*first)->next;
    return true;
}
    
    
int main() {
	// your code goes here
	ListNode *first = new ListNode(30);
	ListNode *second = new ListNode(20);
	ListNode *third = new ListNode(30);
	ListNode *fourth = new ListNode(40);
	ListNode *fifth = new ListNode(30);
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	if (isPalindromRecursive(first, &first))
	    cout << "Is Palindrome!" << endl;
	else
	    cout << "Not a Palindrome!" << endl;
	return 0;
}
