#include <iostream>

using namespace std;

class Node {
public:
    char id;
    Node* next;

    Node() {
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = NULL;
    }

    void insertToHead(char data) {
        Node* new_node = new Node();
        new_node->id = data;

        if (head == NULL) {
            head = tail = new_node;
        } else {
            Node* tmp = head;
            head = new_node;
            new_node->next = tmp;
        }
    }

    void insertToTail(char data) {
        Node* new_node = new Node(); 
        new_node->id = data;

        if (head == NULL) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void traversal() {
        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->id << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void insertDataAfter(char data, char after) {
        if (head == NULL) {
            cout << "ERROR: LinkedList Empty" << endl;
        } else {
            Node* tmp = head;
            while (tmp != NULL && tmp->id != after) {
                tmp = tmp->next;
            }
            if (tmp == NULL) {
                cout << "ERROR: Node with id '" << after << "' not found" << endl;
            } else {
                Node* new_node = new Node(); 
                new_node->id = data;
                new_node->next = tmp->next;
                tmp->next = new_node;
                if (tmp == tail) {
                    tail = new_node;
                }
            }
        }
    }
};

int main(int argc, char** argv) {

    LinkedList* linked_list = new LinkedList();

    linked_list->insertToHead('A');
    linked_list->insertToTail('B');

    cout << linked_list->head->id << endl;
    cout << linked_list->head->next->id << endl;

    Node* nodeX = new Node();
    nodeX->id = 'X';

    Node* tmp = linked_list->head->next;
    linked_list->head->next = nodeX;
    nodeX->next = tmp;

    linked_list->insertToTail('C');
    linked_list->insertToTail('D');

    cout << linked_list->head->id << endl;
    cout << linked_list->tail->id << endl;

    return 0;
}
