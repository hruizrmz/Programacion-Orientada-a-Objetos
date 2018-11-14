#ifndef Cuadratica_h
#define Cuadratica_h
using namespace std;
class Cuadratica {
    public:
        Cuadratica();
        Cuadratica(int, int, int);
        void muestra();
        void Evalua(double);
        Cuadratica operator+ (Cuadratica e2);
        friend Cuadratica operator- (Cuadratica e1, Cuadratica e2);
        friend Cuadratica operator* (Cuadratica e1, int n);
        bool operator== (Cuadratica e2);
        void operator++(int);
        friend istream& operator>> (istream &is, Cuadratica &dato);
        friend ostream& operator<< (ostream &os, Cuadratica &dato);
    private:
        int iCoefA, iCoefB, iCoefC;
};
////////////////////////////////////////////////////////////////////
Cuadratica::Cuadratica() {
    iCoefA = 0;
    iCoefB = 0;
    iCoefC = 0;
}
Cuadratica::Cuadratica(int iA, int iB, int iC) {
    iCoefA = iA;
    iCoefB = iB;
    iCoefC = iC;
}
void Cuadratica::muestra() {
    if (iCoefA != 0){
        cout << iCoefA;
        cout << "x^2 ";
    }
    if (iCoefB != 0){
        if (iCoefB > 0)
            cout << " + ";
        cout << iCoefB;
        cout << "x ";
    }
    if (iCoefC != 0){
        if (iCoefC > 0)
            cout << " + ";
        cout << iCoefC << endl;
    }
}
void Cuadratica::Evalua(double x){
    x = (x * x * iCoefA) + (x * iCoefB) + (iCoefC);
    cout<<x<<endl;
}
////////////////////////////////////////////////////////////////////
Cuadratica Cuadratica::operator+(Cuadratica e2){
    int nA=iCoefA+e2.iCoefA;
    int nB=iCoefB+e2.iCoefB;
    int nC=iCoefC+e2.iCoefC;
    Cuadratica nCoef(nA,nB,nC);
    return nCoef;
}
Cuadratica operator- (Cuadratica e1,Cuadratica e2){
    int nA=e1.iCoefA-e2.iCoefA;
    int nB=e1.iCoefB-e2.iCoefB;
    int nC=e1.iCoefC-e2.iCoefC;
    Cuadratica nCoef(nA,nB,nC);
    return nCoef;
}
Cuadratica operator* (Cuadratica e1, int n){
    int nA=e1.iCoefA*n;
    int nB=e1.iCoefB*n;
    int nC=e1.iCoefC*n;
    Cuadratica nCoef(nA,nB,nC);
    return nCoef;
}
bool Cuadratica::operator== (Cuadratica e2){
    if ( (iCoefA==e2.iCoefA) && (iCoefB==e2.iCoefB) && (iCoefC==e2.iCoefC) )
        return true;
    else
        return false;
}
void Cuadratica::operator++(int n){
    iCoefA++;
    iCoefB++;
    iCoefC++;
}
////////////////////////////////////////////////////////////////////
istream& operator>> (istream &is, Cuadratica &dato){
    is>>dato.iCoefA;
    is>>dato.iCoefB;
    is>>dato.iCoefC;
    return is;
}
ostream& operator<< (ostream &os, Cuadratica &dato){
    if (dato.iCoefA!=0){
        if (dato.iCoefA<0)
            os<<dato.iCoefA<<"x^2";
        else
            os<<dato.iCoefA<<"x^2";
    }
    if (dato.iCoefB!=0){
        if (dato.iCoefB<0)
            os<<dato.iCoefB<<"x";
        else
            os<<" + "<<dato.iCoefB<<"x";
    }
    if (dato.iCoefC!=0){
        if (dato.iCoefC<0)
            os<<dato.iCoefC;
        else
            os<<" + "<<dato.iCoefC;
    }
    return os;
}
////////////////////////////////////////////////////////////////////
#endif /* Cuadratica_h */
