
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
    State(int h, const int c[], int n);
    ~State();

    void next(const Move &move);//throw (logic_error);
    bool winning() const;
    int getHeaps() const;
    int getCoins(int h) const;
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
}

void State::next(const Move &move){//throw(logic_error) {

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
int State::getCoins(int h) const {
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
//apo edw kai kato

#include<iostream>
#include<string>
using namespace std;

class Player {
public:
    Player(const string &n){
        name=n;
    };
    virtual ~Player(){
        name.clear();
    };


    virtual const string & getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream & operator << (ostream &out, const Player &player);

protected:
    string name;
};

class GreedyPlayer : public Player {
public:
    GreedyPlayer(const string &n) : Player(n) {
        tipospaixti = "Greedy";
    }
    virtual const string & getType() const override {
        return tipospaixti;
    }

    virtual Move play(const State &s) override {
        int source_heap = 0;
        int source_coins = 0;
        for (int i=0; i<s.getHeaps() ; i++) {
            if ( s.getCoins(i) > source_coins) {
                source_heap = i;
                source_coins = s.getCoins(i);
            }
        }
        Move GreedyObject(source_heap, source_coins, 0, 0);
        return GreedyObject;
    }
private:
    string tipospaixti;
};

class SpartanPlayer : public Player{
public:
    SpartanPlayer (const string &n): Player(n){
        tipospaixti="Spartan";
    }
    virtual const string & getType() const override{//kathe fora
        return tipospaixti;//pou kalei tin gettype theloume na akolouthei afto
    }
    virtual Move play(const State &s) override{
        int fromthisheap=0,coinsfromhere=0;
        for(int i=0;i<s.getHeaps();i++){
            if(s.getCoins(i)>coinsfromhere){
                fromthisheap=i;
                coinsfromhere=s.getCoins(i);
            }
        }
        Move SpartanObject(fromthisheap,1,0,0);
        return SpartanObject;
    }
private:
    string tipospaixti;
};

class SneakyPlayer : public Player{
public:
    SneakyPlayer (const string &n): Player(n){
        tipospaixti="Sneaky";
    }
    virtual const string & getType() const override{
        return tipospaixti;
    }
    virtual Move play(const State &s) override {
        int nozero = 0;
        while ( s.getCoins(nozero) == 0){
            nozero++;
        }
        int fromthisheap = nozero;
        int coinsfromhere = s.getCoins(nozero);
        for (int i=nozero+1; i < s.getHeaps(); i++) {
            if ( (s.getCoins(i) < coinsfromhere) && (s.getCoins(i) > 0 )) {
                fromthisheap = i;
                coinsfromhere = s.getCoins(i);
            }
        }
        Move SneakyObject(fromthisheap, coinsfromhere, 0, 0);
        return SneakyObject;
    }

private:
    string tipospaixti;
};
class RighteousPlayer : public Player{
public:
    RighteousPlayer(const string &n): Player (n){
        tipospaixti="Righteous";
    }
    virtual const string & getType() const override{
        return tipospaixti;
    }
    virtual Move play(const State &s) override{
        int tothisheap = 0,fromthisheap = 0;//apo to heap(alpha) sto heap(beta)
        int coinsfromhere = s.getCoins(0),coinshere = coinsfromhere;//o logos pou vazo dio metavlites einai epd
        //thelw na vro to min kai max heap me ta nomismata pou exei

        for (int i=1; i < s.getHeaps(); i++) {
            if ( s.getCoins(i) > coinsfromhere) {
                fromthisheap = i;
                coinsfromhere = s.getCoins(i);
            }
            else if ( s.getCoins(i) < coinshere) {
                tothisheap = i;
                coinshere = s.getCoins(i);
            }
        }
        coinsfromhere -= coinsfromhere/2;//afou thelei na asxolithei me ta misa
        Move RighteousObject(fromthisheap, coinsfromhere, tothisheap, coinsfromhere - 1);
        return RighteousObject;

    }
private:
    string tipospaixti;
};

ostream & operator << (ostream &out, const Player &player){
    out<<player.getType()<<" player "<<player.name;
    return out;
}
//apo edw

class Game {
public:
    Game(int heaps, int players){
        hcount=0;
        pcount=0;
        myplayers=players;
        myheaps=heaps;
        heap_coins=new int [heaps];
        player_table = new Player*[players];
    };
    ~Game(){
        delete [] heap_coins;
        delete [] player_table;
    };

    void addHeap(int coins){// throw(logic_error){
        if (coins < 0) { throw logic_error ("Coins must not be a negative number"); }
            else if ( hcount >= myheaps ) { throw logic_error ("You cant put more heaps!!");}
            else {
                heap_coins[hcount] = coins;
                hcount++;
            }

    };
    void addPlayer(Player *player) {// throw(logic_error){
        if ( pcount >= myplayers) {throw logic_error("Player number exceeded!");}
            else {
                player_table[pcount] = player;
                pcount++;
                }


    };
    void play(ostream &out){// throw(logic_error){

            if ( (pcount != myplayers) && (hcount != myheaps)){
                throw logic_error("Incorrect number of heaps/players!");
            }
            else {
                int i = 0;
                State Stateobject(myheaps, heap_coins,myplayers);
                while ( !Stateobject.winning()){
                    out << "State: " << Stateobject << endl;
                    out << *player_table[i%myplayers] << " " << player_table[i%myplayers]->play(Stateobject) << endl;
                    Stateobject.next(player_table[i%myplayers]->play(Stateobject));

                    i++;
                }
                out << "State: " << Stateobject << endl;
                i--;
                out << *player_table[i%myplayers] << " wins" << endl;
            }

    };


    int getPlayers() const{
        return myplayers;
    };
    const Player *getPlayer(int p) const{// throw(logic_error){
        if ( p >myplayers ) {throw logic_error("Player number exceeded!");}
        return player_table[p];
    };
private:
    int hcount,pcount,myplayers,myheaps;
    int *heap_coins;
    Player **player_table;
};

//mexri edw
int main() {
Game specker(3, 4);
specker.addHeap(10);
specker.addHeap(20);
specker.addHeap(17);
specker.addPlayer(new SneakyPlayer("Tom"));
specker.addPlayer(new SpartanPlayer("Mary"));
specker.addPlayer(new GreedyPlayer("Alan"));
specker.addPlayer(new RighteousPlayer("Robin"));
specker.play(cout);
}