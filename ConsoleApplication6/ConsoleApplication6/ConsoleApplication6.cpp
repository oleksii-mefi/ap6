#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Owner
{
    string surname;
    string car_brand;
    string color;
    string number;
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    ifstream fromFile("owners.txt");

    if (!fromFile)
    {
        cout << "��������� ������� ���� ��� �������!\n";
        system("pause");
        return 2;
    }

    string prefix;
    cout << "������ ������� ������ ���������: ";
    cin >> prefix;

    ofstream resultFile("result.txt");

    int k = 0;
    while (fromFile)
    {
        Owner owner;
        fromFile >> owner.surname >> owner.car_brand >> owner.color >> owner.number;
        if (fromFile)
        {
            if (owner.number.substr(0, prefix.length()) == prefix)
            {
                resultFile << owner.surname << ' '
                    << owner.car_brand << ' '
                    << owner.color << ' '
                    << owner.number << '\n';
                k++;
            }
        }
    }

    resultFile.close();
    fromFile.close();

    cout << "�������� " << k << " �������� ��������� � ��������� " << prefix << ".\n";
    cout << "���������� ��������� �������� � ���� result.txt.\n";

    system("pause");
    return 0;
}