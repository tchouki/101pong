/*
** EPITECH PROJECT, 2018
** 101pong
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_arg(char *argv[])
{
    for (int i = 1; argv[i] != NULL; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (argv[i][j] >= 48 || argv[i][j] <= 57 || argv[i][j] == '.' || argv[i][j] == '-') {
            }
            else {
                return (1);
            }
        }
    }
    return (0);
}

int check_last_arg(char *argv)
{
    for (int i = 0; argv[i] != '\0'; i++) {
        if (argv[i] < 48 || argv[i] > 57)
            return (1);
    }
    return (0);
}

void check_reach(float t6, float distance1, float distance2, float vit3)
{
    float cos;

    if (vit3 == 0 || vit3 < 0 && t6 < 0 || vit3 > 0 && t6 > 0)
        printf("The ball won't reach the bat.\n");
    else {
        cos = acos(distance2/distance1);
        cos *= 180/3.14159265359;
        if (__isnanf(cos)) {
            printf("The incidence angle is:\n");
            printf("0.00 degrees\n");
        } else {
            printf("The incidence angle is:\n");
            printf("%.2f degrees\n", cos);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argv[1] != NULL) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            printf("USAGE\n        ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
            printf("DESCRIPTION\n        x0    ball abscissa at time t - 1\n");
            printf("        y0    ball ordinate at time t - 1\n        z0    ball altitude at time t - 1\n");
            printf("        x1    ball abscissa at time t\n        y1    ball ordinate at time t\n");
            printf("        z1    ball altitude at time t\n        n     time shift (greater than or equal to zero, integrer\n");
            return (0);
        }
    }
    int error = check_arg(argv);
    if (error == 1) {
        printf("Not a number\n");
        return (84);
    }
    if (argc != 8) {
        printf("Bad arguments\n");
        return (84);
    }
    float f1 = atof(argv[1]);
    float f2 = atof(argv[2]);
    float f3 = atof(argv[3]);
    float f4 = atof(argv[4]);
    float f5 = atof(argv[5]);
    float f6 = atof(argv[6]);
    float vit1;
    float vit2;
    float vit3;
    float pos1;
    float pos2;
    float pos3;
    int n = atof(argv[7]);
    float distance1;
    float distance2;

    vit1 = f4 - f1;
    vit2 = f5 - f2;
    vit3 = f6 - f3;
    pos1 = f4 + (n * vit1);
    pos2 = f5 + (n * vit2);
    pos3 = f6 + (n * vit3);
    distance1 = sqrt(pow(vit1, 2) + pow(vit2, 2) + pow(vit3, 2));
    distance2 = sqrt(pow(vit1, 2) + pow(vit2, 2));
    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", vit1, vit2, vit3);
    printf("At time t + %d, ball coordinates will be:\n",n);
    printf("(%.2f, %.2f, %.2f)\n", pos1, pos2, pos3);
    check_reach(f6, distance1, distance2, vit3);
    return (0);
}