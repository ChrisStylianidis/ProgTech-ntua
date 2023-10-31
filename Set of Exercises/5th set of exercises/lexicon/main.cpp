#include <iostream>
using namespace std;

class lexicon {
public:
 lexicon(){
     tree = nullptr;
 };
 ~lexicon(){
     purge(tree); tree = nullptr; };
 void insert(const string &s){
        tree = insert_aux(tree,s);};
 int lookup(const string &s) const{
     node *t = tree;
     if(t==nullptr) return 0;
     if(t->word==s) return t->times;
     while(t!=nullptr && t->word != s){
         if(t->word<s){
             if(t->right==nullptr) return 0;
             t=t->right;}
         else { if(t->left==nullptr) return 0;
             t=t->left;}}
     if(t==nullptr) return 0;
     return t->times;
 };
 int depth(const string &s) const{
     node *t = tree;
     if(t==nullptr) return -1;
     if(t->word==s) return 0;
     int position=0;
     while(t!=nullptr && t->word != s){
         position++;
         if(t->word<s){
             if(t->right==nullptr) return -1;
             t=t->right;}
         else { if(t->left==nullptr) return -1;
             t=t->left;}}
     if(t==nullptr) return -1;
     return position;};
 void replace(const string &s1, const string &s2){
     node *here1,*here2;
     if(lookup(s1)!=0){
     here1=position(s1);}
     else{return;}
     if(lookup(s2)!=0){
         here2=position(s2);
         here2->times+=here1->times;
     }else{
         tree=insert_aux(tree,s2);
         here2=position(s2);
         here2->times+=here1->times-1;
     }
     if(here1->left == nullptr && here1->right == nullptr){
         if(here1->parent->word>here1->word) {//aristera
         here1->parent->left = nullptr;
         delete here1;
         return;
         }
         here1->parent->right= nullptr;
         delete here1;
         return;
     }//first case
     if(here1->left == nullptr && here1->right != nullptr){
         if(here1->parent == nullptr){//here1==tree true
             tree=tree->right;
             tree->parent = nullptr;//pleon einai root
             delete here1;
             return;
         }else{
             if(here1->word<here1->parent->word){
                 here1->parent->left=here1->right;
                 here1->right->parent=here1->parent;
                 delete here1;
                 return;}
             else{
                 here1->parent->right=here1->right;
                 here1->right->parent=here1->parent;
                 delete here1;
                 return;}}
     }//second case
     if(here1->left != nullptr && here1->right == nullptr){
         if(here1->parent == nullptr){//here1==tree true
             tree=tree->left;
             tree->parent = nullptr;//pleon einai root
             delete here1;
             return;
         }else{
             if(here1->word<here1->parent->word){
                 here1->parent->left=here1->left;
                 here1->left->parent=here1->parent;
                 delete here1;
                 return;
             }
             else{
                 here1->parent->right=here1->left;
                 here1->left->parent=here1->parent;
                 delete here1;
                 return;}
         }
     }//third case
     if(here1->left != nullptr && here1->right != nullptr){
         node *need1,*need2;
         need1 = find_me(here1->left);
         need2 = here1->right;
         if(need1!=here1->left){
             need1->parent=here1->parent;
             if(need1->parent != nullptr){
                if(need1->word<need1->parent->word){
                    need1->parent->left=need1;
                }else{
                 need1->parent->right=need1;}}
         need1->right=need2;
         need2->parent=need1;
         if(need1!=here1->left){
         need1->left=here1->left;
             here1->left->parent=need1;
             if(here1==tree){tree=need1; delete here1; return;}
             else{ delete here1; return; }
         }else{
             need1->left = nullptr;
         }}
         else{
             need1->parent=here1->parent;
             need1->right=need2;
             need2->parent=need1;
             if(need1->parent == nullptr){
                 delete here1;
                 tree=need1;
                 return;}
             if(here1->word<here1->parent->word){
                 here1->parent->left=need1;
             }else{  here1->parent->right=need1; }
             delete here1;}
     }//forth case
 };
 friend ostream & operator << (ostream &out, const lexicon &l){
        node *t=l.tree;
         if(t!=nullptr){
             inorder_aux(t->left,out);
             out<<t->word<<" "<<t->times<<endl;
             inorder_aux(t->right,out);
         }
    return out;};
private:
    struct node{
        int times;
        string word;
        node *left,*right,*parent;
        node(const string &x,const int &t, node *l, node *r, node *p)
                : word(x),times(t),left(l), right(r), parent(p) {}
    };
    node *tree;
    node *position(const string &s){
        node *here=tree;
        while(here != nullptr && here->word!=s) {
            if (here->word < s)here = here->right;
            else here = here->left;
        }
        return here;
    }
    static void purge(node *t) {
        if (t != nullptr) {
            purge(t->left);
            purge(t->right);
            delete t;
        }
    }
    static void inorder_aux(node *t,ostream &out){
        if(t!=nullptr){
            inorder_aux(t->left,out);
            out<<t->word<<" "<<t->times<<endl;
            inorder_aux(t->right,out);
        }
    }
    node *insert_aux(node *t,const string &key){
        if(t==nullptr){
            node *p=new node(key,1,nullptr, nullptr, nullptr);
            return p;
        }
        if(t->word>key){ t->left=insert_aux(t->left,key); t->left->parent=t;}
        else if(t->word<key){ t->right=insert_aux(t->right,key); t->right->parent=t;}
        else if(t->word==key){ t->times+=1; }
        return t;
    }
    node *find_me(node *t){
        node *t1=t;
        while(t1->right != nullptr) t1=t1->right;
        if(t1!=t){
        if(t1->left != nullptr) {
            t1->parent->right = t1->left;
            t1->left->parent = t1->parent;
            t1->left = nullptr;
        }
        }
        return t1;
    }
};

