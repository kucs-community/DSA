#include<iostream>
#include<vector>

using namespace std;


//Definition for a binary tree node.

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution{
    public:
        vector<int> inOrder(TreeNode* p){

            vector<int> left,right;

            if (p->left)
                left = inOrder(p->left);

            if (p)
                left.push_back(p->val);

            if(p->right)
                right = inOrder(p->right);

            left.insert(left.end(), right.begin(), right.end());

            return left;
        };


        bool isSameTree(TreeNode* p, TreeNode* q){

            vector<int> first,second;

            first = inOrder(p);
            second = inOrder(q);

            if(first.size() != second.size()) return false;

            for(int i = 0; i < first.size(); ++i){

                if(first[i] != second[i])
                    return false;
            }
            
            return true;
        };


};

int main(){
    cout<<"Hello"<<endl;
    return 0;
}