#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->left = NULL;
    }

};

Node* insertIntoBST(Node* root,int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(data > root->data)
    {
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;

}
void createBst(Node* &root)
{
    int data;
    cin>>data;
    while(data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
    return;
}
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
    queue<Node*> q;
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
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
bool searchBST(Node* root,int target)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == target)
    {
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    if(target>root->data)
    {
        rightAns = searchBST(root->right,target);
    }
    else{
        leftAns = searchBST(root->left,target);
    }
    return leftAns || rightAns;
}
int minVal(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    Node* curr = root;
    while(curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr->data;
}

int maxVal(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    } 
    Node* curr = root;
    while(curr->right != NULL)
    {
        curr=curr->right;
    }
    return curr->data;
}


Node* deleteFromBst(Node* root,int target)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == target)
    {
        //0 no. child node
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //1 at least 1 child node
        //for left 
        if( root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // for right
        if(root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 in this case root have 2 childe node
        if(root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteFromBst(root->right , mini);
            return root;
        }
    }
    else if( root->data > target)
    {
        root->left = deleteFromBst(root->left , target);
    }
    else{
        root->right = deleteFromBst(root->right,target);
    }
    return root;
}

Node* bstfromInorder(int inorder[] ,int start ,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int element = inorder[mid];
    Node* root = new Node(element);
    root->left = bstfromInorder(order,start,mid-1);
    root->right =  bstfromInorder(order,mid-1,endl);
}
Node* inOrderSuccessor(Node* root,Node* x)
{
    Node* succ = 0;
    Node* curr = root;
    while(curr){
        if(curr->data > x->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    return succ;
}
Node* inOrderPredecessor(Node* root,Node* p)
{
    Node* pre = 0;
    Node* curr = root;
    while(curr)
    {
        if(curr->data < p->data)
        {
            pre = curr;
            curr= curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return pre;
}

int maxHeight(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    int height = max(leftHeight,rightHeight)+1;
    return  height;
}

int diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = maxHeight(root->left)+maxHeight(root->right) + 1;
    int diameterr = max(option1,max(option2,option3));
    return diameterr;
}

Node lca(Node* root ,Node* p  , Node* q)
{
    if(root == NULL)
    {
        return NULL:
    }
    if( root->data == p->data)
    {
        return p;

    }
    if(root->data == q->data)
    {
        return q;
    }

    Node* rh = lca(root->right,p,q);
    Node* lh =  lca(root->left,p,q);
    if(lh == NULL&& rh == NULL)
    {
        return NULL;
    }
    else if(lh!= NULL && rh == NULL)
    {
        return lh;
    }
    else if(lh == NULL && rh != NULL)
    {
        return rh;
    }
    else{
        return root;
    }

}




int main() {
    Node* root = NULL; // Initialize root to NULL
    cout << "Enter values to insert into BST (enter -1 to stop):" << endl;
    createBst(root);

    cout << "Inorder Traversal of the BST: ";
    inorder(root);
    cout<<"NULL"<<endl;
    cout << endl;

    cout<<"Level order traversal";
    levelOrder(root);
    //cout<<"NULL"<<endl;

    if(searchBST(root,12) == true)
    {
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    cout<<"Minimum value :- "<<minVal(root)<<endl;
    cout<<"Maximum value :- "<<maxVal(root)<<endl;
    deleteFromBst(root,70);
    levelOrder(root);

    return 0;
}