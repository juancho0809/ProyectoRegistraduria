#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream archivo("ejemplo.txt"); // Crear archivo
    if (archivo.is_open()) { // Verificar que se haya abierto correctamente
        archivo << "Este es un ejemplo de archivo de texto generado desde C++.\n";
        archivo << "Puedes escribir cualquier información aquí.\n";
        archivo << "¡Diviértete creando tus propios archivos!\n";
        archivo.close(); // Cerrar archivo
        cout << "Se ha generado el archivo 'ejemplo.txt' correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo 'ejemplo.txt'." << endl;
    }
    return 0;
}
