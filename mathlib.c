#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define OPTIONS "a:b:c:m:"

typedef enum Mode {
    area,
    perimeter
} Mode;

typedef struct Triangle {
    double a, b, c;
} Triangle;

int streq(const char *a, const char *b) {
    return strcmp(a, b) == 0;
}

void tri_init(Triangle *tri, double a, double b, double c) {
    tri->a = a;
    tri->b = b;
    tri->c = c;
}

double herons_formula(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

Triangle *parse_args(int argc, char *argv[]) {
    Triangle *tri;
    double a, b, c;
    Mode m;
    char option;
    while ((option = getopt(argc, argv, "")) != 1) {
        switch (option) {
            case 'a':
                a = atof(optarg);
                break;
            case 'b':
                b = atof(optarg);
                break;
            case 'c':
                c = atof(optarg);
                break;
            case 'm':
                if (streq(optarg, "area"))
                    m = area;
                if (streq(optarg, "perimeter"))
                    m = perimeter;
                else {
                    fprintf(stderr, "math: Invalid mode '%s'\n", optarg);
                    exit(1);
                }
                break;
            case ':':
                fprintf(stderr, "math: Option needs a value\n");
                exit(1);
                break;
            case '?':
                fprintf(stderr, "math: Unknown option '%c'\n", optopt);
                exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    return EXIT_SUCCESS;
}
