#include <iostream>
#include <cmath>
using namespace std;

// Завдання 1.1: If12. Дано три числа. Знайти найменше з них.
void task_if12();
// Завдання 1.2: If29. Дано ціле число. Вивести його рядок-опис.
void task_if29();
// Завдання 2: Geom6. Чи потрапляє точка (x, y) у фігуру 6 варіанту (жовта).
void task_geom6();

int main() {
    int menu;
    cout << "Task number (1 - If12, 2 - If29, 3 - Geom6): ";
    cin >> menu;
    if (!cin) {                       // перевірка: введено не число
        cout << "Wrong task! (Only 1,2,3)" << endl;
        return 0;
    }
    // перемикання між завданнями
    switch (menu) {
        case 1: task_if12(); break;
        case 2: task_if29(); break;
        case 3: task_geom6(); break;
        default: cout << "Wrong task! (Only 1,2,3)" << endl; // повідомлення про помилку
    }
    return 0;
}

// If12: найменше з трьох чисел
void task_if12() {
    double a, b, c;
    cout << "************* If 12 *****************" << endl;
    cout << "Enter three numbers a b c: ";
    cin >> a >> b >> c;
    if (!cin) {                       // перевірка коректності введення
        cout << "Wrong numbers!" << endl;
        return;
    }
    double minimum = a;               // припускаємо, що найменше - перше
    if (b < minimum) minimum = b;
    if (c < minimum) minimum = c;
    cout << "Minimum = " << minimum << endl;
}

// If29: рядок-опис цілого числа (знак + парність)
void task_if29() {
    int n;
    cout << "************* If 29 *****************" << endl;
    cout << "Enter integer n: ";
    cin >> n;
    if (!cin) {                       // перевірка коректності введення
        cout << "Wrong integer!" << endl;
        return;
    }
    if (n == 0)
        cout << "zero number" << endl;               // нульове число
    else if (n < 0 && n % 2 == 0)
        cout << "negative even number" << endl;      // від'ємне парне
    else if (n < 0)
        cout << "negative odd number" << endl;       // від'ємне непарне
    else if (n % 2 == 0)
        cout << "positive even number" << endl;      // додатне парне
    else
        cout << "positive odd number" << endl;       // додатне непарне
}

// Geom6: велике коло радіуса r2 з центром (0,0), два внутрішні кола радіуса r1.
// Центри внутрішніх кіл лежать на прямій під 45 градусів на відстані a від початку:
// (-a/sqrt2, a/sqrt2) та (a/sqrt2, -a/sqrt2). Жовта область = велике коло мінус внутрішні.
void task_geom6() {
    double r1, r2, a, x, y;
    cout << "************* Geom 6 *****************" << endl;
    cout << "Enter r1 r2 a: ";
    cin >> r1 >> r2 >> a;
    if (!cin || r1 <= 0 || r2 <= 0 || a < 0 || a + r1 > r2) { // перевірка параметрів
        cout << "Wrong parameters!" << endl;
        return;
    }
    cout << "Enter point x y: ";
    cin >> x >> y;
    if (!cin) {                       // перевірка координат
        cout << "Wrong coordinates!" << endl;
        return;
    }
    double d = a / sqrt(2.0);         // зміщення центрів за осями
    bool inBig = x * x + y * y <= r2 * r2;                           // у великому колі
    bool inC1 = pow(x + d, 2) + pow(y - d, 2) < r1 * r1;             // у лівому верхньому червоному
    bool inC2 = pow(x - d, 2) + pow(y + d, 2) < r1 * r1;             // у правому нижньому червоному
    if (inBig && !inC1 && !inC2)
        cout << "Point is in the yellow area." << endl;
    else
        cout << "Point is NOT in the yellow area." << endl;
}
