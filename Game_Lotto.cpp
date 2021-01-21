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
        cout << "1. 랜덤 번호 생성" << endl;
        cout << "=================" << endl;
        cout << "\n\n\n";
        cout << "로또 번호를 몇 개 생성할까요? 원하시는 개수를 다음과 같이 입력해주세요." << endl;
        cout << "(1개를 생성하고 싶으시면 '1' 입력 후 엔터, 5개를 생성하고 싶으시면 '5' 입력 후 엔터)" << endl;
        cout << "\n";
        //cout << "※ 메인 메뉴로 돌아가기를 원하시면 '0'을 입력해주세요." << endl;

        int count = 6;
        int num;
        cin >> num;

        try
        {
            if (num <= 0) throw string("잘 못 입력하셨습니다. 0보다 큰 숫자를 입력하세요");
            //else if (num == 0) mainMenu(); // 메인메뉴로 돌아가기
            else
            {
                cout << "로또 번호 " << num << "개를 생성하겠습니다." << endl;
                cout << "\n\n";
                cout << "행운의 번호는?" << endl;
                cout << "\n";
                for (int n = 0; n < num; n++)
                {
                    cout << n + 1 << "번 번호 :\t";
                    randomGenerator(0);
                }
                cout << "\n\n";
                cout << "-------------------------------------------------------------------------------" << endl;
                cout << "\n";
                cout << "♥1등 당첨을 기원합니다♥" << endl;
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
        cout << "2. 특정 숫자 포함 생성" << endl;
        cout << "=================" << endl;
        cout << "\n\n\n";
        cout << "어떤 숫자를 포함할까요? 숫자를 다음과 같이 입력해주세요.(1 ~ 5개만!)" << endl;
        cout << "(13, 24를 포함하고 싶으시면 '13 24' 입력 후 엔터(space로 띄어쓰기 해주세요.))" << endl;
        cout << "\n";

        std::string orgString;
        //cin >> orgString;
        std::getline(std::cin, orgString);
        cout << "\n";

        stringstream orgNum(orgString);
        int newNum;
        vector<int> numVec;
        int SIZE;

        cout << "입력하신 숫자는 ";
        while (orgNum >> newNum)
        {
            numVec.push_back(newNum);
            cout << newNum << " ";
        }
        cout << "입니다." << endl;
        cout << "위 " << numVec.size() << "개의 번호를 포함하여 로또 번호를 생성하겠습니다." << endl;

        SIZE = numVec.size();

        // 중복 값 체크
        for (int i = 0; i < numVec.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (numVec[j] == numVec[i])
                {
                    cout << "\n중복된 번호가 있습니다. 번호를 중복되지 않게 다시 입력해주세요." << endl;
                    Sleep(3000);
                    system("cls");
                    menu_2();
                }
            }
        }

        // 1 ~ 45 범위 체크
        for (int i = 0; i < numVec.size(); i++)
        {
            if (numVec[i] < 1 || numVec[i] > 45)
            {
                cout << "로또는 1 ~ 45 사이의 번호만 고를 수 있습니다. 범위에 맞는 번호를 입력해주세요" << endl;
                Sleep(3000);
                system("cls");
                menu_2();
            }
        }

        // 번호 6개 이상 입력 체크
        if (numVec.size() > 6)
        {
            cout << "로또는 총 6개의 번호만 고를 수 있습니다. 더 적은 갯수의 번호를 입력해주세요" << endl;
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
        cout << "로또 번호를 몇 개 생성할까요? 원하시는 개수를 다음과 같이 입력해주세요." << endl;
        cout << "(1개를 생성하고 싶으시면 '1' 입력 후 엔터, 5개를 생성하고 싶으시면 '5' 입력 후 엔터)" << endl;
        cout << "\n";
        //cout << "※ 메인 메뉴로 돌아가기를 원하시면 '0'을 입력해주세요." << endl;

        int num;
        cin >> num;

        try
        {
            if (num <= 0) throw string("잘 못 입력하셨습니다. 0보다 큰 숫자를 입력하세요");
            //else if (num == 0) mainMenu(); // 메인메뉴로 돌아가기
            else
            {
                cout << "로또 번호 " << num << "개를 생성하겠습니다." << endl;
                cout << "\n\n";
                cout << "행운의 번호는?" << endl;
                cout << "\n";
                for (int n = 0; n < num; n++)
                {
                    cout << n + 1 << "번 번호 :\t";
                    randomGenerator(SIZE, numVec[0], numVec[1], numVec[2], numVec[3], numVec[4], numVec[5]);
                }
                cout << "\n\n";
                cout << "-------------------------------------------------------------------------------" << endl;
                cout << "\n";
                cout << "♥1등 당첨을 기원합니다♥" << endl;
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
        if (num <= 0 || num > 4) throw string("잘 못 입력하셨습니다. 1 ~ 4 사이의 숫자를 입력하세요");

        cout << num << "번을 선택하셨습니다." << endl;

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
        cout << "  로또 번호 생성 프로그램" << endl;
        cout << "\n";
        cout << "< LOTTO NUMBER GENERATOR >" << endl;
        cout << "\n";
        cout << "=============================" << endl;
        cout << "\n\n";
        cout << "\t" << "< MENU >" << endl;
        cout << "\n";
        cout << "1. 랜덤 번호 생성" << endl;
        cout << "2. 특정 숫자 포함 생성" << endl;
        cout << "3. 생일 관련 생성" << endl;
        cout << "4. 역대 1위 당첨번호 기반 생성" << endl;
        cout << "\n\n";
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "※ 이 프로그램은 단순 참고용으로만 활용하시기 바랍니다." << endl;
        cout << "   지나친 로또 구매는 심신에 악영향을 끼칠 수 있습니다." << endl;

        cout << "\n\n\n";
        cout << "원하시는 로또 번호 생성 방법을 아래 메뉴에서 골라 다음과 같이 입력해주세요." << endl;
        cout << "('1. 랜덤 번호 생성'을 원할 경우 '1' 입력 후 엔터)" << endl;

        choiceMenu();
    }
};

int main()
{
    mainMenu();

    return 0;
}