#include "application.h"

using namespace std;


void Application::exec()
{
    string path = "input.txt";
    Graph graph(path);
    int choice;
    do {
        cout << "\n\nВыберите действие:" "\n"
            "1. Найти минимальное остовное дерево," "\n"
            "2. Вывести матрицу смежности," "\n"
            "3. Вывести матрицу инцидентности," "\n"
            "4. Вывести список смежности," "\n"
            "5. Вывести список ребер," "\n"
            "6. Сделать обходы в глубину и ширину," "\n"
            "0. Закончить этот мораторий!" "\n\n"
            "Ваш выбор: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                system("cls");
                graph.findMinSpanningTree();
                break;
            }
            case 2: {
                system("cls");
                graph.showAdjMatrix();
                break;
            }
            case 3: {
                system("cls");
                graph.showIncMatrix();
                break;
            }
            case 4: {
                system("cls");
                graph.showAdjList();
                break;
            }
            case 5: {
                system("cls");
                graph.showEdgeList();
                break;
            }
            case 6: {
                system("cls");
                cout << "Не готово!" << endl;
                break;
            }case 0: {
                break;
            }
            default: {
                cout << "Неправильный ввод!" << endl;
                break;
            }
        }

    } while (choice);
}
