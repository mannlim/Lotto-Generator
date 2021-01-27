#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <random>
#include <vector>
#include <sstream>

using namespace std;

void birthGenerator(int num_0, int num_1, int num_2, int num_3, int num_4, int num_5, int num_6, int num_7)
{
    // ���� ����
    vector<int> checkVec;
    checkVec.clear();

    // 80%
    checkVec.push_back(num_5 * 10 + num_4);  //0
    checkVec.push_back(num_3 * 10 + num_2);  //1
    checkVec.push_back(num_1 * 10 + num_0);  //2

    // 50%
    checkVec.push_back(num_7 * 10 + num_6);   //3
    checkVec.push_back(num_4 * 10 + num_5);  //4
    checkVec.push_back(num_2 * 10 + num_3);  //5
    checkVec.push_back(num_0 * 10 + num_1);  //6
    checkVec.push_back(num_5 + num_4);   //7
    checkVec.push_back(num_3 + num_2);   //8
    checkVec.push_back(num_1 + num_0);   //9
    checkVec.push_back(checkVec[1] + checkVec[2]); //10

    // 20%
    checkVec.push_back(num_7 + num_6 + num_5 + num_4 + num_3 + num_2 + num_1 + num_0);   //11
    checkVec.push_back(num_5 + num_4 + num_3 + num_2 + num_1 + num_0);   //12
    checkVec.push_back(num_7 + num_6 + num_5 + num_4);   //13
    checkVec.push_back(num_3 + num_2 + num_1 + num_0);   //14
    checkVec.push_back(num_2 + num_0);   //15
    checkVec.push_back(num_2 * num_0);   //16
    checkVec.push_back(checkVec[1] * checkVec[2]);   //17

    // ��� ������ ���� & �ߺ� �� üũ
    for (int i = 0; i < checkVec.size(); i++)
    {
        if (checkVec[i] > 45)
        {
            checkVec[i] = 0;
        }

        for (int j = 0; j < i; j++)
        {
            if (checkVec[j] == checkVec[i])
            {
                checkVec[i] = 0;
            }
        }
        //cout << checkVec[i] << endl;
    }
    //cout << endl;

    random_device rd;
    mt19937 gen(rd());

    vector<int> realVec;

    if ((gen() % 10) < 8 && checkVec[0] != 0)
        realVec.push_back(checkVec[0]);
    if ((gen() % 10) < 8 && checkVec[1] != 0)
        realVec.push_back(checkVec[1]);
    if ((gen() % 10) < 8 && checkVec[2] != 0)
        realVec.push_back(checkVec[2]);

    if ((gen() % 10) < 5 && checkVec[3] != 0)
        realVec.push_back(checkVec[3]);
    if ((gen() % 10) < 5 && checkVec[4] != 0)
        realVec.push_back(checkVec[4]);
    if ((gen() % 10) < 5 && checkVec[5] != 0)
        realVec.push_back(checkVec[5]);
    if ((gen() % 10) < 5 && checkVec[6] != 0)
        realVec.push_back(checkVec[6]);
    if ((gen() % 10) < 5 && checkVec[7] != 0)
        realVec.push_back(checkVec[7]);
    if ((gen() % 10) < 5 && checkVec[8] != 0)
        realVec.push_back(checkVec[8]);
    if ((gen() % 10) < 5 && checkVec[9] != 0)
        realVec.push_back(checkVec[9]);
    if ((gen() % 10) < 5 && checkVec[10] != 0)
        realVec.push_back(checkVec[10]);

    if ((gen() % 10) < 2 && checkVec[11] != 0)
        realVec.push_back(checkVec[11]);
    if ((gen() % 10) < 2 && checkVec[12] != 0)
        realVec.push_back(checkVec[12]);
    if ((gen() % 10) < 2 && checkVec[13] != 0)
        realVec.push_back(checkVec[13]);
    if ((gen() % 10) < 2 && checkVec[14] != 0)
        realVec.push_back(checkVec[14]);
    if ((gen() % 10) < 2 && checkVec[15] != 0)
        realVec.push_back(checkVec[15]);
    if ((gen() % 10) < 2 && checkVec[16] != 0)
        realVec.push_back(checkVec[16]);
    if ((gen() % 10) < 2 && checkVec[17] != 0)
        realVec.push_back(checkVec[17]);

    if (realVec.size() > 6) // �ζ� ��ȣ�� 6�� �̻� �ȳ������� ����
    {
        realVec.erase(realVec.begin() + 6, realVec.end());
    }
    else // �ζ� ��ȣ�� 6���� �ǵ��� ����
    {
        for (int i = realVec.size(); i < 6; i++)
        {
            int temp = gen() % 45 + 1;
            realVec.push_back(temp);

            for (int j = 0; j < i; j++)
            {
                if (realVec[j] == temp)
                {
                    realVec.erase(realVec.begin() + i);
                    i--;
                }
            }
        }
    }
 
    sort(realVec.begin(), realVec.end());

    for (int n = 0; n < realVec.size(); n++)
    {
        cout << realVec[n] << " ";
    }
    cout << endl;
}

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
        cout << "=============================" << endl;
        cout << "1. ���� ��ȣ ����" << endl;
        cout << "=============================" << endl;
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
        cout << "=============================" << endl;
        cout << "2. Ư�� ���� ���� ����" << endl;
        cout << "=============================" << endl;
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
        numVec.clear();
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

