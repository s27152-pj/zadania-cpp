#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cout << "Ile jest kawalkow pizzy: " << a << endl;
    cout << "Gosci jest: " << b << endl;
    c = a % b;
    d = a / b;
    cout << "Goscie dostali po tyle kawalkow pizzy: " << d << endl;
    cout << "Organizatorzy dostali tyle kawalkow pizzy: " << c << endl;
    return 0;
}
