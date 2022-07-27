#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class LinkedList
{
public:
    Node *head=NULL,*current=NULL;
    Node* createNode(int value)
    {
        Node *temp=new Node();
        temp->data=value;
        temp->next=NULL;
        return temp;
    }

    void insertAtLast(int value)
    {
        Node *temp=createNode(value);
        if(head==NULL)
        {
            head=temp;
            current=temp;
        }
        else
        {
            current->next=temp;
            current=current->next;
        }
    }

    void insertAtFirst(int value)
    {
        Node *temp=createNode(value);
        if(head==NULL)
        {
            head=temp;
            current=temp;
        } 
        else
        {
            temp->next=head;
            head=temp;
        }
    }

    void insertAfterValue(int value,int searchVal)
    {
        Node *temp=createNode(value);
        //p->next=
        if (head==NULL)
        {
            head=temp;
            current=temp;
        }
        else
        {
            Node *p=head;
            while (p!=NULL)
            {
                if (p->data==searchVal)
                {
                    temp->next=p->next;
                    p->next=temp;
                    break;
                }
                else
                {
                    p=p->next;
                }
            }
        }
    }

    void displayLinkedList()
    {
        Node *p=head;
        while(p!=NULL)
        {
            cout<<p->data<<" -> ";
            p=p->next;
        }
        cout<<endl;
    }

    void DeleteFromFirst()
    {
        if (head != NULL)
        {
            Node *temppointer=head;
            head=temppointer->next;
            delete temppointer;
        }
        else
        {
            cout<<"Can not delete\n";
        }
    }

    void DeleteFromLast()
    {
        Node *temp=head,*p;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        p=temp->next;
        temp->next=NULL;
        current=temp;
        delete p;
    }
    
    void DeleteAnyNode(int SearchVal)
    {
        if (head->data==SearchVal)
        {
            DeleteFromFirst();
        }
        else if (current->data==SearchVal)
        {
            DeleteFromLast();
        }
        else
        {
            Node *temp=head;
            Node *p;
            while (temp!=NULL)
            {
                if (temp->data==SearchVal)
                {
                    p->next=temp->next;
                    delete temp;
                    break;
                }
                p=temp;
                temp=temp->next;
            }
        }
    }

    int getCount()
    {
        Node *n=head;
        int count;
        while (n!=NULL)
        {
            count++;
            n=n->next;
        }
        return count;
    }

    void findMax()
    {
        int maxVal=0;
        Node *temp=head;
        while (temp!=NULL)
        {
            if (temp->data>maxVal)
            {
                maxVal=temp->data;
            }
            temp=temp->next;
        }
        cout<<"Max value in list: "<<maxVal<<endl;
    }
};

class bstNode
{
public:
    int data;
    bstNode *left=NULL;
    bstNode *right=NULL;
};

class BST: public LinkedList
{
public:
    bstNode* createNode(int value)
    {
        bstNode *ptr=new bstNode();
        ptr->data=value;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
    }

    bstNode* insertNode(bstNode *ptr,int value)
    {
        if(ptr==NULL)
        {
            ptr=createNode(value);
        }
        else if(value<ptr->data)
        {
            ptr->left=insertNode(ptr->left,value);
        }
        else if(value>ptr->data)
        {
            ptr->right=insertNode(ptr->right,value);
        }
        return ptr;
    }

    void inorder(bstNode *ptr)
    {
        if(ptr!=NULL)
        {
            inorder(ptr->left);
            cout<<ptr->data<<" ";
            inorder(ptr->right);
        }
    }

    void preorder(bstNode *ptr)
    {
        if(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder(bstNode *ptr)
    {
        if(ptr!=NULL)
        {
            postorder(ptr->left);
            postorder(ptr->right);
            cout<<ptr->data<<" ";
        }
    }

    bstNode* searchNode(bstNode *ptr,int value)
    {
        if(ptr==NULL)
        {
            return ptr;
        }
        else if(value<ptr->data)
        {
            ptr=searchNode(ptr->left,value);
        }
        else if(value>ptr->data)
        {
            ptr=searchNode(ptr->right,value);
        }
        return ptr;
    }

    bstNode* findMin(bstNode *ptr)
    {
        while(ptr->left!=NULL)
        {
            ptr=ptr->left;
        }
        return ptr;
    }

    bstNode* findMax(bstNode *ptr)
    {
        while(ptr->right!=NULL)
        {
            ptr=ptr->right;
        }
        return ptr;
    }

    bstNode* deleteNode(bstNode *ptr,int value)
    {
        ptr=searchNode(ptr,value);
        if(ptr==NULL)
        {
            return ptr;
        }
        else
        {
            //Node->Leaf node
            if(ptr->left==NULL && ptr->right==NULL)
            {
                delete ptr;
                ptr=NULL;
            }
            //Node->with left child
            else if(ptr->right==NULL)
            {
                bstNode *temp=ptr;
                ptr=ptr->left;
                delete temp;
            }
            //Node->with right child
            else if(ptr->left==NULL)
            {
                bstNode *temp=ptr;
                ptr=ptr->right;
                delete temp;
            }
            //Node->with sub-tree
            else
            {
                bstNode *temp=findMin(ptr->right);
                ptr->data=temp->data;
                ptr->right=deleteNode(ptr->right,temp->data);
            }
        }
    }

    void Conversion(bstNode *r,LinkedList lst)
    {
        //LinkedList lst;
        /*lst.insertAtFirst(5);
        lst.insertAfterValue(10,5);
        lst.insertAfterValue(2,10);
        lst.insertAfterValue(9,2);
        lst.insertAfterValue(4,9);
        lst.insertAfterValue(15,4);
        lst.insertAfterValue(8,15);*/
        bstNode *root=r;
        Node *s=lst.head;
        while (s!=NULL)
        {
            int x;
            x=s->data;
            insertNode(root,x);
            s=s->next;
        }
    }
};

int main()
{
    LinkedList lst;
    BST bst;
    int cont;
    int x,y;
    cin>>cont;
    while (cont!=0)
    {
        int choice=0;
        cout<<"enter 1 to insert at first \nenter 2 to insert at last \nenter 3 to insert at after an value";
        cin>>choice;
        if (choice==1)
        {
            cout<<"enter number: ";
            cin>>x;
            lst.insertAtFirst(x);
        }
        else if (choice==2)
        {
            cout<<"Enter end value: ";
            cin>>x;
            lst.insertAtLast(x);
        }
        else if (choice==3)
        {
            cout<<"Insert after value: ";
            cin>>y;
            cout<<"Enter number: ";
            cin>>x;
            lst.insertAfterValue(x,y);
        }
        else 
        {
            cout<<"error\n";
        }
        cout<<"Continue? ";
        cin>>cont;
    }
    int num=lst.head->data;
    cout<<num<<endl;
    bstNode *BST=bst.createNode(num);
    int m=lst.getCount();
    cout<<m<<endl;
    lst.findMax();
    lst.displayLinkedList();
    bst.Conversion(BST,lst);
    bst.inorder(BST);

    return 0;
}
