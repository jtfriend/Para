#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static long num_steps = 100000000;
double step;

int main() {

    clock_t begin = clock();
  int i;
  double x, pi, sum;
  sum = 0.0;

  step = 1.0/ (double) num_steps;

  for(i=0; i< num_steps; i++) {
    x = (i+0.5) * step;
    sum = sum + 4.0 / (1.0 + x*x);
  }
  pi = step * sum;
 
  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("pi: %f", pi);
  printf(" time: %f\n", time_spent);
}
