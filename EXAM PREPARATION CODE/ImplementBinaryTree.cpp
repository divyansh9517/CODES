#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* createTree() {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* newNode = new Node(data);
    //cout << "Left of the node " << newNode->data << endl;

    newNode->left = createTree();

    //cout << "Right of the node " << newNode->data << endl;

    newNode->right = createTree();

    return newNode;
}

// 1 2 3 4 5 -1 6 -1 -1 -1 7


// Function for Inorder Traversal
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}
void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" -> ";
    preorder(root->left);
    preorder(root->right);
}

void postOrder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" -> ";
}

void levelOrder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

}

int main() {
    cout << "Enter tree elements (-1 for NULL nodes): " << endl;
    Node* root = createTree();

    cout << "Inorder Traversal of the Tree: ";
    inorder(root);
    cout << "NULL" << endl; // Indicating the end of traversal


    cout<<"printing post order : ";
    postOrder(root);
    cout<<"NULL"<<endl;

    cout<<"printing pre order : ";
    preorder(root);
    cout<<"NULL"<<endl;
    cout<<"printing levelorder : ";
    levelOrder(root);
    //cout<<"NULL"<<endl;
    return 0;
}
