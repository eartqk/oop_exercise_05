/*
Артамонов О.А. М8О-208Б-19
github.com/eartqk/oop_exercise_05
Вариант 10: список и квадрат
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "List.hpp"
#include "Point.hpp"
#include "Square.hpp"

void Help()
{
    std::cout << "0. Вывести справку.\n";
    std::cout << "1. Добавить квадрат\n";
    std::cout << "   1. В начало списка.\n";
    std::cout << "   2. По индексу.\n";
    std::cout << "   3. В конец списка.\n";
    std::cout << "2. Удалить квадрат\n";
    std::cout << "   1. В начале списка.\n";
    std::cout << "   2. По индексу.\n";
    std::cout << "   3. В конце списка.\n";
    std::cout << "3. Вывести квадрат\n";
    std::cout << "   1. Из начала списка.\n";
    std::cout << "   2. По индексу.\n";
    std::cout << "   3. Из конца списка.\n";
    std::cout << "4. Вывести количество фигур, чья площадь меньше заданной\n";
    std::cout << "5. Вывести все фигуры в списке.\n";
    std::cout << "6. Выйти.\n";
}

int main()
{
    Help();

    list<Square<double>> List;
    Square<double> square;

    int command1, command2, index;
    double area;

    while (true) {
        try {
            std::cin >> command1;
            switch (command1) {
            case 0:
                Help();
                break;
            case 1:
                std::cin >> command2;
                switch (command2) {
                case 1:
                    std::cin >> square;
                    List.push_front(square);
                    break;
                case 2:
                    std::cin >> index;
                    std::cin >> square;
                    List.insert_by_number(index, square);
                    break;
                case 3:
                    std::cin >> square;
                    List.push_back(square);
                    break;
                }
                std::cout << "Квадрат добавлен.\n";
                break;
            case 2:
                std::cin >> command2;
                switch (command2) {
                case 1:
                    List.pop_front();
                    break;
                case 2:
                    std::cin >> index;
                    List.delete_by_number(index);
                    break;
                case 3:
                    List.pop_back();
                    break;
                }
                std::cout << "Квадрат удален.\n";
                break;
            case 3:
                std::cin >> command2;
                switch (command2) {
                case 1:
                    std::cout << List.front() << '\n';
                    break;
                case 2:
                    std::cin >> index;
                    std::cout << List[index] << '\n';
                    break;
                case 3:
                    std::cout << List.back() << '\n';
                    break;
                }
                break;
            case 4:
                std::cout << "Введите заданную площадь: ";
                std::cin >> area;
                std::cout << std::count_if(
                    List.begin(), List.end(),
                    [area](const Square<double>& X) { return area > X.area; });
                std::cout << '\n';
                break;
            case 5:
                if (List.length() == 0)
                    std::cout << "Лист пустой, попробуйте что-то добавить :(\n";
                std::for_each(List.begin(), List.end(), [](const Square<double>& X) {
                    std::cout << X << '\n';
                });
                break;
            case 6:
                return 0;
                break;
            }
        }
        catch (const char* trash) {
        };
    }

    return 0;
}
