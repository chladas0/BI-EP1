#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct BST{
    ~BST(){delete root;}
    struct Node{
        explicit Node(int i) : left(nullptr), right(nullptr), val(i) {}
        ~Node(){delete left, delete right;}
        Node * left, * right;
        int val;
    };

    void insert(int x){
        Node ** insertPos = &root;
        while(*insertPos)
            insertPos = x < (*insertPos)->val ? &(*insertPos)->left : &(*insertPos)->right;
        *insertPos = new Node(x);
    }

    void getShape(Node * cur, int depth)
    {
        if(!cur) return;

        if(cur->left){
            shape += 'L' + to_string(depth);
            getShape(cur->left, depth + 1);
        }
        if(cur->right){
            shape += 'R' + to_string(depth);
            getShape(cur->right, depth + 1);
        }
    }
Node * root = nullptr;
string shape;
};

int main() {
    std::ios::sync_with_stdio(false);
    int c, k, x;
    cin >> c >> k; cin.ignore();
    unordered_set<string> shapes;
    while(c--)
    {
        BST bst;
        for(int i = 0 ; i < k; ++i)
        { cin >> x; bst.insert(x);}
        cin.ignore();
        bst.getShape(bst.root, 0); shapes.insert(bst.shape);
    }
    cout << shapes.size() << endl;
    return 0;
}