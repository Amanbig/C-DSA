#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};
class priority{
    public:
    node * head = NULL;
    void push(int a){
        node *news = new node(a);
        if(empty()){
            head=news;
        }
        else if(head->data>=a&&head->next==NULL){
            news->next=head;
            head=news;
        }
        else if(head->data<a&&head->next==NULL){
            head->next=news;
        }
        else{
            node * temp=head;
            while(temp->next!=NULL&&temp->next->data<news->data){
                temp=temp->next;
            }
            news->next=temp->next;
            temp->next=news;
        }
    }
    int pop(){
        if(empty()){
            return 0;
        }
        else{
            node *temp=head;
            int a=temp->data;
            head=head->next;
            delete temp;
            return a;
        }
    }
    bool empty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    int choice=-1;
    priority p;
    while(choice!=0){
        cout<<"Enter 1 - insert in queue\n";
        cout<<"Enter 2 - pop from queue\n";
        cout<<"Enter 0 - exit\n";
        cin>>choice;
        if(choice==1){
            int a;
            cout<<"Enter number\n";
            cin>>a;
            p.push(a);
        }
        else if(choice==2){
            int a=p.pop();
            cout<<a<<endl;
        }
        else if(choice!=0){
            cout<<"Invalid choice\n";
        }
    }
    return 0;
}