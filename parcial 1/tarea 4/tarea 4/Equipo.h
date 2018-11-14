#ifndef Equipo_h
#define Equipo_h
#include <iomanip>
using namespace std;

class Equipo {
    public:
        Equipo();
    
        void setNom(string);
        void setGame(int);
        void setWin(int);
        void setTie(int);
    
        string getNom();
        int getGame();
        int getWin();
        int getTie();
    
        void newWin(int);
        void calcScore();
        void printList();
    
    private:
        string nom;
        int game,win,tie,score;
};

//  constructor default
Equipo::Equipo(){
    nom="";
    game=0;
    win=0;
    tie=0;
    score=0;
}

//  metodos de modificacion
void Equipo::setNom(string nom){
    this->nom=nom;
}
void Equipo::setGame(int game){
    this->game=game;
}
void Equipo::setWin(int win){
    this->win=win;
}
void Equipo::setTie(int tie){
    this->tie=tie;
}

//  metodos de acceso
string Equipo::getNom(){
    return nom;
}
int Equipo::getGame(){
    return game;
}
int Equipo::getWin(){
    return win;
}
int Equipo::getTie(){
    return tie;
}

//  metodos de operaciones
void Equipo::newWin(int wins){ // modifica el numero de partidos jugados y ganados
    game+=wins;
    win+=wins;
}
void Equipo::calcScore(){ // calcula el puntaje del equipo
    score=(win*3)+(tie);
}
void Equipo::printList(){ // imprime la informacion de los partidos de cada equipo
    cout<<nom<<setw(10)<<game<<setw(10)<<tie<<setw(10)<<win<<setw(10)<<score<<endl;
}

#endif /* Equipo_h */
