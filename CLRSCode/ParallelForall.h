//////////////////////////////////////////////////////////////////////////
//
//	ParallelForall.h
//  https://developer.nvidia.com/content/easy-introduction-cuda-c-and-c
//
//  _K: kernel functon, _D: device function
//
//	Written by Meng Zhu ,Zhejiang University (zhumeng1989@gmail.com)
//	Creation date: Oct.29 2012, 20:03
//
//	All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////

#ifndef ParallelForall_H
#define ParallelForall_H

#include "CudaExt.h"

namespace pf {

void SAXPY_D(int nb, int nt, int n, float a, float *x, float *y);

void SAXPY()
{
	int N = 1<<20;
	float *x, *y, *d_x, *d_y;
	x = (float*)malloc(N*sizeof(float));
	y = (float*)malloc(N*sizeof(float));

	cudaMalloc(&d_x, N*sizeof(float)); 
	cudaMalloc(&d_y, N*sizeof(float));

	for (int i = 0; i < N; i++) {
		x[i] = 1.0f;
		y[i] = 2.0f;
	}

	cudaMemcpy(d_x, x, N*sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(d_y, y, N*sizeof(float), cudaMemcpyHostToDevice);

	// Perform SAXPY on 1M elements
	SAXPY_D((N+255)/256, 256, N, 2.0, d_x, d_y);

	cudaMemcpy(y, d_y, N*sizeof(float), cudaMemcpyDeviceToHost);

	float maxError = 0.0f;
	for (int i = 0; i < N; i++)
		maxError = std::max(maxError, abs(y[i]-4.0f));
	printf("Max error: %fn\n", maxError);
}

}

#endif