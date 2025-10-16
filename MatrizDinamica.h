template <typename T>
class MatrizDinamica {

public:

    int filas;
    int columnas;
    T **datos;

    // constructor
    MatrizDinamica(int a, int b){

        filas = a;
        columnas = b;
        datos = nullptr;

    }

    // Copy constructor
    MatrizDinamica(const MatrizDinamica& otra) {
        filas = otra.filas;
        columnas = otra.columnas;
        datos = nullptr;
        if (filas > 0 && columnas > 0) {
            crearMatriz();
            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    datos[i][j] = otra.datos[i][j];
                }
            }
        }
    }

    // Copy assignment operator
    MatrizDinamica& operator=(const MatrizDinamica& otra) {
        if (this == &otra) {
            return *this;
        }

        if (datos != nullptr) {
            for (int i = 0; i < filas; i++) {
                delete[] datos[i];
            }
            delete[] datos;
        }

        filas = otra.filas;
        columnas = otra.columnas;
        datos = nullptr;

        if (filas > 0 && columnas > 0) {
            crearMatriz();
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    datos[i][j] = otra.datos[i][j];
                }
            }
        }
        return *this;
    }

    // metodo que crea la matriz.
    void crearMatriz(){

        try{

            datos = new T*[filas]; // creacion de las filas.

            // por cada fila crear n columnas.
            for(int i = 0; i < filas; i++){

                datos[i] = new T[columnas];

            };

            // inicializar todos los valores a 0
            for(int i = 0; i < filas; i++){

                for(int j = 0; j < columnas; j++){

                    datos[i][j] = 0;

                }

            }

        }

        catch(std::exception &e){

            std::cout << e.what() << std::endl;
            
        }

    }

    // metodo que redimensiona la matriz con un nuevo valor.
    void redimensionar(int nuevaF, int nuevaC){

        try{

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

            filas = nuevaF;
            columnas = nuevaC;

        }

        catch(std::exception &e){

            std::cout << e.what() << std::endl;

        }

    }

    ~MatrizDinamica(){

        try{

            // limpiar toda la matriz

            for(int i = 0; i < filas; i++){

                delete[] datos[i];

            }

            delete[] datos;
            datos = nullptr;

        }
        
        catch(std::exception &e){

            std::cout << e.what() << std::endl;

        }

    }   




};