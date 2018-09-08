#include <iostream>
#include <math/racional.hpp>
using namespace std;

void LeerEcu (Racional& a, Racional& b, Racional& c);
int SistEcu (Racional a1, Racional b1, Racional c1,
Racional a2, Racional b2, Racional c2,
Racional& x, Racional& y);
Racional Det (Racional a11, Racional a12,Racional a21, Racional a22);

int main()
{
    Racional a1, b1, c1, a2, b2, c2,
    x, y;
    int s;
    /* Entrada de datos */
    Racional a(4,5);
    Racional b(3,7);
    Racional c = a / b;
    cout << (a != b) << endl;
    a+=1;
    cout << "x = " << a.num() << " / " << a.den() << endl;
    cout << "x = " << c.num() << " / " << c.den() << endl;
    cout << "Ecuación 1 (a1*x + b1*y = c1):\n";
    LeerEcu(a1, b1, c1);
    cout << endl;
    cout << "Ecuación 2 (a2*x + b2*y = c2):\n";
    LeerEcu(a2, b2, c2);
    cout << endl;
    /* Cálculo de las soluciones */
    s = SistEcu(a1, b1, c1, a2, b2, c2, x, y);
    /* Salida de datos */
    if (s == 0){
        cout << "Solución:\n\n";
        cout << "x = " << x.num() << " / " << x.den() << endl;
        cout << "y = " << y.num() << " / " << y.den() << endl;
    }
    else if (s == -1)
        cout << "Sistema incompatible\n";
    else // s == 1
        cout << "Infinitas soluciones\n";
}

void LeerEcu (Racional& a, Racional& b, Racional& c){
    long num, den;
    cout << "Coeficiente de x:\n";
    cout << " Numerador = "; cin >> num;
    cout << " Denominador = "; cin >> den;
    a = Racional(num, den);
    cout << "Coeficiente de y:\n";
    cout << " Numerador = "; cin >> num;
    cout << " Denominador = "; cin >> den;
    b = Racional(num, den);
    cout << "Término independiente:\n";
    cout << " Numerador = "; cin >> num;
    cout << " Denominador = "; cin >> den;
    c = Racional(num, den);
}

int SistEcu (Racional a1, Racional b1, Racional c1,
Racional a2, Racional b2, Racional c2,
Racional& x, Racional& y){
    Racional A, B, C;
    A = Det(a1, b1, a2, b2);
    B = Det(c1, b1, c2, b2);
    C = Det(a1, c1, a2, c2);
    if (A.num() != 0)
    {
        x = B * inv(A);
        y = C * inv(A);
        return 0;
    }
    else if (B.num() != 0 && C.num() != 0)
        return -1; /* Sistema incompatible */
    else
        return 1; /* Infinitas soluciones */
}

Racional Det (Racional a11, Racional a12,
Racional a21, Racional a22){
    return a11 * a22 + -a21 * a12;
}
