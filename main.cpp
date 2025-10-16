#include <iostream>
#include "MatrizDinamica.h"


template<typename T>
void imprimirMatriz(const MatrizDinamica<T>& m);

template<typename T>
MatrizDinamica<T> multiplicacionMatriz(const MatrizDinamica<T>& A, const MatrizDinamica<T>& B);

int main() {

    // matriz dinamica A.
    MatrizDinamica<int> A(2, 3);
    A.crearMatriz();
    std::cout << "Se creo la matriz A correctamente." << std::endl;
    
    // Llenar matriz A con valores
    A.datos[0][0] = 1; A.datos[0][1] = 2; A.datos[0][2] = 3;
    A.datos[1][0] = 4; A.datos[1][1] = 5; A.datos[1][2] = 6;
    std::cout << "Matriz A:" << std::endl;
    imprimirMatriz(A);

    // matriz dinamica B.
    MatrizDinamica<int> B(3, 2);
    B.crearMatriz();
    std::cout << "Se creo la matriz B correctamente." << std::endl;
    // Llenar matriz B con valores
    B.datos[0][0] = 7; B.datos[0][1] = 8;
    B.datos[1][0] = 9; B.datos[1][1] = 10;
    B.datos[2][0] = 11; B.datos[2][1] = 12;
    std::cout << "Matriz B:" << std::endl;
    imprimirMatriz(B);

    MatrizDinamica<int> C = multiplicacionMatriz(A, B);

    std::cout << "Multiplicación de Matriz A y B (enteros):" << std::endl;
    imprimirMatriz(C);

    


    return 0;
}

template<typename T>
MatrizDinamica<T> multiplicacionMatriz(const MatrizDinamica<T>& A, const MatrizDinamica<T>& B) {
    if (A.columnas != B.filas) {
        std::cout << "No se puede realizar la operacion: Las columnas de la matriz A no coinciden con las filas de la matriz B" << std::endl;
        return MatrizDinamica<T>(0, 0);
    }

    MatrizDinamica<T> C(A.filas, B.columnas);
    C.crearMatriz();

    for (int i = 0; i < A.filas; i++) {
        for (int j = 0; j < B.columnas; j++) {
            for (int k = 0; k < A.columnas; k++) {
                C.datos[i][j] += A.datos[i][k] * B.datos[k][j];
            }
        }
    }

    return C;
}

template<typename T>
void imprimirMatriz(const MatrizDinamica<T>& m) {
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            std::cout << m.datos[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
