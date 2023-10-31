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
