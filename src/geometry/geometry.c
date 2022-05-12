#include <libgeometry/libgeometry.h>

int main()
{
    int i, is_circle1 = 0, is_circle2 = 0, is_triangle1 = 0, is_triangle2 = 0;
    circle cir1;
    circle cir2;
    triangle tri1;
    triangle tri2;
    char figure1[50];
    char figure2[50];

    char circle1[7] = {"circle"};
    char triangle1[9] = {"triangle"};

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

    if ((figure1[0] == triangle1[0]) || (figure1[0] == triangle1[0] - 32)) {
        for (i = 1; figure1[i] != '('; i++) {
            if ((figure1[i] == triangle1[i])
                || (figure1[i] == triangle1[i] - 32)) {
                is_triangle1 = 1;
            } else {
                is_triangle1 = 0;
                break;
            }
        }
    }

    if (is_circle1 == 1) {
        double perimeter;
        double area;
        if (circle_processing(&cir1, &perimeter, &area)) {
            printf("Perimeter: %lf\n", perimeter);
            printf("Area: %lf\n", area);
        } else
            return 0;
    } else if (is_triangle1 == 1) {
        double perimeter;
        double area;
        if (triangle_processing(&tri1, &perimeter, &area)) {
            printf("Perimeter: %lf\n", perimeter);
            printf("Area: %lf\n", area);
        } else
            return 0;
    } else {
        printf("Unexpected figure\n");
        return 0;
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

    if ((figure2[0] == triangle1[0]) || (figure2[0] == triangle1[0] - 32)) {
        for (i = 1; figure2[i] != '('; i++) {
            if ((figure2[i] == triangle1[i])
                || (figure2[i] == triangle1[i] - 32)) {
                is_triangle2 = 1;
            } else {
                is_triangle2 = 0;
                break;
            }
        }
    }

    if (is_circle2 == 1) {
        double perimeter;
        double area;
        if (circle_processing(&cir2, &perimeter, &area)) {
            printf("Perimeter: %lf\n", perimeter);
            printf("Area: %lf\n", area);
        } else
            return 0;
    } else if (is_triangle2 == 1) {
        double perimeter;
        double area;
        if (triangle_processing(&tri2, &perimeter, &area)) {
            printf("Perimeter: %lf\n", perimeter);
            printf("Area: %lf\n", area);
        } else
            return 0;
    } else {
        printf("Unexpected figure\n");
    }

    if (is_circle1 == 1 && is_circle2 == 1) {
        int flag = intersection_circles(cir1, cir2);

        if (flag == 1) {
            printf("Intersect\n");
        } else {
            printf("Do not intersect\n");
        }
    }

    if (is_triangle1 == 1 && is_triangle2 == 1) {
        int flag = intersection_triangle(tri1, tri2);

        if (flag == 1) {
            printf("Intersect\n");
        } else {
            printf("Do not intersect\n");
        }
    }

    return 0;
}