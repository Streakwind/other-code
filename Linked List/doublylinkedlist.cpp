

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;
    public:
        DoublyLinkedList () {
            head = NULL;
        }
        
        void DisplayList () {
            if (head == NULL) {cout << "Empty list" << endl; return;}
            
            Node* temp = head;
            
            while (temp != NULL) {
                cout << temp->val << " ";
                
                temp = temp->next;
            }
            
            cout << endl;
        }
        
        void InsertFront (int givenVal) {
            Node* newNode = new Node();
            newNode->val = givenVal;
            newNode->next = head;
            newNode->prev = NULL;
            
            head = newNode;
        }
        
        void DeleteFront () {
            if (head == NULL) {
                return;
            }
            
            Node* temp = head;
            head = head->next;
            
            delete temp;
        }
        
        void InsertBack (int givenVal) {
            Node* newNode = new Node();
            newNode->val = givenVal;
            newNode->next = head;
            newNode->prev = NULL;
            
            if (head == NULL) {
                head = newNode;
            } else {
                Node* temp = head;
            
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                
                newNode->prev = temp;
                newNode->next = NULL;
                temp->next = newNode;
            }
        }
        
        void DeleteBack () {
            if (head == NULL) {return;}
            
            if (head->next == NULL) {
                delete head;
                head = NULL;
                
                return;
            }
            
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
        }
};

int main () {
    DoublyLinkedList test;
    
    test.InsertFront(5);
    test.InsertFront(6);
    test.InsertBack(7);
    test.DisplayList();
    
    test.DeleteFront();
    test.DeleteBack();
    test.DisplayList();
    
    return 0;
}
