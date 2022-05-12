#include <libgeometry/libgeometry.h>

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

    x_difference = abs(cir1.x1 - cir2.x1);
    y_difference = abs(cir1.y1 - cir2.y1);

    r_vec = sqrt(SQR(x_difference) + SQR(y_difference));

    r_summ = cir1.radius + cir2.radius;

    if (r_vec <= r_summ) {
        flag = 1;
    } else
        flag = 0;

    return flag;
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
    *perimeter = a + b + c;

    double p = (*perimeter) / 2;
    *area = sqrt(p * (p - a) * (p - b) * (p - c));
    return 1;
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
    *perimeter = 2 * M_PI * cir->radius;

    *area = M_PI * SQR(cir->radius);
    return 1;
}

double s_n(Point a[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        double det = a[i % n].x * a[(i + 1) % n].y - a[(i + 1) % n].x * a[i % n].y;
        sum += det;
    }
    return fabs(sum / 2);
}

int intersection_triangle(triangle tri1, triangle tri2)
{
    const double EPS = 1e-10;

    Point a[3], b[3];

    a[0].x = tri1.x1;
    a[0].y = tri1.y1;
    a[1].x = tri1.x2;
    a[1].y = tri1.y2;
    a[2].x = tri1.x3;
    a[2].y = tri1.y3;

    b[0].x = tri2.x1;
    b[0].y = tri2.y1;
    b[1].x = tri2.x2;
    b[1].y = tri2.y2;
    b[2].x = tri2.x3;
    b[2].y = tri2.y3;

    double sa = s_n(a, 3);

    int flag = 0;
    for (int i = 0; i < 3; ++i) {
        double sum = 0;
        for (int j = 0; j < 3; ++j) {
            Point c[3];
            for (int k = 0; k < 3; ++k)
                if (k == j)
                    c[k] = b[i];
                else
                    c[k] = a[k];

            double sc = s_n(c, 3);

            sum += sc;
        }

        if (fabs(sa - sum) < EPS) {
            flag = 1;
            break;
        }
    }

    return flag;
}