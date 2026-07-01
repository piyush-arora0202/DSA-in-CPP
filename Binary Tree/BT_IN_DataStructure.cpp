#include <iostream> 
#include <vector>   
#include <queue>
#include <map>
using namespace std;

class Node { // O(N)
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); // left
    root->right= buildTree(preorder); // right
    return root;
}

//// PREORDER TRAVERSAL ////////////////// TC: O(N) // 
void preOrder(Node*root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

///// InORDER TRAVERSAL /////////////////// TC: O(N) // 
// void inOrder(Node*root) {
//     if (root == NULL) {
//         return;
//     }
//     inOrder(root->left);
//     cout << root->data << " ";
//     inOrder(root->right);
// }
///// POSTORDER TRAVERSAL ///////////////// TC: O(N) //
// void postOrder(Node*root) {
//     if (root == NULL) {
//         return;
//     }
//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->data << " ";
// }
/////////LEVEL ORDER TRAVERSAL // TC:(n) /////////////
// void levelOrder(Node* root) {
//     if (root == NULL) return;
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL); 

//     while(q.size()>0) {
//         Node* curr = q.front();
//         q.pop();

//         if (curr == NULL) {
//             if (!q.empty()) {
//                 cout << endl;
//                 q.push(NULL);
//                 continue;
//             } else {
//                 break;
//             }
//         }
        
//         cout << curr->data << " ";

//         if (curr->left != NULL) {
//             q.push(curr->left);
//         }
//         if (curr->right != NULL) {
//             q.push(curr->right);
//         }

//     }
// }
////////////// Height of tree ////////////////////////
// int height(Node* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     int leftHt = height(root->left);
//     int rightHt = height(root->right);
//     return max(leftHt,rightHt)+1;   
// }
//////////// Count Nodes ///////////////////
// int count(Node* root) {
//     if (root == NULL) {
//         return 0;
//     }

//     int leftcount = count(root->left);
//     int rightcount = count(root->right);
//     return (leftcount + rightcount )+1;
// }
/////////// Sum of Nodes /////////////////////
// int sumofNodes(Node* root) {
//     if (root == NULL) {
//         return 0;
//     }

//     int leftsum = sumofNodes(root->left);
//     int rightsum = sumofNodes(root->right);
//     return (leftsum + rightsum )+root->data;
// }   
//////////// Top View ////////////////
// void bottomView(Node* root) { // O(NlogN)  
//     queue<pair<Node* ,int >>q;//(node,HD) // O(N)
//     map<int,int> m;//(HD,node val) // O(logN)
//     q.push({root,0});

//     while(q.size()>0) {
//         Node* curr = q.front().first;
//         int currHD = q.front().second;
//         q.pop();

//         // if(m.find(currHD) == m.end()) {
//         m[currHD] = curr->data;
//         // }
//         if (curr->left != NULL) {
//             q.push({curr->left,currHD-1});
//         }
//         if (curr->right != NULL) {
//             q.push({curr->right,currHD+1});
//         }
//     }
//     for (auto it : m) {
//         cout << it.second << " ";
//     }
//     cout << endl;

// }
//////////kth level of tree ////////////    
// void KthLevel(Node* root,int K) {
//     if (root == NULL) {
//         return;
//     }
//     if (K==1) {
//         cout <<root->data << " ";
//         return;
//     }

//     KthLevel(root->left,K-1);
//     KthLevel(root->right,K-1);
// }
///////////// Transform to sum tree ////////////////////////
int sumTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftsum = sumTree(root->left);
    int rightsum = sumTree(root->right);
    root->data += leftsum + rightsum;
    
    return root->data;
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);

    // preOrder(root);
    // inOrder(root);
    // postOrder(root);
    // levelOrder(root);   

    // cout << endl;
    // cout << "Height : " << height(root) << endl;
    // cout << "Count : " << count(root) << endl;
    // cout << "Sum of Nodes : " << sumofNodes(root) << endl;
    // topView(root);  
    // bottomView(root); 
    // KthLevel(root,3);  
    cout << "before sum tree : ";
    preOrder(root);

    sumTree(root);

    cout << "\nafter sum tree : ";
    preOrder(root);
    cout << endl;
    return 0;
}