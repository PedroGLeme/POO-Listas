#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<double> notas(const string& s){
    vector<double> notas_ret;
    int i = 0;
    while (i < s.size()){
        while (i < s.size() && s[i] != ','){ i++;}// acha a primeira virgula
        i++; // pula a virgula
        // le o numero
        string numero;
        while (i< s.size() && s[i]!= ','){ // ate chegar no fim da string dada ou ate a virgula
            numero += s[i]; // contatena o numero
            i++;
        }
        // transforma streing em double
        if (!(numero.empty())){ notas_ret.push_back(stod(numero)); }
        i++; // pula a virgula do numero
    }

    return notas_ret;
}
 int main() {
    std::string s;
    std::getline(std::cin, s);
    for(double n : notas(s))
        std::cout << n << std::endl;
    return 0;
}