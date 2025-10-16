template <typename T>
class MatrizDinamica {
private:
    T **datos;
    int filas;
    int columnas;

public:

    // constructor
    MatrizDinamica(int filas, int columnas){

        this->filas = filas;
        this->columnas = columnas;

        crearMatriz();

    }

    // metodo que crea la matriz.
    void crearMatriz(){

        datos = new T*[filas]; // creacion de las filas.

        // por cada fila crear n columnas.
        for(int i = 0; i < filas; i++){

            datos[i] = new T[columnas];

        };

    }

    // metodo que redimensiona la matriz con un nuevo valor.
    void redimensionar(int nuevaF, int nuevaC){

        T **nuevaMat;

        nuevaMat = new T*[nuevaF]; // crear el vector de tipo puntero.

        for(int i = 0; i < nuevaF; i++){ // por cada fila asigno el valor de nueva columna.

            nuevaMat[i] = new T[nuevaC];

        }

        // copiar todos los elementos de la nueva matriz.
        for(int i = 0; i < nuevaF; i++){

            for(int j = 0; j < nuevaC; j++){

                nuevaMat[i][j] = datos[i][j]; // no estoy seguro si esta es la forma correcta.

            }

        }

        datos = nuevaMat; // el puntero doble datos se le asigna 

        for(int i = 0; i < nuevaF; i++){

            delete[] nuevaMat[i];

        }

        delete[] nuevaMat;

        nuevaMat = nullptr;


    }

    ~MatrizDinamica(){

        // limpiar toda la matriz

        for(int i = 0; i < filas; i++){

            delete[] datos[i];

        }

        delete[] datos;

    }   




};