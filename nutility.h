#ifndef  NUTILITY_H
#define  NUTILITY_H

#include <stddef.h>

#define  isleap(y)    ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define  asize(ar)    (sizeof(ar) / sizeof(ar[0]))

#define  csmf(c)   void set_matrix_##c(int (*p)[c], size_t size) {\
	for (size_t i = 0; i < size; ++i) { \
		for (size_t k = 0; k < c; ++k) { \
			p[i][k] = rand() % 10; }}}

#define  cdmf(c)   void display_matrix_##c(const int (*p)[c], size_t size) {\
	for (size_t i = 0; i < size; ++i) { \
		for (size_t k = 0; k < c; ++k) { \
			printf("%d", p[i][k]);}\
			printf("\n");}pline();}


typedef int Bool;

//function declarations
int isprime(int);
int ndigit(int);
void sleep(double second);
void pline(void);
void randomize(void);
void sgets(char *p);
void sgets_s(char *p, int size);
void set_random_array(int *p, size_t size);
void set_random_array2(int *p, size_t size, int low, int high);

void display_array(const int *p, size_t size);
void sort(int *p, size_t size);
void swap(int *p1, int *p2);
void gswap(void *vp1, void *vp2, size_t n);
const char *random_name(void);
const char *random_surname(void);
const char *random_town(void);


#endif