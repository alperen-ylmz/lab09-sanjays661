#include "linkedListFuncs.h"
#include <stddef.h>
using namespace std;

/*All functions MUST be implemented recursively
* No credit will be given for non-recursive solutions
*/


//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) 
{
    if (head == nullptr) // base case: head is null
    {
        return 0;
    }
    else if (head->next == nullptr) // base case: linked list has one element
    {
        return head->data;
    }
    else
    {
        return head->data + recursiveSum(head->next);
    }
}


//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) 
{
    if (head->next == nullptr) 
    // base case: linked list has one element
    {
        return head->data;
    }
    else
    {
        if (head->data > recursiveLargestValue(head->next))
        // if head is the largest value in the linked list, greater than all values following it
        {
            return head->data;
        }
        else
        // if head is not the largest value in the linked list
        {
            return recursiveLargestValue(head->next);
        }
    }
}


/*Given the head of a linked list, find and return the kth node of the linked list
 *Assume head is the first node
 *If k is larger than the size of the linked list, return NULL
 *
 * Example: n1 -> n2 -> n3 -> n4 -> n5, k = 3
 * Return &n3
 */
Node* recursiveFindKthNode(Node *head, int k)
{
    if (head == nullptr || k < 1) // base case: head is null or k is less than 1
    {
        return nullptr;
    }
    else if (k == 1) // base case: k = 1
    {
        return head;
    }
    else // recursive case
    {
        return recursiveFindKthNode(head->next, k-1);
    }
}


/*Given the head of a linked list, delete the kth node from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n2 and return &n1
* New list should look like this: n1 -> n3 -> n4
*/
Node* recursiveDeleteKthNode(Node *head, int k) 
{
    if (head == nullptr) // base case: head is null
    {
        return nullptr;
    }
    else if (k < 1) // base case: k < 1 - nothing is deleted
    {
        return head;
    }
    else if (k == 1) // base case: k = 1
    {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    else // recursive case
    {
        head->next = recursiveDeleteKthNode(head->next, k-1);
        return head;
    }
}


/*Given the head of a linked list, delete the first k nodes from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n1, n2 and return &n3
*/
Node* recursiveRemoveKFromFront(Node *head, int k) 
{
    if (head == nullptr) // base case: head is null
    {
        return nullptr;
    }
    else if (k < 1) // base case: k < 1 - nothing is deleted
    {
        return head;
    }
    else
    {
        Node* newHead = head->next;
        delete head;
        if (k == 1) // base case: k = 1
        {
            return newHead;
        }
        else // recursive case
        {
            return recursiveRemoveKFromFront(newHead, k-1);
        }
    }
}


/*Given two linked lists, return a NEW linked-list where each element is the sum of the corresponding elements of the input
 * If a linked list has a longer length than the other, treat the corresponding NULL element as a node with value 0
 * 
 * Example: List 1: 1 -> 2 -> 3 -> 12
 * 	    List 2: 4 -> 5 -> 6
 * Return &head of the linked list 5 -> 7 -> 9 -> 12
 */
Node* recursiveElementwiseSum(Node *head1, Node *head2) 
{
    if (head1 == nullptr && head2 == nullptr) // base case: head1 and head2 are null
    {
        return nullptr;
    }
    else if (head1 == nullptr) // recursive case: head1 is null but head2 is not
    {
        Node* cur = new Node{head2->data, nullptr};
        // if there is a node following head2, apply its value to head2->next
        if (head2->next != nullptr)
        {
            cur->next = recursiveElementwiseSum(nullptr, head2->next);
        }
        return cur;
    }
    else if (head2 == nullptr) // recursive case: head2 is null but head1 is not
    {
        Node* cur = new Node{head1->data, nullptr};
        if (head1->next != nullptr)
        // if there is a node following head1, apply its value to head1->next
        {
            cur->next = recursiveElementwiseSum(head1->next, nullptr);
        }
        return cur;
    }
    else // recursive case: neither head1 nor head2 are null
    {
        Node* cur = new Node{head1->data + head2->data, nullptr};
        if (head1->next != nullptr && head2->next != nullptr) 
        // if head1 and head2 are not at the end of either of their corresponding lists
        {
            cur->next = recursiveElementwiseSum(head1->next, head2->next);
        }
        else if (head1->next == nullptr)
        // if head1 is final but head2 is not
        {
            cur->next = recursiveElementwiseSum(nullptr, head2->next);
        }
        else if (head2->next == nullptr)
        // if head2 is final but head1 is not
        {
            cur->next = recursiveElementwiseSum(head1->next, nullptr);
        }
        else
        // if both head1 and head2 are final nodes
        {
            cur->next = nullptr;
        }
        return cur;
    }
}


/*BONUS: Given the heads of two linked lists, splice the second linked list into the first, alternating elements from each list
 * 
 * The first element of the newly arranged linked list will always be head1, unless head1 is NULL (in which case just return head2)
 *
 * You MUST modify the linked lists themselves and DO NOT create another list or any new nodes
 *
 * Example: List 1: 1->2->3, List 2: 4 -> 5 -> 6
 * Return &head of 1 -> 4 -> 2 -> 5 -> 3 -> 6
 */
Node* recursiveSplice(Node *head1, Node *head2) 
{
    if (head1 == nullptr) // base case: head1 is null
    {
        return head2;
    }
    else if (head2 == nullptr) // base case: head2 is null but head1 is not
    {
        return head1;
    }
    else // recursive case: neither head1 nor head2 is null
    {
        Node *temp = head1->next; // stores head1->next as a temporary variable so it doesn't get orphaned
        head1->next = head2;
        head2->next = recursiveSplice(temp, head2->next);
        return head1;
    }
}
