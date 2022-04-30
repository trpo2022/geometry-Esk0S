#include <libgeometry/libgeometry.h>

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