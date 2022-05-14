#include <libgeometry.h>

double char_to_double()
{
    double double_from_char;
    char last_getch;
    int integer;
    char intch;
    int dec_length;
    while ((last_getch = getchar()) == ' ')
        continue;

    integer = (last_getch - '0') * 10;
    while ((intch = getchar()) != '.') {
        integer = (intch - '0' + integer) * 10;
    }
    integer /= 10;

    float dec = 0;
    char decch;

    dec_length = 0;
    while (((decch = getchar()) != ' ') && (decch != ',')) {
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
    while ((last_getch = getchar()) == ' ')
        continue;

    integer = (last_getch - '0') * 10;
    while ((intch = getchar()) != '.') {
        integer = (intch - '0' + integer) * 10;
    }
    integer /= 10;

    float dec = 0;
    char decch;

    dec_length = 0;

    while (((decch = getchar()) != ')') && (decch != ' ')) {
        dec = (decch - '0' + dec) * 10;
        dec_length += 1;
    }
    dec /= 10;

    if (decch != ')') {
        while ((last_getch = getchar()) == ' ')
            continue;

        if (last_getch != ')') {
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

    x_difference = fabs(cir1.x1 - cir2.x1);
    y_difference = fabs(cir1.y1 - cir2.y1);

    r_vec = sqrt(SQR(x_difference) + SQR(y_difference));

    r_summ = cir1.radius + cir2.radius;

    if (r_vec <= r_summ) {
        flag = 1;
    } else
        flag = 0;

    return flag;
}

double perimeter_triangle(double a, double b, double c)
{
    double perimeter = a + b + c;

    return perimeter;
}

double area_triangle(double p, double a, double b, double c)
{
    double area = sqrt(p * (p - a) * (p - b) * (p - c));

    return area;
}

int triangle_processing(triangle* tri, double* perimeter, double* area)
{
    tri->x1 = char_to_double();
    tri->y1 = char_to_double();
    tri->x2 = char_to_double();
    tri->y2 = char_to_double();
    tri->x3 = char_to_double();
    tri->y3 = char_to_double();
    tri->x4 = char_to_double();
    tri->y4 = char_to_double_last();

    if (tri->x1 != tri->x4 || tri->y1 != tri->y4) {
        printf("First and last coordinates must be the same\n");
        return 0;
    }
    double a = sqrt(SQR(tri->x2 - tri->x1) + SQR(tri->y2 - tri->y1));
    double b = sqrt(SQR(tri->x3 - tri->x2) + SQR(tri->y3 - tri->y2));
    double c = sqrt(SQR(tri->x4 - tri->x3) + SQR(tri->y4 - tri->y3));
    // *perimeter = a + b + c;
    *perimeter = perimeter_triangle(a, b, c);

    double p = (*perimeter) / 2;
    // *area = sqrt(p * (p - a) * (p - b) * (p - c));
    *area = area_triangle(p, a, b, c);
    return 1;
}

double perimeter_circle(circle* cir)
{
    double perimeter = 2 * M_PI * cir->radius;

    return perimeter;
}

double area_circle(circle* cir)
{
    double area = M_PI * SQR(cir->radius);

    return area;
}

int circle_processing(circle* cir, double* perimeter, double* area)
{
    cir->x1 = char_to_double();
    cir->y1 = char_to_double();

    cir->radius = char_to_double_last();
    if (cir->radius == 0) {
        printf("Radius cannot be zero\n");
        return 0;
    }
    *perimeter = perimeter_circle(cir);

    *area = area_circle(cir);
    return 1;
}

int cross(
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3,
        double x4,
        double y4)
{
    double denominator = (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);
    int ff = 0;
    if (denominator == 0) {
        if ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1)
                    == 0
            && (x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1)
                    == 0)
            ff = 1;
        else
            ff = 0;
    } else {
        double numerator_a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
        double numerator_b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
        double Ua = numerator_a / denominator;
        double Ub = numerator_b / denominator;

        ff = (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1 ? 1 : 0);
    }
    return ff;
}

int intersection_triangle(triangle tri1, triangle tri2)
{
    Point a[4], b[4];

    a[0].x = tri1.x1;
    a[0].y = tri1.y1;
    a[1].x = tri1.x2;
    a[1].y = tri1.y2;
    a[2].x = tri1.x3;
    a[2].y = tri1.y3;
    a[3].x = tri1.x4;
    a[3].y = tri1.y4;

    b[0].x = tri2.x1;
    b[0].y = tri2.y1;
    b[1].x = tri2.x2;
    b[1].y = tri2.y2;
    b[2].x = tri2.x3;
    b[2].y = tri2.y3;
    b[3].x = tri2.x4;
    b[3].y = tri2.y4;

    int ff = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ff
                    = cross(a[i].x,
                            a[i].y,
                            a[i + 1].x,
                            a[i + 1].y,
                            b[j].x,
                            b[j].y,
                            b[j + 1].x,
                            b[j + 1].y);
        }
    }
    if (ff) {
        return 1;
    }
    return 0;
}

