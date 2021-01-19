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
        cout << "1. 랜덤 번호 생성" << endl;
        cout << "=================" << endl;
        cout << "\n\n\n";
        cout << "몇 개를 생성할까요? 원하시는 개수를 다음과 같이입력해주세요." << endl;
        cout << "(1개를 생성하고 싶으시면 '1' 입력 후 엔터, 5개를 생성하고 싶으시면 '5' 입력 후 엔터)" << endl;
        cout << "\n";
        //cout << "※ 메인 메뉴로 돌아가기를 원하시면 '0'을 입력해주세요." << endl;

        int num;
        cin >> num;

        try
        {
            if (num <= 0) throw string("잘 못 입력하셨습니다. 0보다 큰 숫자를 입력하세요");
            //else if (num == 0) mainMenu();
            else
            {
                cout << num << "개를 생성하겠습니다." << endl;
                cout << "\n\n";
                cout << "행운의 번호는?" << endl;
                cout << "\n";
                for (int n = 0; n < num; n++)
                {
                    cout << n + 1 << "번 번호 :\t";
                    randomGenerator();
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
        if (num <= 0 || num > 4) throw string("잘 못 입력하셨습니다. 1 ~ 4 사이의 숫자를 입력하세요");

        cout << num << "번을 선택하셨습니다." << endl;

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
