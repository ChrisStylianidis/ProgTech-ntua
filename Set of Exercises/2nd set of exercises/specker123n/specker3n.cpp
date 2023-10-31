//specker3n.cpp
#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

class Game {
public:
    Game(int heaps, int players){
        heapscounter = 0;
        playerscounter = 0;
        paixtes = players;
        stoives = heaps;
        kermata = new int [stoives];
        trapezipaixtwn = new Player*[paixtes];
    };
    ~Game(){
        delete [] kermata;
        delete [] trapezipaixtwn;
    };

    void addHeap(int coins) throw(logic_error){
        if (coins < 0) { throw logic_error ("Coins cannot be negative"); }
            else if ( heapscounter >= stoives )  {throw logic_error ("You cant put more heaps");}
            else {
                kermata[heapscounter] = coins;
                heapscounter++;
            }
    };
    void addPlayer(Player *player) throw(logic_error){
        if ( playerscounter >= paixtes) {throw logic_error("Player number exceeded");}
            else{
                trapezipaixtwn[playerscounter] = player;
                playerscounter++;}


    };
    void play(ostream &out) throw(logic_error){

            if ( (playerscounter != paixtes) && (heapscounter != stoives)){
                throw logic_error("Incorrect number of heaps/players");
            }
            else {
                int i = 0;
                State Stateobject(stoives, kermata, paixtes);
                while ( !Stateobject.winning()){
                    out << "State: " << Stateobject << endl;
                    out << *trapezipaixtwn[i % paixtes] << " " << trapezipaixtwn[i % paixtes]->play(Stateobject) << endl;
                    Stateobject.next(trapezipaixtwn[i % paixtes]->play(Stateobject));

                    i++;
                }
                out << "State: " << Stateobject << endl;
                i--;
                out << *trapezipaixtwn[i % paixtes] << " wins" << endl;
            }

    };


    int getPlayers() const{
        return paixtes;
    };
    const Player *getPlayer(int p) const throw(logic_error){
        if (p > paixtes )
            throw logic_error(" error ");
        return trapezipaixtwn[p];
    };
private:
    int heapscounter, playerscounter, paixtes, stoives;
    int *kermata;
    Player **trapezipaixtwn;
};
