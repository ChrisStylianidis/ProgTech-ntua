#include <iostream>
#include <stdexcept>

using namespace std;

class Move {
public:
    Move(int sh, int sc, int th, int tc);

    int getSource() const;
    int getSourceCoins() const;
    int getTarget() const;
    int getTargetCoins() const;

    friend ostream & operator << (ostream &out, const Move &move);
private:
    int sha, tha, sca, tca;
};

Move::Move(int sh, int sc, int th, int tc){

    sha=sh;
    sca=sc;
    tha=th;
    tca=tc;
}

int Move::getSource() const{
    return sha;
}

int Move::getSourceCoins() const{
    return sca;
}

int Move::getTarget() const{
    return tha;
}

int Move::getTargetCoins() const{
    return tca;
}

ostream & operator << (ostream &out, const Move &move){

    out<<"takes "<<move.sca<<" coins from heap ";
    out<<move.sha<<" and puts ";
    if(move.tca==0){
        out<<"nothing";
        return out;}
    out<<move.tca<<" coins to heap "<<move.tha;
    return out;
}


class State {
public:
    // State with h heaps, where the i-th heap starts with c[i] coins.
    // A total of n players are in the game, numbered from 0 to n-1,
    // and player 0 is the first to play.
    State(int h, const int c[], int n);
    ~State();

    void next(const Move &move) throw(logic_error);
    bool winning() const;
    int getHeaps() const;
    int getCoins(int h) const throw(logic_error);
    int getPlayers() const;
    int getPlaying() const;

    friend ostream & operator << (ostream &out, const State &state);

private:
    int *kermata, stoives, players;
    int temp ;
};


State::State(int h, const int c[], int n){
    kermata = new int [h] ;
    stoives = h;
    players = n;
    for (int i = 0; i < stoives ; i++)
        kermata [i] = c [i] ;
    temp = 0;
}
State::~State(){
    delete [] kermata;
    return;
}

void State::next(const Move &move) throw(logic_error){

    if ( (move.getSource() < 0) || (move.getSource() > stoives)
         || (move.getTarget() < 0) || (move.getTarget() > stoives) ){
        throw logic_error("invalid heap");
        return;
    }

    else if ( (move.getSourceCoins() < 1) || (move.getTargetCoins() < 0) ||
              (move.getSourceCoins() <= move.getTargetCoins()) || ( move.getSourceCoins() > getCoins(move.getSource()) ))
        throw logic_error("invalid heap");

    else{
        kermata[move.getSource()] -= move.getSourceCoins();
        kermata[move.getTarget()] += move.getTargetCoins();
    }

    temp ++;
    if (temp == players)
        temp = 0;
}


bool State::winning() const{
    int win = 0;
    for (int i = 0; i < stoives; i++)
        win += getCoins(i);

    if ( win > 0)
        return false;
    return true;
}

int State::getHeaps() const{
    return stoives;
}
int State::getCoins(int h) const throw(logic_error){
    if ((h >= stoives) || (h < 0) ){
        throw logic_error("invalid heap");
    }
    else
        return kermata[h];
}

int State::getPlayers() const{
    return players;
}
int State::getPlaying() const{
    return temp ;
}

ostream & operator << (ostream &out, const State &state){
    int k;
    for (k = 0; k < state.getHeaps()-1 ; k++)
        out << state.kermata[k] << ", ";


    out << state.kermata[k] <<" ";
    out << "with " << state.temp << "/" <<state. players << " playing next" ;
    return out;
}
int main(){

        Move r(1,2,3,4);
        cout<<r<<endl;
        int c[3];
        c[0]=0;
        c[1]=20;
        c[2]=17;
        State s(3,c,5);
        cout<<s<<endl;


        return 0;


}