//stackdemoone.cpp
#include<iostream>
using namespace std;
template <typename T>
class stacko{
public:
    stacko():head(nullptr){}
    ~stacko(){
    if(head!=nullptr)
        delete head;
    }
    void push(const T &x){
    head=new node;
    head->data=x;
    head->next=nullptr;}
    T pop(){
    T result;
    result=head->data;
    delete head;
    return result;
    }
private:
    struct node{
    T data;
    node *next;};
    node *head;
};
int main(){
    cout<<"please";
    stacko<int> s;
    s.push(42);
    cout<<s.pop();
return 0;}
