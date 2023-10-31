//check3.cpp
//check2.cpp
#include<iostream>
#include<iomanip>
#include<stdexcept>

using namespace std;

class ChessBoardArray {

protected:

    int *data;
    unsigned b, sizee;

    unsigned loc(int i,int j)const throw(out_of_range){
        int di = i-b, dj = j-b;
        if(di < 0 || di >= sizee || dj < 0 || dj >= sizee)
            throw out_of_range("invalid index");
        if((di + dj) % 2 != 0) throw out_of_range("black");
        return (di * sizee + dj) / 2;
    }

    class Row {
    public:
        Row(ChessBoardArray &a, int i) : arr(a), row(i) {}
        int & operator [] (int i) const{
            return arr.select(row, i);
        }
    private:
        ChessBoardArray &arr;
        int row;
    };

    class ConstRow {
    public:
        ConstRow(const ChessBoardArray &a, int i) : arr(a), row(i) {}
        int operator [] (int i) const{
            return arr.select(row, i);
        }
    private:
        const ChessBoardArray &arr;
        int row;

    };

public:
    ChessBoardArray(unsigned size = 0, unsigned base = 0): sizee(size), data(new int[size * size]), b(base) {

        if(sizee%2!=0){
            for(int i=0; i<sizee *sizee; i+=2){
                data[i]=0;
            }}
        else{
            int met=0;
            for(unsigned i=0;i<sizee/2; i++){
                for(int j=met;j<met+sizee;j+=2){
                    data[j]=0;
                }
                for(int j=met+sizee;j<met+2*sizee-1;j+=2){
                    data[j+1]=0;
                }
                met+=2*sizee;
            }
    }}
    ChessBoardArray(const ChessBoardArray &a) :sizee(a.sizee), data(new int[a.sizee * a.sizee]), b(a.b) {

        if(sizee%2!=0){
            for(int i=0; i<sizee *sizee; i+=2){
                data[i]=a.data[i];
            }}
        else{
            int met=0;
            for(unsigned i=0;i<sizee/2; i++){
                for(int j=met;j<met+sizee;j+=2){
                    data[j]=a.data[j];
                }
                for(int j=met+sizee;j<met+2*sizee-1;j+=2){
                    data[j+1]=a.data[j+1];
                }
                met+=2*sizee;
            }
    }

    }
    ~ChessBoardArray(){ delete [] data; }
    ChessBoardArray & operator = (const ChessBoardArray &a){
        delete [] data;
        b = a.b;
        sizee = a.sizee;
        data = new int[sizee * sizee];


        if(sizee%2!=0){
            for(int i=0; i<sizee *sizee; i+=2){
                data[i]=a.data[i];
            }}
        else{
            int met=0;
            for(unsigned i=0;i<sizee/2; i++){
                for(int j=met;j<met+sizee;j+=2){
                    data[j]=a.data[j];
                }
                for(int j=met+sizee;j<met+2*sizee-1;j+=2){
                    data[j+1]=a.data[j+1];
                }
                met+=2*sizee;
            }
    }



        return *this;
    }

    int & select(int i, int j){
        return data[loc(i, j)];
    }
    int select(int i, int j) const{
        return data[loc(i, j)];
    }
    const Row operator [] (int i){
        return Row(*this, i);
    }

    const ConstRow operator [] (int i) const{
        return ConstRow(*this, i);
    }


    friend ostream & operator << (ostream &out, const ChessBoardArray &a){
        for(int i = a.b; i < a.sizee+a.b; ++i){
            for(int j = a.b; j < a.sizee+a.b; ++j) {
                if ((i + j) % 2 != 0)
                    out << setw(4) << "0";
                else

                    out << setw(4) << a.data[a.loc(i, j)];

            }
            out << endl;
        }
        return out;
    }
};



