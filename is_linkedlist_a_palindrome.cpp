#include <iostream>
struct llNode {
    int data;
    llNode *next;

    llNode(int data) {
        this->data = data;
    }
};

void ReverseList(struct llNode* &head)
{
    llNode* curr = head;
    llNode* prev = NULL;
    llNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool isLinkedListAPalindrome(struct llNode* &head)
{
    //Go to the mid of the linked list
    //Get the first half
    //Reverse the second half
    //Compare both first and second half!
    //Then before returning, reverse the second half again!

    struct llNode* temp = head;
    struct llNode* firstHalf = head;

    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    bool isOdd = true;
    if (count % 2 == 0) {
        isOdd = false;
    }

    int mid = (count / 2);
    if (isOdd) {
        mid = (count / 2) + 1;
    }
        temp = head;
    int second = mid;

    std::cout<<std::endl;

    while (second > 0) {
        temp = temp->next;
        second--;
    }


    struct llNode* secondHalf = temp;
    ReverseList(secondHalf);

    //Compare both the lists!
    struct llNode* temp2 = secondHalf;
    temp = head;

    bool isPalindrome = true;
    while (temp2 != NULL) {
        if (temp->data == temp2->data) {
            temp = temp->next;
            temp2 = temp2->next;
        } else {
            isPalindrome = false;
            break;
        }
    }

    //Reverse the second half back!
    ReverseList(secondHalf);

    return isPalindrome;
}

int main()
{
    // 1 -> 2 -> 3 -> 2 -> 1
    llNode *head = new llNode(1);
    head->next = new llNode(2);
    head->next->next = new llNode(3);
    head->next->next->next = new llNode(2);
    head->next->next->next->next = new llNode(1);
    std::cout<<"Is a palindrome? 1 -> 2 -> 3 -> 2 -> 1? "<<isLinkedListAPalindrome(head)<<std::endl;

    // 1 -> 2 -> 2 -> 1
    llNode *head1 = new llNode(1);
    head1->next = new llNode(2);
    head1->next->next = new llNode(2);
    head1->next->next->next = new llNode(1);
    std::cout<<"Is a palindrome? 1 -> 2 -> 2 -> 1? "<<isLinkedListAPalindrome(head1)<<std::endl;

    // 1 -> 2 -> 4 -> 1
    llNode *head2 = new llNode(1);
    head2->next = new llNode(2);
    head2->next->next = new llNode(4);
    head2->next->next->next = new llNode(1);
    std::cout<<"Is a palindrome? 1 -> 2 -> 4 -> 1? "<<isLinkedListAPalindrome(head2)<<std::endl;

    // 1 -> 2 -> 3 -> 2 -> 5
    llNode *head3 = new llNode(1);
    head3->next = new llNode(2);
    head3->next->next = new llNode(3);
    head3->next->next->next = new llNode(2);
    head3->next->next->next->next = new llNode(5);
    std::cout<<"Is a palindrome? 1 -> 2 -> 3 -> 2 -> 5? "<<isLinkedListAPalindrome(head3)<<std::endl;
}