class menu_3
{
public:
    menu_3()
    {
        cin.ignore();
        cout << "\n";
        cout << "=============================" << endl;
        cout << "3. ������� ���� ��ȣ ����" << endl;
        cout << "=============================" << endl;
        cout << "\n\n\n";
        cout << "��������� ������ ���� �Է����ּ���." << endl;
        cout << "(��������� 1994�� 2�� 11���� ��� '19940211', 2002�� 11�� 3���ΰ�� '20021103'���� �Է�)" << endl;
        cout << "\n";

        int orgInt;
        cin >> orgInt;
        cout << "\n";

        vector<int> numVec;
        numVec.clear();

        if (orgInt < 10000000 || orgInt >= 100000000)
        {
            cout << "�� �� �Է��ϼ̽��ϴ�. ��������� �ٽ� �Է����ּ���." << endl;
            Sleep(3000);
            system("cls");
            menu_3();
        }
        else
        {
            while (orgInt > 0)
            {
                numVec.push_back(orgInt % 10);
                orgInt /= 10;
            }

            if ((numVec[3] * 10 + numVec[2] > 0) && (numVec[3] * 10 + numVec[2] <= 12)
                && (numVec[1] * 10 + numVec[0] > 0) && (numVec[1] * 10 + numVec[0] <= 31))
            {
                cout << "�Է��Ͻ� ��������� ";

                for (int i = 7; i >= 4; i--)
                {
                    cout << numVec[i];
                }
                cout << "�� ";

                for (int i = 3; i >= 2; i--)
                {
                    cout << numVec[i];
                }
                cout << "�� ";

                for (int i = 1; i >= 0; i--)
                {
                    cout << numVec[i];
                }
                cout << "�� �Դϴ�." << endl;
                cout << "�Է��Ͻ� ��������� ������� �ζ� ��ȣ�� �����ϰڽ��ϴ�." << endl;
            }
            else
            {
                cout << "�� �� �Է��ϼ̽��ϴ�. ��������� �ٽ� �Է����ּ���." << endl;
                Sleep(3000);
                system("cls");
                menu_3();
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
                    birthGenerator(numVec[0], numVec[1], numVec[2], numVec[3], numVec[4], numVec[5], numVec[6], numVec[7]);
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
            menu_3();
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
        else if (num == 3)
        {
            system("cls");
            menu_3();
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
        cout << "3. ������� ���� ��ȣ ����" << endl;
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
    //menu_3();

    return 0;
}