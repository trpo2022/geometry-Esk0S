#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SQR(x) x*x

typedef struct {
    double x1;
    double y1;
    double radius;
} circle;

double char_to_double();
double char_to_double_last();
int intersection_circles(circle, circle);