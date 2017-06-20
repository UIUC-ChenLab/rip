#ifndef MM_H
#define MM_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define DATA_TYPE int
int C[1024][1024], A[1024][1024], B[1024][1024];
int D[1024][1024], E[1024][1024], F[1024][1024];
int G[1024][1024];

void initialize(){
  int i, j;
  for(i = 0; i < 1024; i++){
    for(j  =0; j < 1024; j++){
      A[i][j] = (i+j)%3;
      B[i][j] = (i+j)%7;
      C[i][j] = 0;
    }
  }
}

void check_correctness(){
  FILE *fp;
  int i;
  fp = fopen("result.txt", "w");
    fprintf(fp, "%d\n", C[1024-1][1024-1]);
  fclose(fp);
  int result = system("diff result.txt result_gold.txt");
  assert(result == 0);
}
#endif
