#include <iostream>

using namespace std;

void murcielago(string);
char clave(char l);

int main(){
    string cad;

    cout << "Ingrese una cadena: \n";
    getline(cin, cad);

    murcielago(cad);

    return 0;
}

void murcielago(string cad){

    for (int  i = 0; i < cad.size(); i++)
    {
        char cad1 = cad[i];
        cad[i] = clave(cad1);
    }
    cout << cad;
}

char clave(char l){

    switch (l)
    {
    case 'm':
        return '0';
        break;
    case 'u':
        return '1';
        break;
    case 'r':
        return '2';
        break;
    case 'c':
        return '3';
        break;
    case 'i':
        return '4';
        break;
    case 'e':
        return '5';
        break;
    case 'l':
        return '6';
        break;
    case 'a':
        return '7';
        break;
    case 'g':
        return '8';
        break;
    case 'o':
        return '9';
        break;
    default:
    return l;
        break;
    }
}