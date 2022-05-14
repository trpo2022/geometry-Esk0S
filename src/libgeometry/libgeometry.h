#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SQR(x) (x) * (x)

typedef struct {
    double x1;
    double y1;
    double radius;
} circle;

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct {
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
} triangle;

double char_to_double();
double char_to_double_last();
int intersection_circles(circle, circle);
int triangle_processing(triangle*, double*, double*);
int circle_processing(circle*, double*, double*);
int intersection_triangle(triangle tri1, triangle tri2);
int intersection_triangle_circle(circle cir, triangle tri);
int cross(
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3,
        double x4,
        double y4);
double perimeter_circle(circle* cir);
double area_circle(circle* cir);
double perimeter_triangle(double a, double b, double c);
double area_triangle(double p, double a, double b, double c);
int namecheck1(int is_circle1, int is_triangle1, circle cir1, triangle tri1);
int namecheck2(int is_circle2, int is_triangle2, circle cir2, triangle tri2);
int fig1_cir_check(char *figure1, char *circle1);
int fig1_tri_check(char *figure1, char *triangle1);
int fig2_cir_check(char *figure2, char *circle1);
int fig2_tri_check(char *figure2, char *triangle1);