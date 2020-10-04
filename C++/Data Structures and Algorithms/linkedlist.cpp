#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class linkedList{
public:
    Node *head, *tail;

    linkedList(){
        head = tail = NULL;
    }

    void printList(){
        Node *tmp = head;
        while(tmp != NULL){
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }

    void push(int a){
        Node* new_node = new Node(a);

        if(head==NULL && tail==NULL){
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node; 
        }
    }

    void pop(){
        Node* tmp = head;
        while(tmp->next != tail){
            tmp=tmp->next;
        }
        tail = tmp;
        tmp=tmp->next;
        tail->next = NULL;
        delete tmp;
               
    }

    void deleteList(){
        delete head;
    }
};

int main(){
    linkedList ll;
    ll.push(10);
    ll.push(15);
    ll.push(20);
    ll.push(25);
    ll.printList();
    ll.pop();
    ll.printList();
    ll.deleteList();
}