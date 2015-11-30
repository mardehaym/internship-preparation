#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node * next;
    Node(int x) : val(x), right(NULL), left(NULL), next(NULL) {}
};

class Tree{
private:
    Node * _head;
public:
    Tree() {}
    void add(int x);
    void recAdd(Node * parent, Node * head, int& x, char dir);
    Node * getHead();
    void inOrder(Node * head);
    void postOrder(Node * head);
    int lca(Node * root, int x, int y);
    bool isBalanced(Node * root);
    int depth(Node * root);
    void connect(Node *root);
    void connectHelper(Node * parent, Node * root, char& side);
    Node* sortedArrayToBST(vector<int>& nums);
};

void Tree::add(int x) {
    recAdd(_head, _head, x, 'l');
}

Node * Tree::getHead(){
    return _head;
}

void Tree::inOrder(Node * head){
    if (!head) {
        return;
    }
    inOrder(head->left);
    cout << head->val;
    inOrder(head->right);
}

void Tree::postOrder(Node *head) {
    if (!head) {
        return;
    }
    postOrder(head->left);
    postOrder(head->right);
    cout << head->val << " ";
}

void Tree::recAdd(Node * parent, Node * head, int& x, char dir) {
    if (!head) {
        Node * block = new Node(x);
        !_head ? _head = block : dir == 'l' ? parent->left = block : parent->right = block;
        return;
    }
    if (x >= head->val) {
        recAdd(head, head->right, x, 'r');
    } else {
        recAdd(head, head->left, x, 'l');
    }
}

int Tree::lca(Node *root, int p, int q) {
    if(!root) {
        return -1;
    }
    if (root->val == p || root->val == q) {
        return root->val;
    }
    int L = lca(root->left, p, q);
    int R = lca(root->right, p, q);
    if (L != -1 && R != -1) {
        return root->val;
    }
    return L != -1 ? L : R;
}

    bool Tree::isBalanced(Node *root) {
    if (!root) {
        return false;
    }
    int left = depth(root->left) + 1;
    int right = depth(root->right) + 1;
    
    if (abs(right - left) <= 1) {
        return left < 0 || right < 0 ? false : true;
    }
        return false;
    
}


int Tree::depth(Node *root) {
    if (!root) {
        return 0;
    }
    int l = depth(root->left) + 1;
    int r = depth(root->right) + 1;
    if (abs(r - l) <= 1) {
        return max(r, l);
    }
    return INT_MIN;
}

void Tree::connect(Node * root) {
    if (!root || !root->left) {
        return;
    }
    root->left->next = root->right;
    if (root->next) {
        root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
}



int main() {
    Tree * t = new Tree();
    t->add(20);
    t->add(10);
    t->add(30);
    t->add(5);
    t->add(11);
    t->add(25);
    t->add(35);

    t->connect(t->getHead());
    
    cout << endl << "Passed" << endl;
    
    return 0;
}
