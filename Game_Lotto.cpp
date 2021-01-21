#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <random>
#include <vector>
#include <sstream>

using namespace std;

void randomGenerator(int startNum = 0, int num_0 = 0, int num_1 = 0, int num_2 = 0, int num_3 = 0, int num_4 = 0, int num_5 = 0)
{
    int lotto[6];

    random_device rd;
    mt19937 gen(rd());

    lotto[0] = num_0;
    lotto[1] = num_1;
    lotto[2] = num_2;
    lotto[3] = num_3;
    lotto[4] = num_4;
    lotto[5] = num_5;

    for (int i = startNum; i < 6; i++)
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

class menu_1
{
public:
    menu_1()
    {
        cin.ignore();
        cout << "\n";
        cout << "=================" << endl;
        cout << "1. ���� ��ȣ ����" << endl;
        cout << "=================" << endl;
        cout << "\n\n\n";
        cout << "�ζ� ��ȣ�� �� �� �����ұ��? ���Ͻô� ������ ������ ���� �Է����ּ���." << endl;
        cout << "(1���� �����ϰ� �����ø� '1' �Է� �� ����, 5���� �����ϰ� �����ø� '5' �Է� �� ����)" << endl;
        cout << "\n";
        //cout << "�� ���� �޴��� ���ư��⸦ ���Ͻø� '0'�� �Է����ּ���." << endl;

        int count = 6;
        int num;
        cin >> num;

        try
        {
            if (num <= 0) throw string("�� �� �Է��ϼ̽��ϴ�. 0���� ū ���ڸ� �Է��ϼ���");
            //else if (num == 0) mainMenu(); // ���θ޴��� ���ư���
            else
            {
                cout << "�ζ� ��ȣ " << num << "���� �����ϰڽ��ϴ�." << endl;
                cout << "\n\n";
                cout << "����� ��ȣ��?" << endl;
                cout << "\n";
                for (int n = 0; n < num; n++)
                {
                    cout << n + 1 << "�� ��ȣ :\t";
                    randomGenerator(0);
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
            Sleep(3000);
            system("cls");
            menu_1();
        }
    }
};

class menu_2
{
public:
    menu_2()
    {
        cin.ignore();
        cout << "\n";
        cout << "=================" << endl;
        cout << "2. Ư�� ���� ���� ����" << endl;
        cout << "=================" << endl;
        cout << "\n\n\n";
        cout << "� ���ڸ� �����ұ��? ���ڸ� ������ ���� �Է����ּ���.(1 ~ 5����!)" << endl;
        cout << "(13, 24�� �����ϰ� �����ø� '13 24' �Է� �� ����(space�� ���� ���ּ���.))" << endl;
        cout << "\n";

        std::string orgString;
        //cin >> orgString;
        std::getline(std::cin, orgString);
        cout << "\n";

        stringstream orgNum(orgString);
        int newNum;
        vector<int> numVec;
        int SIZE;

        cout << "�Է��Ͻ� ���ڴ� ";
        while (orgNum >> newNum)
        {
            numVec.push_back(newNum);
            cout << newNum << " ";
        }
        cout << "�Դϴ�." << endl;
        cout << "�� " << numVec.size() << "���� ��ȣ�� �����Ͽ� �ζ� ��ȣ�� �����ϰڽ��ϴ�." << endl;

        SIZE = numVec.size();

        // �ߺ� �� üũ
        for (int i = 0; i < numVec.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (numVec[j] == numVec[i])
                {
                    cout << "\n�ߺ��� ��ȣ�� �ֽ��ϴ�. ��ȣ�� �ߺ����� �ʰ� �ٽ� �Է����ּ���." << endl;
                    Sleep(3000);
                    system("cls");
                    menu_2();
                }
            }
        }

        // 1 ~ 45 ���� üũ
        for (int i = 0; i < numVec.size(); i++)
        {
            if (numVec[i] < 1 || numVec[i] > 45)
            {
                cout << "�ζǴ� 1 ~ 45 ������ ��ȣ�� �� �� �ֽ��ϴ�. ������ �´� ��ȣ�� �Է����ּ���" << endl;
                Sleep(3000);
                system("cls");
                menu_2();
            }
        }

        // ��ȣ 6�� �̻� �Է� üũ
        if (numVec.size() > 6)
        {
            cout << "�ζǴ� �� 6���� ��ȣ�� �� �� �ֽ��ϴ�. �� ���� ������ ��ȣ�� �Է����ּ���" << endl;
            Sleep(3000);
            system("cls");
            menu_2();
        }

        if (numVec.size() < 6)
        {
            for (int n = numVec.size(); n < 6; n++)
            {
                numVec.push_back(0);
            }
        }

        cout << "\n";
        cout << "�ζ� ��ȣ�� �� �� �����ұ��? ���Ͻô� ������ ������ ���� �Է����ּ���." << endl;
        cout << "(1���� �����ϰ� �����ø� '1' �Է� �� ����, 5���� �����ϰ� �����ø� '5' �Է� �� ����)" << endl;
        cout << "\n";
        //cout << "�� ���� �޴��� ���ư��⸦ ���Ͻø� '0'�� �Է����ּ���." << endl;

        int num;
        cin >> num;

        try
        {
            if (num <= 0) throw string("�� �� �Է��ϼ̽��ϴ�. 0���� ū ���ڸ� �Է��ϼ���");
            //else if (num == 0) mainMenu(); // ���θ޴��� ���ư���
            else
            {
                cout << "�ζ� ��ȣ " << num << "���� �����ϰڽ��ϴ�." << endl;
                cout << "\n\n";
                cout << "����� ��ȣ��?" << endl;
                cout << "\n";
                for (int n = 0; n < num; n++)
                {
                    cout << n + 1 << "�� ��ȣ :\t";
                    randomGenerator(SIZE, numVec[0], numVec[1], numVec[2], numVec[3], numVec[4], numVec[5]);
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
            Sleep(3000);
            system("cls");
            menu_2();
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
            system("cls");
            menu_1();
        }
        else if (num == 2)
        {
            system("cls");
            menu_2();
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