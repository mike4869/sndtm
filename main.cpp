#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "mysorts.h"
#include "dataimport.h"
#include <fstream>
using namespace std;
 int main(){
vector<string> datasets = getNamesFromFile("dat_files.txt");
ofstream my_out("Times.txt");
if(!my_out.is_open()){
  cerr << "Error al abrir el archivo de salida " << "Times.txt"  << endl;
  exit(1);
}
for(int i = 0; i<4; i++){
cout << endl << "----" <<(i==0 ? "Distribucion uniforme" : (i == 1 ? "Distribucion normal" : (i==2 ? "Distribucion chi cuadrado" : "Distribucion poisson"))) << "----";
my_out << endl << "----" << (i==0 ? "Distribucion uniforme" : (i == 1 ? "Distribucion normal" : (i==2 ? "Distribucion chi cuadrado" : "Distribucion poisson")))<< "----";  
for(int j = 0; j<6; j++){
int size = (j==0? 40 : (j==1 ? 400 : (j==2 ? 800 : (j==3 ? 2000 : (j==4 ? 4000 : 8000)))));
cout << endl <<"Para un arreglo de " << size << " elementos." << endl;
my_out << endl <<"Para un arreglo de " << size << " elementos." << endl;
double sumI = 0, sumQ = 0, sumQr= 0;
for(int k = 0; k<10; k++){
    int index = 60*i + 10*j + k;
    double* array = importData(datasets[index]);
    double time = InsertionSort(array, size);
    sumI += time;
    cout << "Microsegundos por insercion: " << time << " " << is_sorted(array, size) << endl;
    array = importData(datasets[index]);
    time = quickSortIterative(array, 0, size);
    sumQ += time;
    cout << "Microsegundos por quicksort de forma iterativa: " << time << " " << is_sorted(array, size) <<endl;
      array = importData(datasets[index]);
    time = quicksort_R_time(array, 0, size);
    sumQr += time;
    cout << "Microsegundos por quicksort de forma recursiva: " << time << " " << is_sorted(array, size) <<endl;
}
cout << "Promedio por insercion: " << sumI/10 << ", por quicksort (iterativo): " << sumQ/10 << " y por quicksort (recursivo): " << sumQr/10 << endl;
my_out << "Promedio por insercion: " << sumI/10 << ", por quicksort (iterativo): " << sumQ/10 << " y por quicksort (recursivo): " << sumQr/10 << endl;
}
}
my_out.close();
system("pause");
return 0;
 }