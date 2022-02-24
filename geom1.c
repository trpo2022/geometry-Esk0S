#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SQR(x) x*x

typedef struct {
    double x1;
    double y1;
    double radius;
} circle;

int intersection_circles(circle, circle);

double char_to_double()
{
    double double_from_char;
    char last_getch;
    int integer;
    char intch;
    int dec_length;
    while ((last_getch = getchar()) == ' ') continue;

        integer = (last_getch - '0') * 10;
        while ((intch = getchar()) != '.') {
            integer = (intch - '0' + integer) * 10;
        }
        integer /= 10;
        

        float dec = 0;
        char decch;

        dec_length = 0;
        while ( ((decch = getchar()) != ' ') && (decch != ',') ) {
            
            dec = (decch - '0' + dec) * 10;
            dec_length += 1;
        }
        dec /= 10;

        dec /= pow(10, dec_length);

        double_from_char = integer + dec;

        return double_from_char;
}

double char_to_double_last()
{
    double double_from_char;
    char last_getch;
    int integer;
    char intch;
    int dec_length;
    while ((last_getch = getchar()) == ' ') continue;

        integer = (last_getch - '0') * 10;
        while ((intch = getchar()) != '.') {
            integer = (intch - '0' + integer) * 10;
        }
        integer /= 10;
        

        float dec = 0;
        char decch;

        dec_length = 0;


        while ( ((decch = getchar()) != ')') && (decch != ' ') ) {
            
            dec = (decch - '0' + dec) * 10;
            dec_length += 1;
        }
        dec /= 10;

        if (decch != ')') {
            while ((last_getch = getchar()) == ' ') continue;
            
            if (last_getch != ')')
            {
                
                printf("Expected ')'\n");
                return 0;
            }
        }

        dec /= pow(10, dec_length);

        double_from_char = integer + dec;

        return double_from_char;
}

int main()
{
    int i, is_circle1 = 0, is_circle2 = 0;
    circle cir1;
    circle cir2;
    char figure1[50];
    char figure2[50];

    char circle1[7] = {"circle"};
    
    printf("Enter 2 figures\n");

    i = 0;
    while ((figure1[i] = getchar()) != '(') {
        i++;
    }
    
    if ((figure1[0] == circle1[0]) || (figure1[0] == circle1[0] - 32)) {
        for (i = 1; figure1[i] != '('; i++) {
            if ((figure1[i] == circle1[i]) || (figure1[i] == circle1[i] - 32)) {
                is_circle1 = 1;
            } else {
                is_circle1 = 0;
                break;
            }
        }
    }

    
    if (is_circle1 == 1) {
        
        cir1.x1 = char_to_double();
        cir1.y1 = char_to_double();

        cir1.radius = char_to_double_last();
        if (cir1.radius == 0) {
            return 0;
        }

        double perimeter1;
        perimeter1 = 2 * M_PI * cir1.radius;
        printf("Perimeter: %lf\n", perimeter1);

        double area1;
        area1 = M_PI * SQR(cir1.radius);
        printf("Area: %lf\n", area1);
    } else {
        printf("Unexpected figure\n");
    } 

    getchar();
    



    i = 0;
    while ((figure2[i] = getchar()) != '(') {
        i++;
    }
    
    if ((figure2[0] == circle1[0]) || (figure2[0] == circle1[0] - 32)) {
        for (i = 1; figure2[i] != '('; i++) {
            if ((figure2[i] == circle1[i]) || (figure2[i] == circle1[i] - 32)) {
                is_circle2 = 1;
            } else {
                is_circle2 = 0;
                break;
            }
        }
    }
    
    if (is_circle2 == 1) {
        
        cir2.x1 = char_to_double();
        cir2.y1 = char_to_double();

        cir2.radius = char_to_double_last();
        if (cir2.radius == 0) {
            return 0;
        }

        double perimeter2;
        perimeter2 = 2 * M_PI * cir2.radius;
        printf("Perimeter: %lf\n", perimeter2);

        double area2;
        area2 = M_PI * SQR(cir2.radius);
        printf("Area: %lf\n", area2);
    } else {
        printf("Unexpected figure\n");
        
    } 

    int flag;
    flag = intersection_circles(cir1, cir2);

    if (flag == 1) {
        printf("Пересекаются\n");
    } else {
        printf("Не пересекаются\n");
    }


    return 0;
}

int intersection_circles(circle cir1, circle cir2)
{
    int flag = 0;
    double x_difference;
    double y_difference;
    double r_vec;
    double r_summ;

    x_difference = abs(cir1.x1 - cir2.x1);
    y_difference = abs(cir1.y1 - cir2.y1);

    r_vec = sqrt( SQR(x_difference) + SQR(y_difference) );

    r_summ = cir1.radius + cir2.radius;

    if (r_vec <= r_summ) {
        flag = 1;
    } else flag = 0;

    return flag;
}