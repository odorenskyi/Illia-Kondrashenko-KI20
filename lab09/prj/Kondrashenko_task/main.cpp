#include <iostream>
#include <windows.h>
#include <clocale>
#include <wchar.h>
#include <fcntl.h>
#include <iomanip>
#include <io.h>
#include "moduleskondrashenko.h"

using namespace std;

int N;
double x, y, z, S, input;
float tem_arr[7], mid_temperature_celsius, mid_temperature_farengates;

void SoftwareDeveloper(){

wcout << (L"_______________________________________________________________________________________________\n");
wcout << (L"|Завдання виконав: студент академічної групи КБ - 20. Кондрашенко Ілля Сергійович. ЦНТУ. 2021.| \n");
wcout << (L"|_____________________________________________________________________________________________|\n");

}


void function8_1(){

    wcout << L"\n\n Будь ласка введіть x: ";
    wcin >> x;

    while (x < 0){
        wcout << L"\n\n Будь ласка введіть x: ";
        wcin >> x;
    }

    wcout << L"\n Будь ласка введіть y: ";
    wcin >> y;
    wcout << L"\n Будь ласка введіть z: ";
    wcin >> z;

    wcout << "\n S = " << s_calculation(x, y, z) << "\n";
}

void function9_1(){

    wcout << L"\n Будь ласка введіть силу вiтру: ";
    wcin >> input;

    while (input < 0){

        Beep(417, 500);
        wcout << L"\n\a Помилка....Спробуйте ввести силу вiтру ще раз: ";
        wcin >> input;
    }

    wcout << L"\n Сила вiтру у м/с - " << wind_speed(input) << "\n";
    wcout << L"\n Бал Бофорта - " << beaufort_point(input) << "\n";
}


void function9_2(){

    for(int i = 0; i < 7; i++){

        while(true){

            wcout << L"\n Будь ласка, введiть середнi температурнi показники повiтря у градусах за Цельсієм(у межах від -25 до 45) за " << i + 1 << L" день: ";

            if(!wscanf(L"%f", &tem_arr[i])){

                wscanf(L"%*[^\n]");
                Beep(417, 500);
                wcout << L"\n\a Помилка....Будь ласка введiть число.\n";
            }

            if(tem_arr[i] >= -25 && tem_arr[i] <= 45){

                break;

            }else{

                Beep(417, 500);
                wcout << L"\n\a Помилка....Таких середнiх температурних показникiв повiтря не може бути.";
                wcout << L"\n Будь ласка спробуйте ще раз.\n";
            }
        }
    }

    mid_tem_week(tem_arr, 7, &mid_temperature_celsius, &mid_temperature_farengates);

    wcout << L"\n Середньотижнева температура за шкалою Цельсiя - " << mid_temperature_celsius << "\n";
    wcout << L"\n Середньотижнева температура за шкалою Фаренгейта - " << mid_temperature_farengates << "\n";
}


void function9_3(){

    while(true){

        wcout << L"\n Введiть цiле число в iнтервалi вiд 0 до 70700: ";

        if(!wscanf(L"%d", &N)){

            wscanf(L"%*[^\n]");
            Beep(417, 500);
            wcout << L"\n\a Помилка....Будь ласка введiть число.\n";

        }else if(N >= 0 && N <= 70700){

            wcout << zero_one_counter(N);
            break;

        }else{
            Beep(417, 500);
            wcout << L"\n\a Помилка....Будь ласка спробуйте ще раз.\n";
        }
    }
}

int main(){

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _wsetlocale(LC_ALL,L"");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SoftwareDeveloper();

    wchar_t input = 0;

    do {
        wcout << L"\n Шановний користувачу, будь ласка оберіть функцію, яку виконає програма: \n";
        wcout << L"\n Для виклику функцiї s_calculation введіть команду: \"q\"\n Для виклику функцiї до задачi 9.1 введіть команду: \"e\"";
        wcout << L"\n Для виклику функцiї до задачi 9.2 введіть команду: \"r\"\n Для виклику функцiї до задачi 9.3 введіть команду: \"t\"\n\n";
        wcin >> input;

        if (input == 'q' || input == 'Q') {

            function8_1();

            wcout << L"\n\n Для того, щоб вийти з програми, будь ласка введіть команду: \"y\", \"Y\" або \"H\": " << "\n";
            wcin >> input;

        }else if (input == 'e' || input == 'E'){

            function9_1();

            wcout << L"\n\n Для того, щоб вийти з програми, будь ласка введіть команду: \"y\", \"Y\" або \"H\": " << "\n";
            wcin >> input;

        }else if (input == 'r' || input == 'R'){

            function9_2();

            wcout << L"\n\n Для того, щоб вийти з програми, будь ласка введіть команду: \"y\", \"Y\" або \"H\": " << "\n";
            wcin >> input;

        }else if (input == 't' || input == 'T'){

            function9_3();

            wcout << L"\n\n Для того, щоб вийти з програми, будь ласка введіть команду: \"y\", \"Y\" або \"H\": " << "\n";
            wcin >> input;

        }else if (input != 'y' && input != 'Y' && input != 'h' && input != 'H'){

            Beep(417, 500);
            wcout << L"\n Ви ввели невірну команду, будь ласка спробуйте ще раз" << "\n";
        }

    }while (input != 'y' && input != 'Y' && input != 'h' && input != 'H');

    system("pause");

    return 0;
}
