#include <iostream>
#include <cmath>
using namespace std;


class Polynomial {
protected:
    class Term {
    protected:
        int exponent;
        int coefficient;
        Term *next;
        Term(int exp, int coeff, Term *n):exponent(exp),coefficient(coeff),next(n){};
        friend class Polynomial;
        friend ostream & operator << (ostream &out, const Polynomial &p);
        friend Polynomial operator+ (const Polynomial &p, const Polynomial &q);
        friend Polynomial operator* (const Polynomial &p, const Polynomial &q);
    };
public:
    Polynomial(){
        head= new Term (0, 0, nullptr);
        meg=0;
    };

    Polynomial(const Polynomial &p){
        head= new Term(0,0, nullptr);
        meg=0;
        copy(p);
    };
    ~Polynomial(){
        purge();
    };

    Polynomial & operator = (const Polynomial &p){
        purge();

        head= new Term(0,0, nullptr);
        meg=0;
        copy(p);

        return *this;
    };

    void addTerm(int expon, int coeff){
        if(meg==0){
            head->coefficient=coeff;
            head->exponent=expon;
        }
        else {
            if(expon==head->exponent){
                head->coefficient+=coeff;
            }else{
            Term *q = new Term(expon,coeff, nullptr);
            Term *d=head;
            if(q->exponent>head->exponent){
                q->next=head;
                head=q;
            }
            else{
                while( (d->next) != nullptr && (d->next)->exponent>=q->exponent){
                d=d->next;

            }
            if(d->exponent==expon){
                d->coefficient+=coeff;
                if(d->coefficient==0) meg--;
                delete q;
            }else {
                Term *n = d->next;
                d->next = q;
                q->next = n;
            }
        }}}

        meg++;
    };
    double evaluate(double x){
        double s=0;
        for(Term *q = head; q != nullptr; q=q->next)
            s+=q->coefficient*pow(x,q->exponent);
        return s;
    };

    friend Polynomial operator+ (const Polynomial &p, const Polynomial &q){
             Polynomial r(p);
            Term *i=q.head;
            while(i != nullptr){
                r.addTerm(i->exponent,i->coefficient);
                i=i->next;
            }
            return r;
     };
    friend Polynomial operator* (const Polynomial &p, const Polynomial &q){//   ###
        Polynomial r;                                                      //   #####
        for(Term *i=p.head;i!= nullptr;i=i->next){
            for(Term *j=q.head;j!= nullptr; j=j->next){
                r.addTerm(i->exponent+j->exponent,i->coefficient*j->coefficient);
            }
        }
        return r;
    };

    friend ostream & operator << (ostream &out, const Polynomial &p){
        Term *h=p.head;
        bool negative=false;
        string answer;
        while(h!= nullptr && h->coefficient==0 ) h=h->next;
        if(h== nullptr){ out<<"0"; return out;}
        if(h->coefficient<0){ answer+="- "; negative=true; }
        if(abs(h->coefficient)==1 && h->exponent==0){ answer+="1"; }
        else if(abs(h->coefficient)==1 && h->exponent==1){ answer+="x"; }
        else if(h->exponent==0){ if(negative) answer+=to_string(-h->coefficient); else answer+=to_string(h->coefficient); }
        else if(abs(h->coefficient)==1){ answer+="x^"+to_string(h->exponent);  }
        else if(h->exponent==1){ if(negative) answer+=to_string(-h->coefficient)+"x"; else answer+=to_string(h->coefficient)+"x"; }
        else if(negative){  answer+=(to_string(-h->coefficient))+"x^"+(to_string(h->exponent));   }
        else{ answer+=(to_string(h->coefficient))+"x^"+(to_string(h->exponent));  }
        h=h->next;

        while(h != nullptr){
            while(h!= nullptr && h->coefficient==0) h=h->next;
            if(h== nullptr) break;
            negative=false;
            if(h->coefficient<0){ answer+=" - "; negative=true;} else answer+=" + ";
            if(abs(h->coefficient)==1 && h->exponent==0){ answer+="1"; }
            else if(abs(h->coefficient)==1 && h->exponent==1){ answer+="x"; }
            else if(h->exponent==0){ if(negative) answer+=to_string(-h->coefficient); else answer+=to_string(h->coefficient); }
            else if(abs(h->coefficient)==1){ answer+="x^"+to_string(h->exponent);  }
            else if(h->exponent==1){ if(negative) answer+=to_string(-h->coefficient)+"x"; else answer+=to_string(h->coefficient)+"x"; }
            else if(negative){  answer+=(to_string(-h->coefficient))+"x^"+(to_string(h->exponent));   }
            else{ answer+=(to_string(h->coefficient))+"x^"+(to_string(h->exponent));  }
                h=h->next;
        }
        out<<answer;
        return out;
    };
private:
    Term *head;
    int meg;
    void copy(const Polynomial &p){
        for(Term *q = p.head; q != nullptr; q=q->next)
        addTerm(q->exponent,q->coefficient);
    }
    void purge() {
        Term *p = head ;
        while (p != nullptr) {
            Term *q = p;
            p = p-> next;
            delete q;
        }
    }
};


int main() {
    Polynomial p; // 0
    p.addTerm(1, 3); // 3x

    p.addTerm(2, 1); // x^2
    p.addTerm(0, -1); // -1

    Polynomial q(p); // x^2 + 3x - 1
    q.addTerm(1, -3); // -3x

    cout << "P(x) = " << p << endl;
    cout << "P(1) = " << p.evaluate(1) << endl;
    cout << "Q(x) = " << q << endl;
    cout << "Q(1) = " << q.evaluate(1) << endl;
    cout << "(P+Q)(x) = " << p+q << endl;
    cout << "(P*Q)(x) = " << p*q << endl;
    }