/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    
    void splitString(string data, const char delim, vector<string> &d){
        stringstream ss(data);
        string s;
        while(getline(ss, s , delim)){
            d.push_back(s);
        }
    }
    void preOrder(TreeNode* root, string &ans){
        if(!root){
            ans += ",NULL";
            return;
        }
        
        ans += "," + to_string(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    string serialize(TreeNode* root) {
        string ans = "";
        preOrder(root, ans);
        return ans;
    }
    
    TreeNode* des(vector<string> &s, int &i){
        if(s[i] == "NULL"){
            i++;
            return NULL;
        }
        
        
        TreeNode* newNode = new struct TreeNode(stoi(s[i]));
        i++;
        newNode->left = des(s, i);
        newNode->right = des(s,i);
        
        return newNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        cout <<endl;
        vector<string> tokenised;
        splitString(data, ',', tokenised);
        for(int i = 0; i < tokenised.size();i++) cout <<tokenised[i] <<" ";
        int i = 1;
        return des(tokenised, i);
        
        
        //return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));