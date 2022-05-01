#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SQR(x) (x) * (x)

typedef struct {
    double x1;
    double y1;
    double radius;
} circle;

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