#include <iostream>
using namespace std;

template <typename T>
class stack {
public:

    stack (const int size) {
        top=0;
        megethos=size;
        a=new T[size];
    }

    stack (const stack &s) {
        megethos=s.megethos;
        a=new T[megethos];
        for(int i=0;i<s.top;i++)
            a[i]=s.a[i];
        top=s.top;

    }

    ~stack () {delete [] a;}



  const stack & operator = (const stack &s) {
        delete [] a;
        megethos=s.megethos;
        a=new T[megethos];
        for(int i=0; i<s.top; i++){
           a[i]=s.a[i];
        }
      top=s.top;
       return *this;

    }

    bool empty () { return top==0;}


    void push (const T &x) {
        a[top++]=x;
    }


    T pop () {
        T result=a[--top];
        return result;
    }
    int size () {return top;}
    friend ostream & operator << (ostream &out, const stack &s) {

        out<<"[";
         T *p;
         int i=0;
        p =s.a;
         if(s.top!=0) {
             for (i=0; (i+1)<s.top; i++) {
                 out << *p << ", ";
                p++;

             }
             out<<*p<<"]";
             return out;

             }
         out<<"]";
        return out;
    }


private:
      T *a;
      int top,megethos;

};
#ifndef CONTEST
int main () {
 // let’s play with integers...
stack<int> s(10);

cout << "s is empty: " << s << endl;

s.push(42);
cout << "s has one element: " << s << endl;
s.push(17);
s.push(34);
cout << "s has more elements: " << s << endl;
cout << "How many? " << s.size() << endl;
stack<int> t(5);
t.push(7);
cout << "t: " << t << endl;
t = s;
cout << "popping from s: " << s.pop() << endl;
s.push(8);
stack<int> a(s);
t.push(99);
a.push(77);
cout << "s: " << s << endl;
cout << "t: " << t << endl;
cout << "a: " << a << endl;
// now with doubles...
stack<double> c(4);
c.push(3.14);
c.push(1.414);
cout << "c contains doubles " << c << endl;
// and with characters...
stack<char> k(4);
k.push('$');
cout << "k contains a character " << k << endl;
return 0;
}
#endif
