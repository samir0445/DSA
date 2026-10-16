#include<bits/stdc++.h>
using namespace std;



  class TreeNode {
    public:
     int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
  };

bool isleaf(TreeNode* node) {
    return node != nullptr &&
           node->left == nullptr &&
           node->right == nullptr;
}
    void addleft(TreeNode* root , vector<int>& ans){
        TreeNode* node = root->left;
        while(node){
            if(!isleaf(node)) ans.push_back(node->data);

            if(node->left){
                node = node->left;
            }
            else{
                node = node->right;
            }

        }
        
    }
    void addRight(TreeNode* root , vector<int>& ans){
         TreeNode* node = root->right;
         stack<int> st;
        while(node){
            if(!isleaf(node)) st.push(node->data);

            if(node->right){
                node = node->right;
            }
            else{
                node = node->left;
            }

        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

    }

    
    void addleaf(TreeNode* root , vector<int>& ans){

        if(isleaf(root)){
            ans.push_back(root->data);
            return;
        }

        addleaf(root->left,ans);
        addleaf(root->right,ans);


    }
    vector <int> boundary(TreeNode* root){
    	vector<int>ans;
        if(root == nullptr){
            return ans;
        }

        if(!isleaf(root)) ans.push_back(root->data);

        addleft(root,ans);
        addleaf(root,ans);
        addRight(root,ans);

        return ans;}



int main(){
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    vector<int> ans = boundary(root);

    for(auto s : ans){
        cout << s << " ";
    }
    return 0;
}