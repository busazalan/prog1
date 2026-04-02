#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Pont;

double distance(Pont p1, Pont p2) {

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {
    Pont a = { 1, 2 };
    Pont b = { 6, 5 };

    printf("A két pont közti távolság: %lf\n", distance(a, b));

    return 0;
}
