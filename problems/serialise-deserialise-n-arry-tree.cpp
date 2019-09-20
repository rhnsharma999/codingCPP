/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    void preOrder(Node* root, string &ser){
        if(!root){
           
            return;
        }
        
        ser += " " + to_string(root->val);
        ser += " [";
        for(int i = 0; i < root->children.size();i++) preOrder(root->children[i], ser);
        ser += "] ";
    }
    
    string serialize(Node* root) {
        string ans = "";
        preOrder(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string s) {
        
        
        cout <<s <<endl;
        stack<Node*> store;
        
        Node* ptr;
        Node* root = NULL;
        for(int i = 0; i < s.size();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int ans = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    ans = ans * 10 + (s[i++] - '0');
                }
                Node* node = new struct Node(ans, {});
                if(!store.empty()){
                    cout <<(store.top())->val <<endl;
                    store.top()->children.push_back(node);
                    ptr = node;
                }
                else{
                    root = node;
                    ptr = node;
                }
            }
            else if(s[i] == '['){
                cout <<"pushing " <<(ptr ? -1 : ptr->val) <<endl;
                store.push(ptr);
            }
            else if(s[i] == ']') store.pop();
            else{
                continue;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));