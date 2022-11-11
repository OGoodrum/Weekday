
#include <stdio.h>
#include <stdlib.h>

int main(){
    /* INPUT DATA */
    int year = 2003;
    int month = 5;
    int day = 23;
    /* END OF INPUT DATA */

    
    //determining a leap year
    int leap_year;
    if(year % 4 != 0){
        leap_year = 0;
    }else if(year % 100 != 0){
        leap_year = 1;
    }else if(year % 400 != 0){
        leap_year = 0;
    }else{
        leap_year = 1;
    }
    
    //Calcultaions for the day of the week
    int day_of_week = ((year % 100)/4) + day;
    if(month == 1 || month == 10){
        day_of_week = day_of_week + 1;
    }
    else if(month == 2 || month == 3 || month == 11){
        day_of_week = day_of_week + 4;
    }
    else if(month == 5){
        day_of_week = day_of_week + 2;
    }
    else if(month == 6){
        day_of_week = day_of_week + 5;
    }
    else if(month == 8){
        day_of_week = day_of_week + 3;
    }
    else if(month == 9 || month == 12){
        day_of_week = day_of_week + 6;
    }
    
    
    if(leap_year == 1 && (month == 1 || month == 2)){
        day_of_week = day_of_week - 1;
    }
    
    day_of_week = day_of_week - (((year / 100) % 4) * 2);
    
    day_of_week = day_of_week + (year % 100);
    
    day_of_week = day_of_week + 12;
    
    day_of_week = day_of_week % 7;
    
    
    //Error statemnets for all invalid inputs
    //Invalid year
    if(year < 1 || year > 10000){
        printf("Error: Invalid year\n");
    }
    
    //invalid month
    else if(month < 1 || month > 12){
        printf("Error: Invalid month\n");
    }
    
    //invalid day
    else if(day < 1 || day > 31){
        printf("Error: Invalid day\n");
    }else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
        printf("Error: Invalid day\n");
    }else if(month == 2 && day > 29){
        printf("Error: Invalid day\n");
    }else if(leap_year == 0 && day > 28 && month == 2){
        printf("Error: Invalid day\n");
    }else{
        //print date and day of the week
        if(day_of_week == 0){
            printf("%d-%d-%d: Sunday\n", year, month, day);
        }else if(day_of_week == 1){
            printf("%d-%d-%d: Monday\n", year, month, day);
        }else if(day_of_week == 2){
            printf("%d-%d-%d: Tuesday\n", year, month, day);
        }else if(day_of_week == 3){
            printf("%d-%d-%d: Wednesday\n", year, month, day);
        }else if(day_of_week == 4){
            printf("%d-%d-%d: Thursday\n", year, month, day);
        }else if(day_of_week == 5){
            printf("%d-%d-%d: Friday\n", year, month, day);
        }else if(day_of_week == 6){
            printf("%d-%d-%d: Saturday\n", year, month, day);
    }}
   

    return 0;
}