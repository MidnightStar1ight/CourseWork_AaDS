#include "application.h"

using namespace std;


void Application::exec()
{
    string path = "input.txt";
    Graph graph(path);
    int choice;
    do {
        cout << "\n\n�������� ��������:" "\n"
            "1. ����� ����������� �������� ������," "\n"
            "2. ������� ������� ���������," "\n"
            "3. ������� ������� �������������," "\n"
            "4. ������� ������ ���������," "\n"
            "5. ������� ������ �����," "\n"
            "6. ������� ������ � ������� � ������," "\n"
            "0. ��������� ���� ���������!" "\n\n"
            "��� �����: ";
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
                cout << "�� ������!" << endl;
                break;
            }case 0: {
                break;
            }
            default: {
                cout << "������������ ����!" << endl;
                break;
            }
        }

    } while (choice);
}
