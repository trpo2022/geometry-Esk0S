#include <ctest.h>
#include <libgeometry.h>
#include <stdlib.h>

CTEST(figures_suit, triangles_intersection)
{
    triangle tri1, tri2;

    tri1.x1 = 1.0;
    tri1.y1 = 1.0;
    tri1.x2 = 1.5;
    tri1.y2 = 4.0;
    tri1.x3 = 5.0;
    tri1.y3 = 2.0;
    tri1.x4 = 1.0;
    tri1.y4 = 1.0;

    tri2.x1 = 3.0;
    tri2.y1 = 1.0;
    tri2.x2 = 3.0;
    tri2.y2 = 4.0;
    tri2.x3 = 6.0;
    tri2.y3 = 3.0;
    tri2.x4 = 3.0;
    tri2.y4 = 1.0;

    int expected = 1;
    int result = intersection_triangle(tri1, tri2);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, circle_triangle_intersection)
{
    triangle tri;
    circle cir;

    tri.x1 = 1.0;
    tri.y1 = 1.0;
    tri.x2 = 1.5;
    tri.y2 = 4.0;
    tri.x3 = 5.0;
    tri.y3 = 2.0;
    tri.x4 = 1.0;
    tri.y4 = 1.0;

    cir.x1 = 2.0;
    cir.y1 = 1.0;
    cir.radius = 0.5;
    int expected = 1;
    int result = intersection_triangle_circle(cir, tri);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, circle_intersection)
{
    circle cir1, cir2;

    cir1.x1 = 2.0;
    cir1.y1 = 1.0;
    cir1.radius = 0.5;

    cir2.x1 = 2.0;
    cir2.y1 = 2.0;
    cir2.radius = 0.5;
    int ecpexted = 1;
    int result = intersection_circles(cir1, cir2);
    ASSERT_EQUAL(ecpexted, result);
}

CTEST(figure_suit, perimeter_cir)
{
    circle cir;

    cir.x1 = 2.0;
    cir.y1 = 1.0;
    cir.radius = 0.5;

    double expected = 2 * M_PI * cir.radius;
    int result = perimeter_circle(&cir);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, area_cir)
{
    circle cir;

    cir.x1 = 2.0;
    cir.y1 = 1.0;
    cir.radius = 0.5;

    double expected = M_PI * SQR(cir.radius);
    double result = area_circle(&cir);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, perimeter_tri)
{
    triangle tri;

    tri.x1 = 1.0;
    tri.y1 = 1.0;
    tri.x2 = 1.5;
    tri.y2 = 4.0;
    tri.x3 = 5.0;
    tri.y3 = 2.0;
    tri.x4 = 1.0;
    tri.y4 = 1.0;

    double a = sqrt(SQR(tri.x2 - tri.x1) + SQR(tri.y2 - tri.y1));
    double b = sqrt(SQR(tri.x3 - tri.x2) + SQR(tri.y3 - tri.y2));
    double c = sqrt(SQR(tri.x4 - tri.x3) + SQR(tri.y4 - tri.y3));
    double expected = a + b + c;
    double result = perimeter_triangle(a, b, c);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, area_tri)
{
    triangle tri;

    tri.x1 = 1.0;
    tri.y1 = 1.0;
    tri.x2 = 1.5;
    tri.y2 = 4.0;
    tri.x3 = 5.0;
    tri.y3 = 2.0;
    tri.x4 = 1.0;
    tri.y4 = 1.0;

    double a = sqrt(SQR(tri.x2 - tri.x1) + SQR(tri.y2 - tri.y1));
    double b = sqrt(SQR(tri.x3 - tri.x2) + SQR(tri.y3 - tri.y2));
    double c = sqrt(SQR(tri.x4 - tri.x3) + SQR(tri.y4 - tri.y3));
    double perimeter = perimeter_triangle(a, b, c);
    double p = (perimeter) / 2;
    double expected = sqrt(p * (p - a) * (p - b) * (p - c));
    double result = area_triangle(p, a, b, c);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, name_check)
{
    char figure1[50] = "circle(";
    char figure2[50] = "triangle(";
    char circle1[7] = {"circle"};
    char triangle1[9] = {"triangle"};
    int fig = 0;

    if (fig1_cir_check(figure1, circle1)) {
        fig = 1;
    } else if (fig1_tri_check(figure1, triangle1)) 
            fig = 1;
    else if (fig2_cir_check(figure2, circle1))
            fig = 1;
    else if (fig2_tri_check(figure2, triangle1))
            fig = 1;
    
    ASSERT_EQUAL(1, fig);     
}