int intersection_triangle_circle(circle cir, triangle tri)
{
    const double eps = 1e-10;
    double x0 = cir.x1;
    double y0 = cir.y1;
    double r = cir.radius;
    double x1, x2, y1, y2;
    int track = 0;
    Point p[4];

    p[0].x = tri.x1;
    p[2].x = tri.x3;
    p[0].y = tri.y1;
    p[2].y = tri.y3;
    p[1].x = tri.x2;
    p[3].x = tri.x4;
    p[1].y = tri.y2;
    p[3].y = tri.y4;

    for (int i = 0; i < 3; i++) {
        x1 = p[i].x;
        y1 = p[i].y;
        x2 = p[i + 1].x;
        y2 = p[i + 1].y;

        double dx01 = x1 - x0, dy01 = y1 - y0, dx12 = x2 - x1, dy12 = y2 - y1;
        double a = SQR(dx12) + SQR(dy12);
        printf("%lf\n", a);
        if (fabs(a) < eps) {
            printf("Координаты начала и конца совпадают\n");
            return 0;
        }
        double k = dx01 * dx12 + dy01 * dy12;
        double c = SQR(dx01) + SQR(dy01) - SQR(r);
        double d1 = SQR(k) - a * c;
        if (d1 >= 0 && fabs(d1) < eps) {
            double t = -k / a;
            track++;
            if (t > 0 - eps && t < 1 + eps) {
                track++;
            }
        } else if (d1 >= 0)
            track++;
    }
    if (track > 0)
        return 1;
    return 0;
}

int namecheck1(int is_circle1, int is_triangle1, circle cir1, triangle tri1)
{
    if (is_circle1 == 1) {
        double perimeter;
        double area;
        if (circle_processing(&cir1, &perimeter, &area)) {
            printf("Perimeter: %lf\n", perimeter);
            printf("Area: %lf\n", area);
            return 1;
        }
        return 0;
    } else if (is_triangle1 == 1) {
        double perimeter;
        double area;
        if (triangle_processing(&tri1, &perimeter, &area)) {
            printf("Perimeter: %lf\n", perimeter);
            printf("Area: %lf\n", area);
            return 1;
        }
        return 0;
    }
    printf("Unexpected figure\n");
    return 0;
}

int namecheck2(int is_circle2, int is_triangle2, circle cir2, triangle tri2)
{
    if (is_circle2 == 1) {
        double perimeter;
        double area;
        if (circle_processing(&cir2, &perimeter, &area)) {
            printf("Perimeter: %lf\n", perimeter);
            printf("Area: %lf\n", area);
            return 1;
        }
        return 0;
    } else if (is_triangle2 == 1) {
        double perimeter;
        double area;
        if (triangle_processing(&tri2, &perimeter, &area)) {
            printf("Perimeter: %lf\n", perimeter);
            printf("Area: %lf\n", area);
            return 1;
        }
        return 0;
    }
    printf("Unexpected figure\n");
    return 0;
}

int fig1_cir_check(char *figure1, char *circle1)
{
    int is_circle1;
    if ((figure1[0] == circle1[0]) || (figure1[0] == circle1[0] - 32)) {
        for (int i = 1; figure1[i] != '('; i++) { // int добавил
            if ((figure1[i] == circle1[i]) || (figure1[i] == circle1[i] - 32)) {
                is_circle1 = 1;
            } else {
                is_circle1 = 0;
                break;
            }
        }
    }
    return is_circle1;
}

int fig1_tri_check(char *figure1, char *triangle1)
{
    int is_triangle1;
    if ((figure1[0] == triangle1[0]) || (figure1[0] == triangle1[0] - 32)) {
        for (int i = 1; figure1[i] != '('; i++) {
            if ((figure1[i] == triangle1[i])
                || (figure1[i] == triangle1[i] - 32)) {
                is_triangle1 = 1;
            } else {
                is_triangle1 = 0;
                break;
            }
        }
    }
    return is_triangle1;
}

int fig2_cir_check(char *figure2, char *circle1)
{
    int is_circle2;
    if ((figure2[0] == circle1[0]) || (figure2[0] == circle1[0] - 32)) {
        for (int i = 1; figure2[i] != '('; i++) {
            if ((figure2[i] == circle1[i]) || (figure2[i] == circle1[i] - 32)) {
                is_circle2 = 1;
            } else {
                is_circle2 = 0;
                break;
            }
        }
    }
    return is_circle2;
}

int fig2_tri_check(char *figure2, char *triangle1)
{
    int is_triangle2;
    if ((figure2[0] == triangle1[0]) || (figure2[0] == triangle1[0] - 32)) {
        for (int i = 1; figure2[i] != '('; i++) {
            if ((figure2[i] == triangle1[i])
                || (figure2[i] == triangle1[i] - 32)) {
                is_triangle2 = 1;
            } else {
                is_triangle2 = 0;
                break;
            }
        }
    }
    return is_triangle2;
}