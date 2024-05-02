#include <iostream>

using namespace std;

class Node{
    public:
        char id;
        Node *next;
        
        Node(){
            next = NULL;
        }
};

class LinkedList{
    public:
        Node *head;
        Node *tail;
        
        LinkedList(){
            head = tail = NULL;
        }
        void insertToHead(char data){
            Node *new_node = new Node();
            new_node->id = data;
            
            if(head == NULL){
                head = tail = new_node;
            } else {
                new_node->next = head;
                head = new_node;
            }
        }
        void insertToTail(char data){
            Node *new_node = new Node();
            new_node->id = data;
            
            if(head == NULL){
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        void traversal(){
            Node *current_node = head;
            while(current_node != NULL){
                cout << current_node->id << " ";
                current_node = current_node->next;
            }
            cout << endl;
        }
};
int main(int argc, char** argv) {
    
    LinkedList *linked_list = new LinkedList();
    
    Node *node1 = new Node();
    node1->id = 'A';
    
    linked_list->head = node1;
    linked_list->tail = node1;
    
    Node *node2 = new Node();
    node2->id = 'B';
    
    linked_list->head->next = node2;
    linked_list->tail = node2;
    
    cout << linked_list->head->id << endl;
    cout << linked_list->head->next->id << endl;
    
    Node *new_node = new Node();
    new_node->id = 'X';
    
    Node *current_node = linked_list->head->next;
    linked_list->head = new_node;
    new_node->next = current_node;
    
    linked_list->insertToTail('C');
    linked_list->insertToTail('D');
    
    linked_list->traversal();
    
    return 0;
}
