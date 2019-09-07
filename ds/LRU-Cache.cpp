#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<vector<int> > graph;
map<int,bool> visited;

struct Node {
    int key;
    string data;
    struct Node * next;
    struct Node * prev;
};

class LRU {
    private:
    map<int, Node*> store;
    Node * head;
    Node * tail;
    int size;
    int currentSize;


    void deleteNode(Node * node){

        if(!node) return;
        if(!head) return;

        if(!node->prev && !node->next){
            head = NULL;
            tail = NULL;
        }
        if(node->prev){
            node->prev->next = node->next;
        }
        if(node->next){
            node->next->prev = node->prev;
        } else{
            //update tail;
            tail = node->prev;
        }
        currentSize--;
        store[node->key] = NULL;
    }

    void addHead(Node * node){
        if(!head){
            head = node;
            tail = node;
        } else{
            node->next = head;
            head->prev=  node;
            head = node;
        }
        currentSize++;
        store[node->key] = node;
    }
    Node * getUtil(int key){
        Node * node = store[key];
        deleteNode(node);
        addHead(node);
        return store[key];
    }

    Node * getNode(int key, string value){
        Node * node = new struct Node;
        node->prev = node->next = NULL;
        node->key = key;
        node->data = value;
        return node;
    }

    public:
    LRU(int size){
        this->size = size;
        this->currentSize = 0;
        head = tail = NULL;
        
    }

    Node * get(int key){
        if(store[key] == NULL) return NULL;
        else{
            return getUtil(key);
        }
    }

    void put(int key, string value){
    
        auto node = getNode(key, value);
        if(store[key]) deleteNode(store[key]);
        if(currentSize == size){
            
            deleteNode(tail);
        }
        addHead(node);
      
        store[key] = node;
    }

    void printList(){
        auto cp = head;
        while(cp){
            cout <<cp->key <<"-" <<cp->data <<" ";
            cp = cp->next;
        }
        cout <<endl;
    }
   

};
int main(){
    LRU lru(3);
    while(true){
        int option, key;
        string value;
        cin >>option;

        if(option == 0){
            cin >>key;
            auto data = lru.get(key);
            if(data) cout <<data->key <<"-" <<data->data <<endl;
            else cout <<"-1\n";
        } else if(option == 1){
            cin >>key >> value;
            lru.put(key, value);
            lru.printList();
        } else{
            lru.printList();
        }
    }
}