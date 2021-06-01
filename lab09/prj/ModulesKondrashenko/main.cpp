#include <iostream>
#include <cmath>
#include <wchar.h>
#include <io.h>
#include <string>
#include <bitset>
#include "moduleskondrashenko.h"
using namespace std;

double s_calculation(double x, double y, double z){

    const double PI = 3.141592653589793;

    double S = z + 2 * pow(y, 2)/log(x-y) + sqrt(PI * x );

    S = int(S*100 + 0.5)/100.0;

    return S;
}


double wind_speed(double input){

    input = input * 1000;

    return input;
}


double beaufort_point(double input){

    if (input < 0.3){

        return 0.0;

    }else if (input >= 0.3 && input <= 1.5){

        return 1.0;

    }else if (input >= 1.6 && input <= 3.3){

        return 2.0;

    }else if (input >= 3.4 && input <= 5.4){

        return 3.0;

    }else if (input >= 5.5 && input <= 7.9){

        return 4.0;

    }else if (input >= 8.0 && input <= 10.7){

        return 5.0;

    }else if (input >= 10.8 && input <= 13.8){

        return 6.0;

    }else if (input >= 13.9 && input <= 17.1){

        return 7.0;

    }else if (input >= 17.2 && input <= 20.7){

        return 8.0;

    }else if (input >= 20.8 && input <= 24.4){

        return 9.0;

    }else if (input >= 24.5 && input <= 28.4){

        return 10.0;

    }else if (input >= 28.5 && input <= 32.6){

        return 11.0;

    }else if (input >= 32.7){

        return 12.0;
    }
}


float mid_tem_week(float tem_arr[], int size,  float *mid_temperature_celsius, float *mid_temperature_farengates){

    (*mid_temperature_celsius) = 0;

    (*mid_temperature_farengates) = 0;

    for(int i = 0; i < size ; i++){

        (*mid_temperature_celsius) += (tem_arr[i]);
    }

    (*mid_temperature_celsius) /= 7;

    (*mid_temperature_farengates) = 32 + (*mid_temperature_celsius) * 9/5;

    (*mid_temperature_farengates) = int((*mid_temperature_farengates) * 100 + 0.5) / 100.0;

    (*mid_temperature_celsius) = int((*mid_temperature_celsius) * 100 + 0.5) / 100.0;
}


int zero_one_counter(int N){

    int mask_1 = 0b00000000000000000000000000000001;

    int mask_2 = 0b00000000000000000000000000000001;

    int D7 = 0b00000000000000000000100000000000;

    int Zero = 0;
    int One = 0;

    for(int i = 0; i < (log2(N)); i++){

        if(!(N & mask_1))

            Zero++;

        else

            One++;
            mask_1 <<= 1;
    }

    if(!(N & (mask_2 << 7))){

        wcout << L"\n Bin Zero - ";
        return Zero;

    }else{

        wcout << L"\n Bin One - ";
        return One;
    }
}



