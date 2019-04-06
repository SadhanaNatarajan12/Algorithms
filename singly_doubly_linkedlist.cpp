#include <iostream>
struct dllNode
{
    int data;
    struct dllNode* next;
    struct dllNode* prev;

    dllNode(int data) {
	this->data = data;
	next = NULL;
	prev = NULL;
    }
};

struct llNode
{
    int data;
    struct llNode* next;
    llNode(int data) {
	this->data = data;
	next = NULL;
    }
};

//For example, NULL <- 1 <-> 4 <-> 3 <-> 4 <-> 1 -> NULL returns True while 1 <-> 4 returns False.
void printDllFromBeginning(struct dllNode* head)
{
    std::cout<<"Printing Dll from Beginning!"<<std::endl;
    struct dllNode* temp = head;
    while (temp != NULL) {
	std::cout<<temp->data<<" ";
	temp = temp->next;
    }
    std::cout<<std::endl;
}

void printDllFromEnd(struct dllNode* tail)
{
    std::cout<<"Printing Dll from end!"<<std::endl;
    struct dllNode* temp = tail;
    while (temp != NULL) {
	std::cout<<temp->data<<" ";
	temp = temp->prev;
    }
    std::cout<<std::endl;
}

void printSinglyLL(struct llNode* head)
{
    std::cout<<"Printing Singly linkedlist!"<<std::endl;
    struct llNode* temp = head;
    while (temp != NULL) {
	std::cout<<temp->data<<" ";
	temp = temp->next;
    }
    std::cout<<std::endl;
}

void printSinglyLLUsingRecursionUtil(struct llNode* temp)
{
    if (temp == NULL) {
	return;
    } else {
	std::cout<<temp->data<<" ";
	printSinglyLLUsingRecursionUtil(temp->next);
    }
}

void printSinglyLLUsingRecursion(struct llNode* head)
{
    std::cout<<"Printing Singly linkedlist using recursion!"<<std::endl;
    struct llNode* temp = head;
    printSinglyLLUsingRecursionUtil(temp);
    std::cout<<std::endl;
}

bool isDllPalindrome(struct dllNode* head)
{
    struct dllNode* temp = head;
    
    //NULL <- 1 <-> 4 <-> 3 <-> 4 <-> 1 -> NULL
    while (temp->next != NULL) {
	temp = temp->next;
    }
    struct dllNode* tail = temp;
    struct dllNode* temp2 = tail;
    temp = head;

    bool isPalindrome = true;
    while (temp->next != temp2->prev) {
	if (temp->data != temp2->data) {
	    isPalindrome = false;
	    break;
	} else {
	    temp = temp->next;
	    temp2 = temp2->prev;
	}
    }
    return isPalindrome;
}

void ReverseSecondHalfOfLinkedlist(struct llNode *&head)
{
    struct llNode *curr = head;
    struct llNode *next = NULL, *prev = NULL;
    while (curr != NULL) {
	next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
    }
    head = prev;
}

bool Compare2Halves(struct llNode *firstHalf, struct llNode *secondHalf)
{
    struct llNode *temp1 = firstHalf;
    struct llNode *temp2 = secondHalf;

    bool isPalindrome = true;
    while (temp2 != NULL) {
	if (temp1->data != temp2->data) {
	    isPalindrome = false;
	    break;
	} else {
	    temp1 = temp1->next;
	    temp2 = temp2->next;
	}
    }
    return isPalindrome;
}

//Odd : 1 -> 2 -> 3 -> 4 -> 5 : count = 5 : 5/2 = 2, mid = 2 + 1, secondHalf = mid + 1
//Even: 1 -> 2 -> 3 -> 4      : count = 4 : 4/2 = 2, mid = 2, secondHalf = mid + 1
bool isSinglyLinkedListPalindrome(struct llNode *head)
{
    if (head->next == NULL) //case where only 1 node is present!!!
	return true;

    int count = 0;
    struct llNode* temp = head;
    while (temp != NULL) {
	count++;
	temp = temp->next;
    }

    bool isOdd = true;
    if (count % 2 == 0) {
	isOdd = false;
    }

    int mid = 0;
    if (isOdd) {
	mid = count/2 + 1;
    } else {
	mid = count/2;
    }

    struct llNode* secondHalf; 
    temp = head;
    int tmpctr = 0;
    while (tmpctr < mid) {
	tmpctr++;
	temp = temp->next;
    }
    secondHalf = temp;

    ReverseSecondHalfOfLinkedlist(secondHalf);
    bool bisPalindrome = Compare2Halves(head, secondHalf);
    ReverseSecondHalfOfLinkedlist(secondHalf);

    return bisPalindrome;
}

int main()
{
    struct dllNode* head = new dllNode(1);

    head->prev = NULL;
    head->next = new dllNode(4);
    head->next->next = new dllNode(3);
    head->next->next->next = new dllNode(4);
    head->next->next->next->next = new dllNode(1);
    head->next->next->next->next->next = NULL;
    struct dllNode* tail;
    tail = head->next->next->next->next;
    tail->prev = head->next->next->next;
    tail->prev->prev = head->next->next;
    tail->prev->prev->prev = head->next;
    tail->prev->prev->prev->prev = head;
    tail->prev->prev->prev->prev->prev = NULL;

    printDllFromBeginning(head);
    printDllFromEnd(tail);

    std::cout<<"Is the dll Palindrome: "<<isDllPalindrome(head)<<std::endl;

    //NULL <- 1 <-> 4 -> NULL
    struct dllNode* head1 = new dllNode(1);
    head1->prev = NULL;
    head1->next = new dllNode(4);
    head1->next->next = NULL;
    struct dllNode* tail1;
    tail1 = head1->next;
    tail1->prev = head1;
    tail1->prev->prev = NULL;

    printDllFromBeginning(head1);
    printDllFromEnd(tail1);

    std::cout<<"Is the dll Palindrome: "<<isDllPalindrome(head1)<<std::endl;


    //Singly linked list!
    //For example, 1 -> 4 -> 3 -> 4 -> 1 returns True while 1 -> 4 returns False.
    struct llNode *head2 = new llNode(1);
    head2->next = new llNode(4);
    head2->next->next = new llNode(3);
    head2->next->next->next = new llNode(4);
    head2->next->next->next->next = new llNode(1);
    head2->next->next->next->next->next = NULL;
    
    printSinglyLL(head2);

    struct llNode *head3 = new llNode(1);
    head3->next = new llNode(4);
    head3->next->next = NULL;

    printSinglyLL(head3);

    printSinglyLLUsingRecursion(head2);
    printSinglyLLUsingRecursion(head3);

    std::cout<<"Is the singly linked list Palindrome: "<<isSinglyLinkedListPalindrome(head2)<<std::endl;
    std::cout<<"Is the singly linked list Palindrome: "<<isSinglyLinkedListPalindrome(head3)<<std::endl;
}
