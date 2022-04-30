#include <libgeometry/libgeometry.h>

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