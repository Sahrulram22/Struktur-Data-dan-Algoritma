#include <iostream>
using namespace std;

#define max 5
string dataQueue[max];
int top = 0;

bool isFull(){
    if(top >= max){
        return true;
    }else {
        return false;
    }
}

bool isEmpty(){
    if(top == 0){
        return true;
    }else{
        return false;
    }
}

void view(){
    if(!isEmpty()){
        cout << "Data Antrian : " << endl;
        for(int a = top-1;a >=0; a--){
            cout << a+1 << "." << dataQueue[a] << endl;
        }
    }else {
        cout << "Antrian Kosong" << endl;
    }
    
    if(isFull()){
        cout << "Antrian Penuh" << endl;
    }
    cout << endl;
}

void enqueue(){
    if(!isFull()){
        cout<<"Masukan Data : ";
        cin >> dataQueue[top];
        top++;
    }
}

void dequeue(){
    if(!isEmpty()){
        for(int a = 0; a < top-1; a++){
            dataQueue[a] = dataQueue[a+1];
        }
        top--;
    }
    
}


int main() {
    int choice;
    string item;
    
    queue:
        system("cls");
        view();
        cout << "Menu Utama\n1. Enqueue\n2. Dequeue\nPilihan :";
        cin >> choice;
       
    if(choice == 1){
        system("cls");
        enqueue();
        goto queue;
    } else if (choice == 2){
        system("cls");
        dequeue();
        goto queue;
    }    
}
