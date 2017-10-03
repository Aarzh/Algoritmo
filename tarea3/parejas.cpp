//Complejidad O(n)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string matchMaker(int n, std::string **H, std::string **M,std::string *mujeres, std::string *hombres);


int main(){

  int n = 3;


  std::vector<std::string> mujeres;
  mujeres.push_back("Juana");
  mujeres.push_back("Danna");
  mujeres.push_back("Pancha");

  std::vector<std::string> hombres;
  mujeres.push_back("Sebas");
  mujeres.push_back("Fulano");
  mujeres.push_back("Simon");
/*
for(int i = 0; i < n; i++){
  std::cout << M[i][0] << std::cout;
}
*/
  std::vector<std::vector<std::string>> H;
  H.push_back();
  std::string M[n][n] = {{"juana","Danna","Pancha"},{"juana","Pancha","Danna"},{"Pancha","juana","Danna"}};
  std::string H[n][n] = {{"Sebas", "Fulano", "Simon"},{"Fulano", "Sebas", "Simon"},{"Sebas", "Simon", "Fulano"}};

  std::string matchMaker(n, H , M , mujeres , hombres);


  return 0;
}






std::string matchMaker(int n, std::string **H, std::string **M,std::string *mujeres, std::string *hombres){
  for(int i = 0; i< n ; ++i){
    ninaAemparejar = mujeres[i];
    ninoAemparejar = hombres[i];
    if(ninaAemparejar == M[i][0]){
      std::cout << M[i][0] << std::cout;
    }

    for(int j = 0; j < n ; ++j){

    }
  }
}
