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
    ChessBoardArray(unsigned size = 0, unsigned base = 0): sizee(size), b(base) {
        if(sizee%2==0){
            data = new int[(size * size)/2];
            for(int i=0;i<(size*size)/2;i++)
                data[i]=0;}
        else{
            data=new int[(size * size)/2+1];
            for(int i=0;i<(size*size)/2+1;i++)
                data[i]=0;
        }
    }
    ChessBoardArray(const ChessBoardArray &a) :sizee(a.sizee), b(a.b) {

        if(sizee%2==0){
            data = new int[(sizee * sizee)/2];
            for(int i=0;i<(sizee * sizee)/2;i++)
                data[i]=a.data[i];}
        else{
            data = new int[(sizee * sizee)/2+1];
            for(int i=0;i<(sizee * sizee)/2+1;i++)
                data[i]=a.data[i];
        }
    }
    ~ChessBoardArray(){ delete [] data; }
    ChessBoardArray & operator = (const ChessBoardArray &a){
        delete [] data;
        b = a.b;
        sizee = a.sizee;

        if(sizee%2==0){
            data = new int[(sizee * sizee)/2];
            for(int i=0;i<(sizee * sizee)/2;i++)
                data[i]=a.data[i];}
        else{
            data = new int[(sizee * sizee)/2+1];
            for(int i=0;i<(sizee * sizee)/2+1;i++)
                data[i]=a.data[i];
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





