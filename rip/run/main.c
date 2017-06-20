#include "PLA.h"
#define N 1024
int C[N][N], A[N][N], B[N][N];
int D[N][N], E[N][N], F[N][N];
int G[N][N];
__attribute__((flatten))
int main(){
	int i1 =0, j1, k1; 
	int i2 =0, j2, k2;
	int i3 =0, j3, k3;

#pragma clang loop critical(disable)
	for (; i1 < N; ++i1){
		int InLine = 1;
		double lat_hw = LAT_HW_1;
		double lat_sw = 25325039000.000000;
		double power_hw = POW_HW_1;
		double power_sw = 1.77;
		int BRAM = BRAM_HW_1;
		int DSP = DSP_HW_1;
		int LUT = LUT_HW_1;
		int FF = FF_HW_1;
	    for (j1 = 0; j1 < N; ++j1){
			for (k1 = 0; k1 < N; ++k1){
				       C[i1][j1] += A[i1][k1] * B[k1][j1]; // S1
			}
	    }
	}
#pragma clang loop critical(disable)
	for (; i2 < N; ++i2){
		int InLine = 1;
		double lat_hw = LAT_HW_2;
		double lat_sw = 25328931000.000000;
		double power_hw = POW_HW_2;
		double power_sw = 1.72;
		int BRAM = BRAM_HW_2;
		int DSP = DSP_HW_2;
		int LUT = LUT_HW_2;
		int FF = FF_HW_2;
		  for (j2 = 0; j2 < N; ++j2){
			      for (k2 = 0; k2 < N; ++k2){
					     D[i2][j2] += E[i2][k2] * F[k2][j2]; // S2
			}
	    }
	}
#pragma clang loop critical(disable)
	for (; i3 < N; ++i3){
		int InLine = 1;
		double lat_hw = LAT_HW_3;
		double lat_sw = 162225655000;
		double power_hw = POW_HW_3;
		double power_sw = 1.72;
		int BRAM = BRAM_HW_3;
		int DSP = DSP_HW_3;
		int LUT = LUT_HW_3;
		int FF = FF_HW_3;
		  for (j3 = 0; j3 < N; ++j3){
			      for (k3 = 0; k3 < N; ++k3){
					     G[i3][j3] += C[i3][k3] * D[k3][j3]; // S3
			}
	    }
	}
	return 0;
}
