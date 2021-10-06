//Algoritmo de Division de Enteros

//Se aplicara el ejemplo desarrollado en clase (en este caso de 8 bits) con valores:
//      M=0011
//      Q=0111

#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main(){
    const int bits{8};  // Puede ser usada en cualquier cantidad de N bits (en este caso utilice de 8 bits)
    int count;
    count=bits;
    bitset<2>Result(string("00"));
    bitset<2>ResultP(string("00"));
    bitset<2>Val10(string("10"));
    bitset<bits*2>AQ;
    bitset<bits>M(string("11"));

    bitset<bits>Val1(string("1"));

    //      M=0000 1001=9
    //   Mneg=1111 0110
    // Mneg+1=1111 0111
    //      A=0000 0000=0
    //      S=1111 0111=-9  RESULTADO FINAL
    bitset<bits>Mneg;
    //Asignando los valores negados de M a M Negativo
    for(int i{0};i<bits;i++){
        if(M[i]){
            Mneg[i]=Val10[0];
        }
        else{Mneg[i]=Val10[1];}
    }
    //Sumando 1 al valor negado
    for(int i{0};i<bits;i++){
        Result=Mneg[i]+Val1[i]+Result[1];
        Mneg[i]=Result[0];
    }
    
    Result=ResultP;
    
    bitset<bits>Q(string("111"));
    for(int i=0;i<bits;i++)AQ[i]=Q[i];

    do{
        //Shift Left A,Q
        AQ=AQ<<1;

        //A<-A-M = A+Mneg
        for(int i{0};i<bits;i++){
            Result=AQ[i+bits]+Mneg[i]+Result[1];
            AQ[i+bits]=Result[0];
        }

        if(AQ[15]){//Verifica si A[15] es 1 or 0
            AQ[0]=Val10[0];
            for(int i{0};i<bits;i++){
            Result=AQ[i+bits]+M[i]+Result[1];
            AQ[i+bits]=Result[0];
        }
        }
        else{
            AQ[0]=Val10[1];
        }
        Result=ResultP;
        count--;
    }while(count>0);
    cout<<"El valor de AQ es: "<<AQ<<endl;
    cout<<"El valor del cociente Q es: ";
    for(int i=bits-1;i>=0;i--)cout<<AQ[i];
    cout<<endl;
    cout<<"El valor del residuo A es: ";
    for(int i=bits*2-1;i>=bits;i--)cout<<AQ[i];

    cout<<endl;

    //El valor de AQ es: 0000000100000010
    //El valor del cociente Q es: 00000010
    //El valor del residuo A es: 00000001
    return 0;
}
