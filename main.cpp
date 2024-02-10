#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
    int data ;
    Node* left_node ;
    Node* right_node ;
    Node(int d): data(d) ,left_node(nullptr),right_node(nullptr){}
};

class Tree {
    private :
        Node* head ;
    public:
        Tree() : head(nullptr){}

        void show(Node* current) {
        if (!current) {
            return;
        }

        queue<Node*> q;
        q.push(current);

        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                Node* node = q.front();
                q.pop();

                if (node) {
                    cout << node->data << " ";
                    q.push(node->left_node);
                    q.push(node->right_node);
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }

        void insert_left(int x){
            Node* nov = new Node(x);
            nov->data = x;
            if(!head)
                {
                cout << "The tree is empty !"<<endl;
                }
            else if(!head->left_node)
            {
               nov->left_node = nullptr;
               nov->right_node=nullptr;
               head->left_node = nov;
            }
            else
            {
               Node* next = head->left_node;
               head->left_node = nov ;
               nov->left_node = next ;
               nov->right_node = nullptr;
            }
        }

        void insert_right(int x){
            Node* nov = new Node(x);
            nov->data = x;
            if(!head)
                {
                cout << "The tree is empty !"<<endl;
                }
            else if(!head->right_node)
            {
               nov->left_node = nullptr;
               nov->right_node=nullptr;
               head->right_node = nov;
            }
            else
            {
               Node* next = head->right_node;
               head->right_node = nov ;
               nov->right_node = next ;
               nov->left_node = nullptr;
            }
        }

        void insert_debut(int x){
            Node* nov = new Node(x);
            if(!head){head = nov ;}
            else{
                if(head->left_node && head->left_node->data < x){
                insert_right(x);
                }else{
                    insert_left(x);
                }
            }
        }

        Node* get_root() {
            return head ;
        }
        //recursive methode
        bool recherche(Node* current,int x){
            if(!current){return false;}
            if(current->data == x){
                return true;
            }
            if(x>current->data){
                    recherche(current->right_node,x);
                }
            if(x<current->data){
                    recherche(current->left_node,x);
                }
            return true ;
        }
        //methode withe a FIFO queue using breadth-first search algorithm
        bool recherche2(Node* root, int x) {
        if (!root) {
          cout << "the data doesn't exist cuz the tree is empty" << endl;
          return false;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
          Node* current = q.front();
          q.pop();

          if (current->data == x) {
              cout << "the data exists in the tree" << endl;
              return true;
          }

          if (current->left_node) {
              q.push(current->left_node);
          }

          if (current->right_node) {
             q.push(current->right_node);
          }
          }

         cout << "the data doesn't exist in the tree" << endl;
         return false;
          }

          void invert_tree(Node* current)
          {
              if(!current){
                cout << "if this message printed tow times -> the code is working" << endl;
                return ;
              }
              Node* x = current->left_node ;
              current->left_node= current->right_node ;
              current->right_node = x ;
                    if(current->left_node && current->right_node){
                        invert_tree(current->left_node);
                        invert_tree(current->right_node);
                    }else if(current->left_node){
                        current = current->left_node ;
                        invert_tree(current);
                    }else{
                        current = current->right_node;
                        invert_tree(current);
                    }

                }


};


int main()
{
    Tree t = Tree() ;
    t.insert_debut(2);
    t.insert_debut(3);
    t.insert_debut(7);
    t.insert_debut(5);
    t.insert_debut(1);
    t.insert_debut(6);
    t.show(t.get_root());
    t.invert_tree(t.get_root());
    t.show(t.get_root());
    int a ;
    cout << "put the a value and see if it's existing in your tree or not" << endl;
    cin >> a ;
    if(t.recherche(t.get_root(),a)){
        cout << "the value " << a << " does exist" << endl;
    }else{
        cout <<"the value " << a <<" doesn't exist" << endl;
    }
    return 0;
}
