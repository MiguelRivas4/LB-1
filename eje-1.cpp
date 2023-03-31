#include <iostream>

using namespace std;

void imprimirMatriz(int** matriz, int tam){
    //imprimiendo matriz
    int salto = 0;
    for(int k = 0; k < tam*tam; k++){
        if (salto != 2)
        {
            cout << matriz[k/tam][k%tam]<<" ";
            salto++;
        }
        else
        {
            cout << matriz[k/tam][k%tam] << endl;
            salto=0;
        }
        
    }
}

string esDiagonal(int** matriz, int tam) {
    // Verificar que los elementos fuera de la diagonal sean cero
    for(int k = 0; k < tam*tam; k++){
        int fila = k/tam, col = k%tam;

        if (fila != col && matriz[fila][col] != 0)
        {
            return "No es diagonal";
        }
    }

    return "Es diagonal";
}

string esSimetrica(int** matriz, int tam) {
    // Verificar que los elementos fuera de la diagonal sean cero
    for(int k = 0; k < tam*tam; k++){
        int fila = k/tam, col = k%tam;

        if (matriz[fila][col] != matriz[col][fila])
        {
            return "No es simetrica";
        }
    }

    return "Es simetrica";
}

void sustituirOcurrencias(int** matriz, int tam, int a, int b) {
    // Verificar que los elementos fuera de la diagonal sean cero
    for(int k = 0; k < tam*tam; k++){
        int fila = k/tam, col = k%tam;

        if (matriz[fila][col] == a)
        {
            matriz[fila][col] = b;
        }
    }
}

string filaIgualColumna(int** matrizA, int** matrizB, int n, int f, int c) {
    // Verificar si la fila f de A es igual a la columna c de B
    for (int i = 0; i < n; i++) {
        if (matrizA[f][i] != matrizB[i][c]) {
            return "La fila F de la matriz A no es igual a la columna C de la matriz B";
        }
    }

    return "La fila F de la matriz A es igual a la columna C de la matriz B";
}

string intercambiarFilas(int** matriz, bool flag,int n, int a, int b) {
    //Si es true deberá intercambiar las filas a y b, si es false deberá intercambiar las columnas a y b.
    int aux;
    for (int i = 0; i < n; i++) {
        if (flag) {
            aux = matriz[a][i];
            matriz[a][i] = matriz[b][i];
            matriz[b][i] = aux;

        }else{
            aux = matriz[i][a];
            matriz[i][a] = matriz[i][b];
            matriz[i][b] = aux;

        }
    }
    return "INTERCAMBIO REALIZADO";
}

bool buscarCadena(char** matriz, string cadena, int tam) {
    // Buscar la cadena en las filas
    for (int i = 0; i < tam; i++) {
        if (matriz[i][0] == cadena[0] && matriz[i][1] == cadena[1] && matriz[i][2] == cadena[2]) {
            return true;
        }
    }

    // Buscar la cadena en las columnas
    for (int j = 0; j < tam; j++) {
        if (matriz[0][j] == cadena[0] && matriz[1][j] == cadena[1] && matriz[2][j] == cadena[2]) {
            return true;
        }
    }

    // Buscar la cadena en la diagonal principal
    if (matriz[0][0] == cadena[0] && matriz[1][1] == cadena[1] && matriz[2][2] == cadena[2]) {
        return true;
    }

    // Buscar la cadena en la diagonal secundaria
    if (matriz[0][2] == cadena[0] && matriz[1][1] == cadena[1] && matriz[2][0] == cadena[2]) {
        return true;
    }

    // Si no encontramos la cadena, devolvemos false
    return false;
}

int main() {
    int tam=3;

    //creando filas
    int** mDiagonal = (int**) malloc(sizeof(int*)*tam);
    int** mSimetrica = (int**) malloc(sizeof(int*)*tam);
    char** mCaracteres = (char**) malloc(sizeof(char*)*tam);

    //creado columnas
    for(int i = 0; i < tam; i++){
        *(mDiagonal + i) = (int*) malloc(sizeof(int)*tam);
        *(mSimetrica + i) = (int*) malloc(sizeof(int)*tam);
        *(mCaracteres + i) = (char*) malloc(sizeof(char)*tam);
    }

    //llenado matrices
    mDiagonal[0][0] = 1;
    mDiagonal[0][1] = 1;
    mDiagonal[0][2] = 1;
    mDiagonal[1][0] = 2;
    mDiagonal[1][1] = 2;
    mDiagonal[1][2] = 2;
    mDiagonal[2][0] = 3;
    mDiagonal[2][1] = 3;
    mDiagonal[2][2] = 3;

    mSimetrica[0][0] = 0;
    mSimetrica[0][1] = 2;
    mSimetrica[0][2] = 3;
    mSimetrica[1][0] = 1;
    mSimetrica[1][1] = 5;
    mSimetrica[1][2] = 4;
    mSimetrica[2][0] = 1;
    mSimetrica[2][1] = 2;
    mSimetrica[2][2] = 1;

    mCaracteres[0][0] = 'a';
    mCaracteres[0][1] = 'f';
    mCaracteres[0][2] = 'c';
    mCaracteres[1][0] = 'd';
    mCaracteres[1][1] = 'b';
    mCaracteres[1][2] = 'f';
    mCaracteres[2][0] = 'g';
    mCaracteres[2][1] = 'h';
    mCaracteres[2][2] = 'c';

    //cout<<esDiagonal(mDiagonal, tam)<<endl;

    //cout<<esSimetrica(mSimetrica, tam)<<endl;

    //cout<<"Sustituir ocurrencias"<<endl;
    //sustituirOcurrencias(mDiagonal,tam,0,3);

    //cout<<filaIgualColumna(mDiagonal,mSimetrica,tam,1,0)<<endl;

    cout<<"MATRIZ ORIGINAL"<<endl;
    imprimirMatriz(mDiagonal,tam);

    cout<<intercambiarFilas(mDiagonal,false,tam,0,1)<<endl;

    cout<<"MATRIZ NUEVA"<<endl;
    imprimirMatriz(mDiagonal,tam);
    


    string cadena = "abc";
    if (buscarCadena(mCaracteres, cadena, tam)) {
        cout << "La cadena " << cadena << " se encuentra en la matriz" << endl;
    } else {
        cout << "La cadena " << cadena << " no se encuentra en la matriz" << endl;
    }

    //liberar espacio
    for(int i = 0; i < tam; i++){
        free (*(mDiagonal + i));
        free (*(mSimetrica + i));
    }
    free(mDiagonal);
    free(mSimetrica);

    return 0;
}