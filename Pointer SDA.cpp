#include <iostream>
#include <string>

class Node {
public:
    char id;
    std::string name;
    int order;
    Node *next;
    
    Node() {
        next = NULL;
    }
};

class LinkedList {
public:
    Node *head;
    Node *tail;
    
    LinkedList() {
        head = tail = NULL;
    }
    
    void insertDataAfter(char data, char after) {
        if (head == NULL)
            std::cout << "ERROR: LinkedList kosong" << std::endl;
        else if (tail->id == after) {
            insertToTail(data);
        } else {
            Node *temp = head;
            
            while (temp->id != after && temp != NULL) {
                temp = temp->next;
            }
            
            if (temp == NULL)
                std::cout << "ERROR: Node dengan id '" << after << "' tidak ditemukan" << std::endl;
            else {
                Node *newNode = new Node();
                newNode->id = data;
                
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    
    void insertToTail(char data) {
        Node *node = new Node();
        node->id = data;
        
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
};

int main() {
    LinkedList *linked_list = new LinkedList();
    
    Node *node1 = new Node();
    node1->id = 'A';
    
    linked_list->head = node1;
    linked_list->tail = node1;
    
    Node *node2 = new Node();
    node2->id = 'B';
    
    linked_list->head->next = node2;
    linked_list->tail = node2;
    
    std::cout << "Head id: " << linked_list->head->id << std::endl;
    std::cout << "Head next id: " << linked_list->head->next->id << std::endl;
    
    return 0;
}
