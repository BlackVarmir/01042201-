#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

double число_з_рядка(string q) {
    int y, d;
    double res;
    d = 1;
    res = 0;
    for (int i = q.length() - 1; i >= 0; i--) {
        y = (int)q[i] - 48;
        res = y * d + res;
        d = d * 10;
    }
    return res;
}

double отримати_дробову_частину(string x) {
    double res;
    int d, y, temp;
    d = 1;
    temp = 0;
    for (int i = x.length() - 1; i >= 0; i--) {
        y = (int)x[i] - 48;
        temp = y * d + temp;
        d = d * 10;
    }
    res = temp;
    for (int i = 0; d != 1; i++) {
        res = res / 10;
        d = d / 10;
    }
    return res;
}

double отриматиЧисло(string x) {
    double res;
    char a = ',';
    int pos = x.find(a);
    if (x.find(a) == string::npos) {
        res = число_з_рядка(x);
        return res;
    }
    else {
        string y = x.substr(0, pos);
        string z = x.substr(pos + 1);
        int ціла = число_з_рядка(y);
        double дробова = отримати_дробову_частину(z);
        res = ціла + дробова;
        return res;
    }
}

double отриматиЧислоКрапка(string x) {
    double res;
    char a = '.';
    int pos = x.find(a);
    if (x.find(a) == string::npos) {
        res = число_з_рядка(x);
        return res;
    }
    else {
        string y = x.substr(0, pos);
        string z = x.substr(pos + 1);
        int ціла = число_з_рядка(y);
        double дробова = отримати_дробову_частину(z);
        res = ціла + дробова;
        return res;
    }
}

void вивід_через_кому(double x) {
    int a = x;
    double b = x - a;
    if (b == 0) {
        cout << x << endl;
    }
    else {
        string l = to_string(b);
        l.erase(0, 2);
        for (int i = l.length() - 1; i != 0; i--) {
            if (l[i] != '0') {
                break;
            }
            else {
                if (l[i] == '0') {
                    l[i] = ' ';
                }
                else {
                    continue;
                }
            }
        }
        cout << a << "," << l << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        cout << "1 - Вибрати дію додавання" << endl;
        cout << "2 - Вибрати дію віднімання" << endl;
        cout << "3 - Вибрати дію множення" << endl;
        cout << "4 - Вибрати дію ділення" << endl;
        cout << "0 - Завершити роботу програми" << endl;
        char choice;
        cin >> choice;
        if (choice == '1') {
            cout << "Введіть перше число:" << endl;
            string a;
            cin >> a;
            double x;
            if (a.find('.') != -1) {
                x = отриматиЧислоКрапка(a);
            }
            else {
                x = отриматиЧисло(a);
            }
            cout << "Введіть друге число:" << endl;
            string b;
            cin >> b;
            double y;
            if (b.find('.') != -1) {
                y = отриматиЧислоКрапка(b);
            }
            else {
                y = отриматиЧисло(b);
            }
            double res = x + y;
            if ((a.find('.') != -1) || (b.find('.') != -1)) {
                cout << res << endl;
            }
            else {
                вивід_через_кому(res);
            }
        }
        else if (choice == '2') {
            cout << "Введіть перше число:" << endl;
            string a;
            cin >> a;
            double x;
            if (a.find('.') != -1) {
                x = отриматиЧислоКрапка(a);
            }
            else {
                x = отриматиЧисло(a);
            }
            cout << "Введіть друге число:" << endl;
            string b;
            cin >> b;
            double y;
            if (b.find('.') != -1) {
                y = отриматиЧислоКрапка(b);
            }
            else {
                y = отриматиЧисло(b);
            }
            double res = x - y;
            if ((a.find('.') != -1) || (b.find('.') != -1)) {
                cout << res << endl;
            }
            else {
                вивід_через_кому(res);
            }
        }
        else if (choice == '3') {
            cout << "Введіть перше число:" << endl;
            string a;
            cin >> a;
            double x;
            if (a.find('.') != -1) {
                x = отриматиЧислоКрапка(a);
            }
            else {
                x = отриматиЧисло(a);
            }
            cout << "Введіть друге число:" << endl;
            string b;
            cin >> b;
            double y;
            if (b.find('.') != -1) {
                y = отриматиЧислоКрапка(b);
            }
            else {
                y = отриматиЧисло(b);
            }
            double res = x * y;
            if ((a.find('.') != -1) || (b.find('.') != -1)) {
                cout << res << endl;
            }
            else {
                вивід_через_кому(res);
            }
        }
        else if (choice == '4') {
            cout << "Введіть перше число:" << endl;
            string a;
            cin >> a;
            double x;
            if (a.find('.') != -1) {
                x = отриматиЧислоКрапка(a);
            }
            else {
                x = отриматиЧисло(a);
            }
            cout << "Введіть друге число:" << endl;
            string b;
            cin >> b;
            double y;
            if (b.find('.') != -1) {
                y = отриматиЧислоКрапка(b);
            }
            else {
                y = отриматиЧисло(b);
            }
            if (y == 0) {
                cout << "На нуль ділити не можна." << endl;
            }
            else {
                double res = x / y;
                if ((a.find('.') != -1) || (b.find('.') != -1)) {
                    cout << res << endl;
                }
                else {
                    вивід_через_кому(res);
                }
            }
        }
        else if (choice == '0') {
            break;
        }
        else {
            cout << "Ви зробили некоректний вибір." << endl;
        }
    }
}