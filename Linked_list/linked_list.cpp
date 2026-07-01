
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// linear linked list //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int value) {
//         data = value;
//         next = NULL;
//     }
// };
// class list {
//     Node* head;
//     Node* tail;
// public:
//     list() {
//         head = NULL;
//         tail = NULL;
//     }

//     void push_front(int val) {
//         Node* newNode = new Node(val);
//         if (head == NULL) {
//             head = tail = newNode;
//             return;
//         } else {
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     void push_back(int val) {
//         Node* newNode = new Node(val);
//         if (head == NULL) {
//             head = tail = newNode;
//             return;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void pop_front() {
//         if (head == NULL) {
//             cout << "LL is empty\n";
//             return;
//         } else {
//             Node* temp = head;
//             head = head->next;
//             temp->next = NULL;
//             delete temp;

//         }
//     }

//     void pop_back() {
//         if (head == NULL) {
//             cout << "LL is empty\n";
//             return;
//         }
//         Node* temp = head;
//         while (temp->next != tail) {
//             temp = temp->next;
//         }
//         temp->next = NULL;
//         delete tail;
//         tail = temp;
//     }

//     void insert(int pos, int val) {
//         if (pos < 0) {
//             cout << "Invalid position\n";
//             return;
//         }

//         if (pos == 0) {
//             push_front(val);
//             return;
//         }
//         Node* temp = head;
//         for (int i = 0; i < pos - 1; i++) {
//             if (temp == NULL) {
//                 cout << "Position out of bounds\n";
//                 return;
//             }
//             temp = temp->next;
//         }

//         Node* newNode = new Node(val);  
//         newNode->next = temp->next;
//         temp->next = newNode;
//     } 
//     int search(int key) {
//         Node* temp = head;
//         int pos = 0;
//         while (temp != NULL) {
//             if (temp->data == key) {
//                 return pos;
//             }
//             temp = temp->next;
//             pos++;
//         }
//         return -1; // Not found
//     }




//     void printLL() {
//         Node* temp = head;
//         while (temp != NULL) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };  
// int main () {
//     list ll;
//     ll.push_front(3);
//     ll.push_front(2);
//     ll.push_front(1);

//     ll.insert(3,4);

//     ll.printLL();
    
//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// doubly linked list //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// class Node {
// public:
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int val) {
//         data = val;
//         next = prev = NULL;
//     }
// };
// class DoublyList {
//     Node* head;
//     Node* tail;

// public:
//     DoublyList() {
//         head = tail = NULL;
//     }

//     void push_front(int val) {
//         Node *newNode = new Node(val);
//         if (head==NULL) {
//             head = tail = newNode;
//         } else {
//             newNode->next = head;
//             head->prev = newNode;
//             head = newNode;
//         }
//     }

//     void print() {
//         Node* temp = head;
//         while(temp != NULL) {
//             cout << temp->data << "<=>";
//             temp = temp->next;
//         }
//         cout << "NULL\n";
//     }

//     void push_back(int val) {
//         Node* newNode = new Node(val);

//         if (head == NULL) {
//             head = tail = newNode;
//         } else {
//             newNode->prev = tail;
//             tail->next = newNode;
//             tail = newNode;

//         }
//     }
//     void pop_front() {
//         if (head==NULL) {
//             cout <<"dll is empty\n";
//             return;
//         }
//         Node* temp = head;
//         head = head->next;

//         if(head!=NULL) {
//             head->prev = NULL;
//         }
//         temp->next = NULL;
//         delete temp;
//     }
//     void pop_back() {
//         if (head==NULL) {
//             cout << "dll is empty";
//             return;
//         }
//         Node* temp = tail;
//         tail = tail->prev;;

//         if (tail != NULL) {
//             tail->next = NULL;
//         }
//         temp->prev = NULL;
//         delete temp;
//     }
// };
// int main() {
//     DoublyList dll;

//     dll.push_back(1);
//     dll.push_back(2);
//     dll.push_back(3);

//     dll.pop_back();
//     dll.pop_back();
//     dll.print();
//     return 0;
// }



///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// circular linked list //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;
public:
    CircularList() {
        head = tail = NULL;
    }    
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void print() {
        if (head == NULL) {
            cout << "CLL is empty\n";
            return;
        }
        cout << head->data << "->";
        Node* temp = head->next;
        while(temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteAtHead() {
        if (head == NULL) {
            cout << "CLL is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }
    void deleteAtTail() {
        if (head == NULL) {
            cout << "CLL is empty\n";
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        tail->next = NULL;
        delete tail;
        tail = temp;
    }
};
int main() {
    CircularList cll;

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    cll.print();

    cll.deleteAtHead();
    cll.print();

    cll.deleteAtTail();
    cll.print();
    return 0;
}


