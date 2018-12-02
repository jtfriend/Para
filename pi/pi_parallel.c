#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

static long num_steps = 100000000;
double step;

#define NUM_THREADS 2

int main() {

  clock_t begin = clock();

  int i, nthreads;
  double pi, sum[NUM_THREADS];

  step = 1.0/ (double) num_steps;

  omp_set_num_threads(NUM_THREADS);

  #pragma omp parallel
  {
    int i, id, nthrds;
    double x;

    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    if (id == 0) nthreads = nthrds;

    for(i=id, sum[id]=0.0; i< num_steps; i=i+nthrds) {
      x = (i+0.5) * step;
      sum[id] += 4.0 / (1.0 + x*x);
    }

  }
  for (i = 0, pi=0; i< nthreads; i++) {
    pi += sum[i] * step;
  }

  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("pi: %f", pi);
  printf(" time: %f\n", time_spent);
}
