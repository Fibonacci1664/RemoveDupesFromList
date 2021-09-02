#include<iostream>

 // Definition for singly-linked list.
 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* header;
 ListNode* tail;
 int size = 0;
 
 // Append stuff to the end of the list.
 void append(int data)
 {
     // Create new node
     ListNode* n = new ListNode(data);

     // Case 1: Empty List.
     if (header == nullptr)
     {
         header = n;
         tail = n;
     }
     else		// Case 2: List is not empty.
     {
         tail->next = n;
         tail = n;
     }

     // Increment the size count of the list.
     ++size;
 }

ListNode* deleteDuplicates(ListNode* head)
{
    // Case 1: empty list
    if (head == nullptr)
    {
        return nullptr;
    }

    // Case 2: 1 node
    if (head->next == nullptr)
    {
        return head;
    }

    // Case 3: > 1 node

    // Traverse list
    // Create a temp node to use as an iterator, this way we can just return the same head
    ListNode* iter = head;
    bool flag = false;

    while (iter->next != nullptr)
    {
        // Check for and remove dups
        while(iter->next->val == iter->val)
        {
            // Check if we're 2 away from the end of the list
            if (iter->next->next != nullptr)
            {
                ListNode* temp = iter->next->next;
                delete iter->next;
                iter->next = temp;
            }
            else
            {
                // If we enter this scope it means we will just delete the very last node
                // So just break from here.
                delete iter->next;
                iter->next = nullptr;
                flag = true;
                break;
            }
        }

        if (flag)
        {
            break;
        }

        // Don't move the iterator pointer until we're sure the next
        // node does NOT have the same value as the current one
        iter = iter->next;
    }

    return head;
}

int main()
{
    append(1);
    append(1);
    append(1);
    append(3);
    append(3);
    append(3);

    ListNode* iter = header;

    while (iter != nullptr)
    {
        std::cout << "[ " << iter->val << " ], ";

        iter = iter->next;
    }

    deleteDuplicates(header);

    std::cout << '\n';

    while (header != nullptr)
    {
        std::cout << "[ " << header->val << " ], ";

        header = header->next;
    }

	return 0;
}