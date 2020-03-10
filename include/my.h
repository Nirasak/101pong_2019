/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

typedef struct vect
{
    double x0;
    double y0;
    double z0;
    double x1;
    double y1;
    double z1;
    double vx;
    double vy;
    double vz;
    double angle;
    int n;
} vect_t;

int print_descr(void);
int pong(char **av);

#endif
