
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
//se

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
    out << "takes " << move.sca << " coins from heap ";
    out << move.sha << " and puts ";
    if(move.tca == 0){
        out << "nothing";
        return out;
    }
    out << move.tca << " coins to heap " << move.tha ;
    return out;
}


class State {
public:
    // State with h heaps, where the i-th heap starts with c[i] coins.
    // A total of n players are in the game, numbered from 0 to n-1,
    // and player 0 is the first to play.
    State(int h, const int c[], int n);
    ~State();

    void next(const Move &move) throw (logic_error);
    bool winning() const;
    int getHeaps() const;
    int getCoins(int h) const throw (logic_error);
    int getPlayers() const;
    int getPlaying() const;

    friend ostream & operator << (ostream &out, const State &state);

private:
    int *coins, heaps, players;
    int temp ;
};


State::State(int h, const int c[], int n){
    coins = new int [h] ;
    heaps = h;
    players = n;
    for (int i = 0; i < heaps ; i++)
        coins [i] = c [i] ;
    temp = 0;
}
State::~State(){
    delete [] coins;
    return;
}

void State::next(const Move &move) throw(logic_error){

    if ( (move.getSource() < 0) || (move.getSource() > heaps)
         || (move.getTarget() < 0) || (move.getTarget() > heaps) ){
        throw logic_error("invalid heap");
        return;
    }

    else if ( (move.getSourceCoins() < 1) || (move.getTargetCoins() < 0) ||
              (move.getSourceCoins() <= move.getTargetCoins()) || ( move.getSourceCoins() > getCoins(move.getSource()) ))
        throw logic_error("invalid heap");

    else{
        coins[move.getSource()] -= move.getSourceCoins();
        coins[move.getTarget()] += move.getTargetCoins();
    }

    temp ++;
    if (temp == players)
        temp = 0;
}


bool State::winning() const{
    int win = 0;
    for (int i = 0; i < heaps; i++)
        win += getCoins(i);

    if ( win > 0)
        return false;
    return true;
}

int State::getHeaps() const{
    return heaps;
}
int State::getCoins(int h) const throw(logic_error){
    if ((h >= heaps) || (h < 0) ){
        throw logic_error("invalid heap");
    }
    else
        return coins[h];
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
        out << state.coins[k] << ", ";


    out << state.coins[k] <<" ";
    out << "with " << state.temp << "/" <<state. players << " playing next" ;
    return out;
}



class Player {
public:
    Player(const string &n);
    virtual ~Player();


    virtual const string & getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream & operator << (ostream &out, const Player &player);
private:

};


int main() {


    return 0;
}
