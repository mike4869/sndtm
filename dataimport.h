#include "mysorts.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
// Funciones para importar los juegos de datos creados en MATLAB
double* importData(string filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error opening file " << filename << endl;
    exit(1);
  }
  file.seekg(0, ios::end);
  int size = file.tellg();
  file.seekg(0, ios::beg);
  double* data = new double[size];
  string line;
  int i = 0;
  while (getline(file, line)) {
    stringstream ss(line);
    double value;
    ss >> value;
    data[i] = value;
    i++;
  }
  file.close();
  return data;
}

vector<string> getNamesFromFile(string filename) {
  ifstream file(filename);
  vector<string> names;
  string line;

  while (getline(file, line)) {
    names.push_back(line);
  }

  return names;
}