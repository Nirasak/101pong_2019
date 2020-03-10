/*
** EPITECH PROJECT, 2019
** pong.c
** File description:
** pong
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "my.h"

#define ABS(x) (x) > 0 ? (x) : -(x)

int init_struct(char **av, vect_t *vect)
{
    for (int i = 1; i < 7; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if ((av[i][j] < '0' || av[i][j] > '9')
                && av[i][j] != '.' && av[i][j] != '-')
                return (84);
    for (int j = 0; av[7][j] != '\0'; j++)
        if (av[7][j] < '0' || av[7][j] > '9')
            return (84);
    vect->x0 = atof(av[1]);
    vect->y0 = atof(av[2]);
    vect->z0 = atof(av[3]);
    vect->x1 = atof(av[4]);
    vect->y1 = atof(av[5]);
    vect->z1 = atof(av[6]);
    vect->n = atoi(av[7]);
    vect->vx = vect->x1 - vect->x0;
    vect->vy = vect->y1 - vect->y0;
    vect->vz = vect->z1 - vect->z0;
    vect->angle = 0;
    return (0);
}

void print_result(vect_t *vect)
{
    double a = sqrt(powf(vect->vx, 2) + powf(vect->vy, 2) + powf(vect->vz, 2));

    printf(
        "The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n",
        vect->vx, vect->vy, vect->vz);
    printf(
        "At time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n",
        vect->n, vect->vx * vect->n + vect->x1, vect->vy * vect->n + vect->y1,
        vect->vz * vect->n + vect->z1);
    if ((vect->z1 > 0 && (vect->vz * vect->n + vect->z1) > 0)
        || (vect->z1 < 0 && (vect->vz * vect->n + vect->z1) < 0)
        || a == 0)
        printf("The ball won't reach the paddle.\n");
    else
        printf(
            "The incidence angle is:\n%.2f degrees\n",
            fabs(90 - acos(vect->vz / a) * 180 / M_PI));
}

int pong(char **av)
{
    vect_t vect;

    if (init_struct(av, &vect) == 84)
        return (84);
    print_result(&vect);
    return (0);
}
