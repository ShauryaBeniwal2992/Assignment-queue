/*
Write a program to find the middle of a linked list.
Input: 1->2->3->4->5
Output: 3
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void findMiddle(Node*&head){
    Node*temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    temp=head;
    for(int i=0;i<count/2;i++){
        temp=temp->next;
        
    }
    cout<<"Middle value is: "<<temp->data<<endl;
}

int main(){

    int num=0;
    while(num%2==0){
        cout<<"Enter number of elements for the list for refernce(odd)";
        cin>>num;
    }
    Node*head=NULL;

    int arr[num];
    int value=0;
    cout<<"Enter the elements for reference: ";
    for(int i=0;i<num;i++){
        cout<<"Element number "<<i+1<<" : ";
        cin>>value;
        Node*temp=new Node;
        temp->data=value;
        temp->next=NULL;
        if (head == NULL) {
            head = temp;
        }
        else {
            Node*current=head;
            while(current->next != NULL){
                current=current->next;
            }
            current->next=temp;
        }
    }
    findMiddle(head);
    

    return 0;
}