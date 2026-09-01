/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* next = curr->next;  // store next
                Node* child = flatten(curr->child);  // flatten child list

                

                // Go to the tail of the child list
                Node* temp = child;
                while (temp->next) {
                    temp = temp->next;
                }

                // Connect tail of child to next
                temp->next = next;
                if (next) next->prev = temp;
            }

            curr = curr->next;  // move forward
        }

        return head;
    }
};
;
