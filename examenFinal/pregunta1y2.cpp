#include <iostream>
using namespace std;

int numTriangular(int num){
    int i = 0;//asignacion 1
    int triangular = 0;// asignacion 1
    while (triangular < num){ //num +1
        i++;//asignacion num
        triangular = (i*(i+1))/2;//asignacion 4num
        }
        if(num == triangular){//asignacion 1
            cout<<"Su numero es triangular"<<endl;//asignacion 1
            return 0;//asignacion 1
        }else{//o
            cout<<"Su numero no es triangular, el triangular siguiente es:  "<<triangular<<endl;// asignacion 1
            return 0;//asignacion 1
    }
}

int numFuncion(int num){
    int res = 0;//asignacion 1
    int i = 1;// asignacion 1
    while (i < num) {//n
        i++;//n
        res += i;//2n
        return (num+((res*2)/num));//4n
    }
}

int main(){
    numFuncion(15);
    return 0;
}
