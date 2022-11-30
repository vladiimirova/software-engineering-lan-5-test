// лб 3 іпз.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

void checkInputValidity() // функція перевіряє введені данні
{
    if (cin.fail())
    {
        throw "Incorrect input"; // виводить повідомлення
    }
}

void checkLoopBoundsValidity(int a, int b) // функція перевіряє чи є "a" більше "b"
{
    if (a >= b)
    {
        throw "Incorrect loop bounds input"; // виводить повідомлення
    }
}

void checkUpperBoundValidity(int n) // функція перевіряє, чи задовільняють введені дані "n' умові
{
    if (n < 2)
    {
        throw "Input upper bound input"; // виводить повідомлення
    }
}
void checkLoopStepValidity(int h) // функція перевіряє чи є "h" рівним або меншим за 0
{
    if (h <= 0)
    {
        throw "Incorrect step input"; //виводить повідомлення
    }
}

int calculate(int n, int a, int b, int h) // ця функція обчислює "y" використовуючи дані (a,b,h,n) 
{
    int y{}
    ;

    if (a > 0)
    {
        y = 1;
        for (int l = a; l <= b; l += h)
        {
            for (int i = 0; i <= n - 1; i++)
                y += (l) / i;
        }
        return y;
    }

    else
    {
        y = 0;

        for (int l = a; l <= b; l += h)
        {
            for (int i = 1; i <= n - 1; i++)
            {
                int k = 0;
                for (int j = 1; j < n; j++)
                {
                    k = k + (l - i + j);
                }
                y += k;
            }
        }
        return y;
    }
}


int main() // ця функціє запитує дані та обробляє винятки, якщо такі є
{
    int   a, b, h, n;

    try // відповідає за спроби перехопити винятки
    {
       
        cout << "Print a = "; // ввести значення a
        cin >> a;
        cout << "Print b = "; // ввести значення b
        cin >> b;
        checkInputValidity();
        checkLoopBoundsValidity(a, b);
        cout << "Print h = "; // ввести значення h
        cin >> h;
        checkInputValidity();
        checkLoopStepValidity(h);
        cout << "Print n >= 2, n = "; // ввести значення n
        cin >> n;
        checkInputValidity();
        checkUpperBoundValidity(n);

        for (a; a <= b; a += h)
        {
            cout << "x = " << a << " y = " << calculate( n, a, b, h) << endl;
        }
        cout << endl;
    }

    catch (const char* ex) // перехоплює винятки та негайно завершує роботу програми
    {
        cout << ex << endl;
        return -1;
    }
    catch (...)
    {
        cout << "Unknown error" << endl; // пеехоплює інші винятки та негайно завершує програму
        return -2;
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
