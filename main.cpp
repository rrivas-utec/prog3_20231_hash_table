#include <iostream>
#include <functional>
using namespace std;

void ejemplos_funciones_hash() {
    std::hash<string> hash_string_fn; // Objeto Funcion
    std::hash<double> hash_double_fn;

    cout
        << hash_string_fn("Universidad de Ingenieria y Tecnologia")
        << endl;

    cout
        << hash_double_fn(3.14156) << endl;

}
int main() {
    ejemplos_funciones_hash();
    return 0;
}
