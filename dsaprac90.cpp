#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Build tree from preorder traversal where -1 represents NULL node
Node* buildTree(vector<int>& preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}



// Morris Traversal - Preorder version
vector<int> morris_algo(Node* root) {
    Node* curr = root;
    vector<int> ans;
    while (curr != NULL) {
        if (curr->left == NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
            Node* IP = curr->left;
            while (IP->right != NULL && IP->right != curr) {
                IP = IP->right;
            }
            if (IP->right == NULL) {
                IP->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            } else {
                IP->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}



int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

   

    cout << "Morris Preorder Traversal:" << endl;
    vector<int> morrisResult = morris_algo(root);
    for (int val : morrisResult) {
        cout << val << " ";
    }
    cout << endl;

  

    return 0;
}

