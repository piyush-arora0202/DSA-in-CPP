#include <iostream>
#include <vector>
#include <climits>
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
Node* insert(Node* root,int val) {
    if (root == NULL) {
        return new Node(val); // return the updated root
    }
    if (val < root->data) {
        root->left = insert(root->left,val);
    } else {
        root->right = insert(root->right,val);
    }
    return root;
}
Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for (int val : arr) {
        root = insert(root,val);
    }
    return root;
}
// void inorder(Node* root, vector<int>& arr) {
//     if (root == NULL) {
//         return;
//     }
//     inorder(root->left, arr);
//     arr.push_back(root->data);
//     inorder(root->right, arr);
// }
// bool search(Node* root,int key) {
//     if(root == NULL) {
//         return false;
//     }
//     if (root->data == key) {
//         return true;
//     }
//     if (key <root->data) {
//         return search(root->left,key);
//     } else {
//         return search(root->right,key);
//     }
// }
// Node* getInorderSuccessor(Node* root) { // left most node in right subtree
//     while (root->left != NULL && root != NULL) {
//         root = root->left;
//     }
//     return root;
// }
// Node* delNode(Node* root,int key) {
//     if (root == NULL) {
//         return NULL;
//     }
//     if (key < root->data) {
//         root->left = delNode(root->left,key);
//     } else if (key > root->data){
//         root->right = delNode(root->right,key);
//     } else {
//         //key == root
//         if (root->left == NULL) {
//             Node* temp = root->right;
//             delete root;
//             return temp;
//         }
//         if (root->right == NULL) {
//             Node* temp = root->left;
//             delete root;
//             return temp;
//         } else { // 2 children
//             Node* IS = getInorderSuccessor(root->right);
//             root->data = IS->data;
//             root->right = delNode(root->right, IS->data);
//         }
//     }
//     return root;
// }


// int main() {
//     vector<int> arr = {3,2,1,5,6,4};

//     Node* root = buildBST(arr);
//     cout << "befor : " ;
//     inorder(root);
//     cout << endl;
//     // cout << search(root,1) << endl;
//     delNode(root,2);
    
//     cout << "After : ";
//     inorder(root);
//     cout << endl;

//     return 0;
// }


///////////// merge two bst /////////////////// TC: O(n+m) SC: O(n+m)
// Node* buildBSTFromSorted(vector<int> arr, int start, int end) {
//     if (start > end) {
//         return NULL;
//     }
//     int mid = (start + end) / 2;
//     Node* root = new Node(arr[mid]);
//     root->left = buildBSTFromSorted(arr, start, mid - 1);
//     root->right = buildBSTFromSorted(arr, mid + 1, end);
//     return root;
// }

// Node* merge2BST(Node* root1,Node* root2) {
//     vector<int> arr1,arr2;
//     inorder(root1,arr1);
//     inorder(root2,arr2);   
    
//     vector<int> temp;
//     int i = 0, j = 0;   
//     while (i < arr1.size() && j < arr2.size()) {
//         if (arr1[i] < arr2[j]) {
//             temp.push_back(arr1[i]);
//             i++;
//         } else {
//             temp.push_back(arr2[j]);
//             j++;
//         }
//     }
//     while (i < arr1.size()) {
//         temp.push_back(arr1[i]);
//         i++;
//     }   
//     while (j < arr2.size()) {
//         temp.push_back(arr2[j]);
//         j++;
//     }   
//     return buildBSTFromSorted(temp,0,temp.size()-1);   

// }   
////////////////// Largest BST /////////////////
// class Info {
// public:
//     int sz;
//     int max;
//     int min;
//     Info(int mi , int ma , int size) {
//         min = mi;
//         max = ma;
//         sz = size;
//     }
// };
// Info helper(Node* root) {
//     if (root == NULL) {
//         return Info(INT_MAX,INT_MIN,0);
//     }
//     Info left = helper(root->left);
//     Info right = helper(root->right);

//     if (root->data > left.max && root->data < right.min) {
//         int currmin = min(root->data,left.min);
//         int currmax = max(root->data,right.max);
//         int currsz = left.sz + right.sz + 1;
//         return Info(currmin,currmax,currsz);
//     }
//     return Info(INT_MIN,INT_MAX,max(left.sz,right.sz));
// }
// int largestBSTinBT(Node* root) {
//     Info info = helper(root);
//     return info.sz;
// }
/////////////// Predecessor & Successor in BST /////////////////////////////
Node* rightmost(Node* root) {
    Node* ans;
    while (root != NULL) {
        ans = root;
        root = root->right;
    }
    return ans;
}
Node* leftmost(Node* root) {
    Node* ans;
    while (root != NULL) {
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPredSucc(Node* root,int key) {
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while (curr != NULL) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            if (curr->left != NULL) {
                pred = rightmost(curr->left);
            }
            if (curr->right != NULL) {
                succ = leftmost(curr->right);
            }
            break;
        }
    }
    return {pred->data,succ->data};
}

int main() {

//     Node* root = new Node(10);
//     root-> left = new Node(5);
//     root->right = new Node(15);
//     root->left->left = new Node(1);
//     root->left->right = new Node(8);
//     root->right->right = new Node(7);

//     cout << largestBSTinBT(root) << endl;

    Node* root = new Node(6);
    root-> left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    vector<int> ans = getPredSucc(root,key);
    cout << "Predecessor: " << ans[0] << endl;
    cout << "Succ: " << ans[1] << endl;

    return 0;

}