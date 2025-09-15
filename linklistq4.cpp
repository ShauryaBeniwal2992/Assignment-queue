/*
4. Write a program to reverse a linked list.
Input: 1->2->3->4->NULL
Output: 4->3->2->1->NULL
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main(){
    int num=0;
    while(num <= 0){
        cout<<"Enter number of elements in the list: ";
        cin>>num;
    }

    Node* head =NULL;
    int value;

    for(int i=0;i<num;i++){
        cout<<"Element number "<<i+1<<" : ";
        cin>>value;
        Node*temp=new Node;
        temp->data=value;
        temp->next=NULL;
        if (head==NULL) {
            head= temp;
        }
        else {
            Node*current=head;
            while(current->next != NULL){
                current=current->next;
            }
            current->next=temp;
        }
    }

    Node*prev= NULL;
    Node*current= head;
    Node*next= NULL;

    while(current!=NULL){
        next=current->next; 
        current->next= prev;
        prev=current;       
        current=next;
    }
    head = prev;

    cout<< "Reversed Linked List: ";
    current=head;
    while(current != NULL){
        cout<<current->data;
        if (current->next != NULL) cout<<"->";
        current = current->next;
    }
    cout << "->NULL" << endl;

    return 0;
}
