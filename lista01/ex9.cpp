#include <iostream>
#include <cmath>      
#include <iomanip>

using namespace std;

int main() {
    double x1, y1, x2, y2;

    // Leitura dos valores
    cin >> x1 >> y1 >> x2 >> y2;

    // Cálculo da distância euclidiana
    double dist;
    dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    // Exibe a distância com 4 casas decimais
    cout << setprecision(5) << dist << endl;

    return 0;
}
