//check.cpp
#include<iomanip>
#include<stdexcept>

using namespace std;

class ChessBoardArray {

 protected:

  int *data;
 unsigned basee, sizee;

 unsigned loc(int i,int j)const throw(out_of_range){
        int di = i-basee, dj = j-basee;
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
  ChessBoardArray(unsigned size = 0, unsigned base = 0): sizee(size), data(new int[size * size]), basee(base) {

    if(sizee%2!=0){
            for(int i=0; i<sizee *sizee; i+=2){
                data[i]=0;
            }}
        else{
            bool am=true;
            for(unsigned i=0;i<sizee; i++){
                if(am){
                    for(unsigned j=0;j<sizee;j+=2){
                        data[j]=0;
                    }
                    am=false;
                }
                else{
                    for(unsigned j=0;j<sizee-1;j+=2){
                        data[j+1]=0;
                    }
                    am=true;
                }
            }

        }
  }
  ChessBoardArray(const ChessBoardArray &a) :sizee(a.sizee), data(new int[a.sizee * a.sizee]), basee(a.basee) {
   for (unsigned i = 0; i < sizee * sizee; ++i)
    data[i] = a.data[i];
  }
  ~ChessBoardArray(){ delete [] data; }
  ChessBoardArray & operator = (const ChessBoardArray &a){
    delete [] data;
    basee = a.basee;
    sizee = a.sizee;
    data = new int[sizee * sizee];
    for (unsigned i = 0; i < sizee * sizee; ++i)
       data[i] = a.data[i];
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
        for(int i = a.basee; i < a.sizee + a.basee; ++i){
            for(int j = a.basee; j < a.sizee + a.basee; ++j){
                if(( i + j ) % 2 != 0 )
                  out << setw(4) << "0";
                else
                {   if ( a.data[a.loc(i,j)] == NULL )
                        out << setw(4) << "0";
                    else
                      out<< setw(4) << a.data[ a.loc(i,j) ] ;
                }
            }
            out << endl;
        }
    return out;
  }
 };


