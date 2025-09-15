/*
1. Develop a menu driven program for the following operations on a Singly Linked
List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
(d) Deletion from the beginning.
(e) Deletion from the end.
(f) Deletion of a specific node, say 'Delete Node 60').
(g) Search for a node and display its position from head.
(h) Display all the node values.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void InsertAtBeginning(Node*&head, int value){
    Node*newNode=new Node();
    newNode->data=value;
    newNode->next=head;
    head=newNode;  
}

void InsertAtEnd(Node*&head, int value){
    Node*newNode= new Node();
    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
        return;
    }
    Node*temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;

}
void InsertAtBetween(Node*&head, int value, int position){
    Node*newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;

    if (position==0){
        newNode->next=head;
        head=newNode;
        return;
    }

    Node*temp=head;
    for (int i=0; i<position-1 && temp!=NULL; i++){
        temp=temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void DeleteAtBeginning(Node*&head){
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    head = head->next;
}
void DeleteAtEnd(Node*&head){
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;

    }

    Node*temp=head;
    Node*temp2;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    delete temp;
    temp2->next=NULL;


}
void DeleteAtBetween(Node*&head, int position){
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if (position == 1) {
        head = head->next;
        return;
    }
    Node*temp=head;
    for(int i=0; i<position-2 && temp->next != NULL;i++){
        temp=temp->next;
    }
    Node*temp2=temp;
    temp=temp->next;
    temp2->next=temp->next;
    delete temp;

}
int searchNode(Node*&head, int value){
    Node*temp=head;
    int count=1;
    while (temp != NULL) {
        if (temp->data == value) {
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}
void displayNode(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

}


int main(){

    Node*head =NULL;
    int value,num=0;

    while(num!=9){
        cout<<"What do you want to proceed with: \n";
        cout<<"1. Insertion at the beginning.\n";
        cout<<"2. Insertion at the end.\n";
        cout<<"3. Insertion in between\n";
        cout<<"4. Deletion from the beginning.\n";
        cout<<"5. Deletion from the end.\n";
        cout<<"6. Deletion of a specific node\n";
        cout<<"7. Search for a node and display its position from head.\n";
        cout<<"8. Display all the node values.\n";
        cout<<"9.Exit";
        cin>>num;
        int tempNum;
        int tempPos;
        switch (num)
        {
        case 1:
            cout<<"Enter the number to insert: ";
            cin>>tempNum;
            InsertAtBeginning(head,tempNum);
            break;
        case 2:
            cout<<"Enter the number to insert: ";
            cin>>tempNum;
            InsertAtEnd(head,tempNum);
            break;
        case 3:
            cout<<"Enter the number to insert: ";
            cin>>tempNum;
            cout<<"Which position to insert";
            cin>>tempPos;
            InsertAtBetween(head,tempNum,tempPos);
            break;
        case 4:
            DeleteAtBeginning(head);
            break;
        case 5:
            DeleteAtEnd(head);
            break;
        case 6:
            cout<<"Which position to delete";
            cin>>tempPos;
            DeleteAtBetween(head,tempPos);
            break;
        case 7:
            cout<<"Which number to find";
            cin>>tempNum;
            tempPos=searchNode(head,tempNum);
            if(tempPos!=-1) {
                cout<<tempNum<<" found at position "<<tempPos<<endl;
            } 
            else{
                cout<<tempNum<<"not found in the list."<<endl;
            }
            break;
        case 8:
            displayNode(head);
            break;
        case 9:
            cout<<"Exiting!";
            break;
        
        default:
        cout<<"Choose a valid option!";
            break;
        }
    }
    

    return 0;
}