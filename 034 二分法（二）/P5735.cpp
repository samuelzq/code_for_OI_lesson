/**
 * https://www.luogu.com.cn/problem/P5735 
 *
 * @File:   p5735.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2023-12-24
 *
 */
#include <iostream>
#include <cmath>

using namespace std;

double dis(double x1, double y1, double x2, double y2)
{
    double x, y;
    x = x2 - x1;
    y = y2 - y1;
    return sqrt(x * x + y * y);
}

int main(void)
{
    double x1, y1, x2, y2, x3, y3, s;

    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    s = dis(x1, y1, x2, y2) + dis(x2, y2, x3, y3) + dis(x3, y3, x1, y1);
    printf("%.2lf\n", s);
    return 0;
}

