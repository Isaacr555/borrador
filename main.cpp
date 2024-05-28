#include <iostream>
#include "Lote.h"

int main() {
    const int numLotes = 10;
    Lote lotes[numLotes];

    // Lógica del menú aquí

    return 0;
}

//UNIR LOS DOS MAIN PARA QUE QUEDE EL MENU
int main() {
    const int numLotes = 10;
    Lote lotes[numLotes];

    // Lógica para comprar un lote
    try {
        comprarLote(lotes, numLotes, "Juan Perez", 12345, 2, "aspersión mecanizada", "todo incluido");
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    // Lógica para consultar los lotes
    string consulta;
    consultarLotes(lotes, numLotes, consulta);

    // Salida de la consulta (simulación sin cout)
    cout << consulta;

    return 0;
}
