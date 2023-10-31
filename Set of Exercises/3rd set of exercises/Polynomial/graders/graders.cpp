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
        if(p.meg>q.meg){
            Polynomial r(p);
            Term *i=q.head;
            while(i != nullptr){
                r.addTerm(i->exponent,i->coefficient);
                i=i->next;
            }
            return r;
        }else{
            Polynomial r(q);
            Term *i=p.head;
            while(i != nullptr){
                r.addTerm(i->exponent,i->coefficient);
                i=i->next;
            }
            return r;

        }
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
        int i=1;
        Term *h=p.head;
        bool negative;

        if(h->coefficient<0) {      out<<"- "; negative=true;}
        if(h->exponent==1){if(negative) out<<-h->coefficient<<"x"; else out<<h->coefficient<<"x";}
        else if(h->exponent==0){if(negative) out<<-h->coefficient; else out<<h->coefficient;}
        else if(h->coefficient==1)  out<<"x^"<<h->exponent;
        else {if(negative) out<<-h->coefficient<<"x^"<<h->exponent; else out<<h->coefficient<<"x^"<<h->exponent;}
        h=h->next;
        negative=false;

        while(h != nullptr){
            if(h->coefficient==0){
                h=h->next;
                //out<<i<<": "<<h->coefficient<<"x"<<endl;
            }else{
                if(h->coefficient>0) out<<" + ";
                else{ out<<" - "; negative=true;}

            if(h->exponent==1){if(negative) out<<-h->coefficient<<"x"; else out<<h->coefficient<<"x";}
            else if(h->exponent==0){if(negative) out<<-h->coefficient; else out<<h->coefficient;}
            else if(h->coefficient==1)  out<<"x^"<<h->exponent;
            else {if(negative) out<<-h->coefficient<<"x^"<<h->exponent; else out<<h->coefficient<<"x^"<<h->exponent;}
            h=h->next;
            negative=false;

            }
            i++;
        }
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


