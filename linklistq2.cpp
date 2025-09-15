/*
2. Write a program to count the number of occurrences of a given key in a singly linked
list and then delete all the occurrences.
Input: Linked List : 1->2->1->2->1->3->1 , key: 1
Output: Count: 4 , Updated Linked List: 2->2->3.
*/


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main(){
    int num=0;
    while(num<=0){
        cout<<"Enter number of elements in the list: ";
        cin>>num;
    }

    Node* head=NULL;
    int value;

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
    int key;
    cout<<"Enter the key to count and delete: ";
    cin>>key;

    Node*current =head;
    Node*prev =NULL;
    int count=0;

    while(current!=NULL){
        if(current->data==key){
            count++;
            Node* toDelete =current;
            if(prev==NULL){
                head=current->next;
            } 
            else{
                prev->next=current->next;
            }
            current=current->next;
            delete toDelete;
        } 
        else{
            prev=current;
            current=current->next;
        }
    }

    cout<<"Count: "<<count<< endl;
    cout<<"Updated Linked List: ";
    current = head;

    while(current != NULL){
        cout<<current->data;
        if (current->next != NULL) cout << "->";
        current = current->next;
    }
    cout << endl;

    return 0;
}
