#include "mm.h"
void kernel_mm(){
	for (int i1 = 0; i1 < 1024; ++i1){
	    for (int j1 = 0; j1 < 1024; ++j1){
			for (int k1 = 0; k1 < 1024; ++k1){
				       C[i1][j1] += A[i1][k1] * B[k1][j1]; // S1
			}
	    }
	}
}

int main(int argc, char** argv){
	initialize();
	kernel_mm();
	check_correctness();
	return 0;
}
