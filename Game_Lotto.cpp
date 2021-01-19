#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;

class randomGenerator
{
public:
    randomGenerator()
    {
        int lotto[6];

        random_device rd;
        mt19937 gen(rd());

        for (int i = 0; i < 6; i++)
        {
            int temp = gen() % 45 + 1;
            lotto[i] = temp;
            for (int j = 0; j < i; j++)
            {
                if (lotto[j] == temp)
                {
                    i--;
                }
            }
        }

        sort(lotto, lotto + 6);

        for (int i = 0; i < 6; i++)
        {
            cout << lotto[i] << "\t";
        }
        cout << endl;
    }
};

class menu_1
{
public:
    menu_1()
    {
        system("cls");
        cout << "\n";
        cout << "=================" << endl;
        cout << "1. ���� ��ȣ ����" << endl;
        cout << "=================" << endl;
        cout << "\n\n\n";
        cout << "�� ���� �����ұ��? ���Ͻô� ������ ������ �����Է����ּ���." << endl;
        cout << "(1���� �����ϰ� �����ø� '1' �Է� �� ����, 5���� �����ϰ� �����ø� '5' �Է� �� ����)" << endl;
        cout << "\n";
        //cout << "�� ���� �޴��� ���ư��⸦ ���Ͻø� '0'�� �Է����ּ���." << endl;

        int num;
        cin >> num;

        try
        {
            if (num <= 0) throw string("�� �� �Է��ϼ̽��ϴ�. 0���� ū ���ڸ� �Է��ϼ���");
            //else if (num == 0) mainMenu();
            else
            {
                cout << num << "���� �����ϰڽ��ϴ�." << endl;
                cout << "\n\n";
                cout << "����� ��ȣ��?" << endl;
                cout << "\n";
                for (int n = 0; n < num; n++)
                {
                    cout << n + 1 << "�� ��ȣ :\t";
                    randomGenerator();
                }
                cout << "\n\n";
                cout << "-------------------------------------------------------------------------------" << endl;
                cout << "\n";
                cout << "��1�� ��÷�� ����մϴ٢�" << endl;
                cout << "\n";
            }
        }
        catch (string(error_message))
        {
            cout << error_message << endl;
            menu_1();
        }
    }
};

void choiceMenu()
{
    int num;
    cin >> num;

    try
    {
        if (num <= 0 || num > 4) throw string("�� �� �Է��ϼ̽��ϴ�. 1 ~ 4 ������ ���ڸ� �Է��ϼ���");

        cout << num << "���� �����ϼ̽��ϴ�." << endl;

        Sleep(1000);
        system("cls");

        if (num == 1)
        {
            menu_1();
        }
    }
    catch (string(error_message))
    {
        cout << error_message << endl;
        choiceMenu();
    }
}

class mainMenu
{
public:
    mainMenu()
    {
        system("cls");

        cout << "\n";
        cout << "=============================" << endl;
        cout << "\n";
        cout << "  �ζ� ��ȣ ���� ���α׷�" << endl;
        cout << "\n";
        cout << "< LOTTO NUMBER GENERATOR >" << endl;
        cout << "\n";
        cout << "=============================" << endl;
        cout << "\n\n";
        cout << "\t" << "< MENU >" << endl;
        cout << "\n";
        cout << "1. ���� ��ȣ ����" << endl;
        cout << "2. Ư�� ���� ���� ����" << endl;
        cout << "3. ���� ���� ����" << endl;
        cout << "4. ���� 1�� ��÷��ȣ ��� ����" << endl;
        cout << "\n\n";
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "�� �� ���α׷��� �ܼ� ��������θ� Ȱ���Ͻñ� �ٶ��ϴ�." << endl;
        cout << "   ����ģ �ζ� ���Ŵ� �ɽſ� �ǿ����� ��ĥ �� �ֽ��ϴ�." << endl;

        cout << "\n\n\n";
        cout << "���Ͻô� �ζ� ��ȣ ���� ����� �Ʒ� �޴����� ��� ������ ���� �Է����ּ���." << endl;
        cout << "('1. ���� ��ȣ ����'�� ���� ��� '1' �Է� �� ����)" << endl;

        choiceMenu();
    }
};

int main()
{
    mainMenu();
    
    return 0;
}
