#include <stdio.h>
#include <omp.h>

int main()
{
  int x = 1234;
  int iam = 0, np = 1, i = 0, j = 0;
  omp_set_num_threads(4);
#pragma omp parallel firstprivate(iam, np, i, x)
  {
    np = omp_get_num_threads();
    iam = omp_get_thread_num();
    printf("Soy el thread %d, antes de actualizar, con x=%d \n", iam, x); // mensajito para que le de tiempo al master a poner x=999
    x = iam * 1111;
    printf("\t\tSoy el thread %d, despues de actualizar, con x=%d \n", iam, x);

  } //parallel

  printf("\n Despues de pragma parallel x=%d \n\n", x);
} //main