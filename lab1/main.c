#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, c;
    double xn, xk, dx;
    double x, F;

    // Ввод параметров функции
    printf("Введите a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Ввод интервала
    printf("Введите начало интервала xn: ");
    scanf("%lf", &xn);

    printf("Введите конец интервала xk: ");
    scanf("%lf", &xk);

    printf("Введите шаг dx: ");
    scanf("%lf", &dx);

    // Проверка шага
    if (dx <= 0)
    {
        printf("Ошибка: шаг должен быть больше 0.\n");
        return 0;
    }

    // Проверка интервала
    if (xn > xk)
    {
        printf("Ошибка: xn должен быть меньше или равен xk.\n");
        return 0;
    }

    // Заголовок таблицы
    printf("\n");
    printf("       x              F(x)\n");
    printf("--------------------------------\n");

    // Табулирование функции
    for (x = xn; x <= xk + 0.0000001; x = x + dx)
    {
        // Первый случай:
        // F = a*sin(x) - ln(x)/(c+b)
        if (x < c && a != 0)
        {
            // ln(x) существует только при x > 0
            // знаменатель c+b не должен быть равен 0
            if (x > 0 && c + b != 0)
            {
                F = a * sin(x) - log(x) / (c + b);

                printf("%10.3lf    %12.3lf\n", x, F);
            }
            else
            {
                printf("%10.3lf    не определено\n", x);
            }
        }

        // Второй случай:
        // F = (x - a*x^2) / (x - b - sin(c))
        else if (x > c && a == 0)
        {
            if (x - b - sin(c) != 0)
            {
                F = (x - a * x * x) / (x - b - sin(c));

                printf("%10.3lf    %12.3lf\n", x, F);
            }
            else
            {
                printf("%10.3lf    не определено\n", x);
            }
        }

        // Во всех остальных случаях:
        // F = 3*x + (a+x)/c^2
        else
        {
            if (c != 0)
            {
                F = 3 * x + (a + x) / (c * c);

                printf("%10.3lf    %12.3lf\n", x, F);
            }
            else
            {
                printf("%10.3lf    не определено\n", x);
            }
        }
    }

    printf("\nНажмите Enter, чтобы закрыть программу...");
    getchar(); // считывает оставшийся символ '\n' после scanf
    getchar(); // ждёт нажатия Enter

    return 0;

}
