#include<bits/stdc++.h>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* prev1)
    {
        data = data1;
        next = next;
        back = prev1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* create(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node* deleteHead(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node* prev =head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node* tail = head;
    while(tail ->next != NULL)
    {
        tail = tail->next;
    }
    Node* prev = tail->back;
    tail->back = NULL;
    prev->next = NULL;

    delete tail;
    
    return head;
}
void printList(Node* head){
    while(head != NULL)
    {
        cout<<head->data<<"->";
        head= head->next;
    }
    cout<<"NULL";
}

Node* removeKth(Node* head,int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    int cnt = 0;
    Node*temp = head;
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL)
    {
        delete temp;
        return NULL;
    }
    else if(prev == NULL)
    {
        deleteHead(head);
        //return head;
    }

    else if(front == NULL)
    {
        deleteTail(head);
    }

    prev ->next = front;
    front->back = prev;

    temp->next =nullptr;
    temp->back = nullptr;

    return head;
}

void deleteNode(Node* temp)
{
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return ;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}
Node* insertHead(Node* head,int val)
{
    Node* newNode = new Node(val,head,nullptr);
    head->back =newNode;
    return newNode;
}

Node* insertTail(Node* head,int val)
{
    if(head->next == NULL)
    {
        return insertHead(head,val);
    }

    Node* tail = head;
    while(tail->next  != NULL)
    {
        tail = tail->next;
    }
    Node* prev = tail->next;
    Node* newNode = new Node(val,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
// Node* insertAtKth(Node* head, int x,int k)
// {
//     if(k == 1)
//     {
//         return insertHead(head,x);
//     }
//     Node* temp = head;
//     int cnt = 0;
//     while(temp != NULL)
//     {
//         cnt++;
//         if(cnt == k)
//         {
//             break;
//         }
//         temp = temp->next;
//     }
//     Node* prev= temp->back;
//     Node* newNode = new Node(x,temp,prev);
//     prev->next = newNode;
//     temp->back = newNode;
//     return head;
// }

Node* insertAtKth(Node* head, int x, int k)
{
    if (k == 1)
    {
        return insertHead(head, x);
    }

    Node* temp = head;
    int cnt = 1;

    while (temp != NULL && cnt < k)
    {
        temp = temp->next;
        cnt++;
    }

    // Insert at the end
    if (temp == NULL && cnt == k)
    {
        // Assuming you have insertTail function
        return insertTail(head, x);
    }

    // Invalid position
    if (temp == NULL)
    {
        cout << "Position out of bounds\n";
        return head;
    }

    // Normal insertion
    Node* prev = temp->back;
    Node* newNode = new Node(x, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}
void insert(Node* node,int x)
{
    Node* prev = node->back;
    Node* newNode = new Node(x,node,prev);
    prev->next = newNode;
    node->back = newNode;
}


int main()
{
    vector<int> arr= {1,2,3,4,5,9,0,7,8};
    Node* head = create(arr);
    printList(head);
    cout<<endl;
    // head = deleteHead(head);
    // printList(head);

    // cout<<endl;
    // head = deleteTail(head);
    // printList(head);
    // cout<<endl;
    // head = removeKth(head,3);
    // printList(head);

    insert(head->next,9);
    printList(head);
}