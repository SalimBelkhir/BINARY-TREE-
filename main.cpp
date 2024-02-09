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
    return 0;
}
