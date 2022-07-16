#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
    int data;
    Node *next;
}*head;
void insertatfront(int data)
{
    if(head==NULL)
    {
        head= new Node();
        head->next=NULL;
        head->data=data;
    }
    else
    {
        cout<<"Called Here"<<endl;
        Node *b=new Node();
        b->data=data;
        b->next=head;
        head=b;

    }
}
void printTable()
{
    Node *p =head;
    while(p!=NULL)
    {
        cout<<p->data;
        p=p->next;
    }
}


int main()
{
    insertatfront(4);
    insertatfront(5);
    printTable();
}