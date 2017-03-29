#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <emmintrin.h>

#define k 0.5
#define k4 5.0

void getWallTime(double *wct){
	struct timeval tp;//domh tou system
	gettimeofday(&tp,NULL);
	*wct = (double)(tp.tv_sec+(tp.tv_usec/1000000.0));}
	
main(){

	int i;
	float *fpix, *ftrans;
	double timeStart, timeEnd;
	__m128 *vpix, *vtrans;
	__m128 tempor; 
	__m128 temp;
	
	
	i=posix_memalign ((void**)&fpix, 16, 4*sizeof(float));
		if(i!=0){
		printf("error fpix");
		exit (0);
	
	}
	i=posix_memalign ((void**)&ftrans, 16, 4*sizeof(float));
		if(i!=0){
		printf("error fpix");
		free (fpix);
		exit (0);
		}
		
	
		
	vfpix=(__m128 *) fpix;
	vftrans = (__m128 *) ftrans;
    
	
	for(i=0;i<(M*N);i++){
		fpix[i]=rand();
		ftrans=0.0; }
		
	 getWallTime(&timeStart);

		for (i = 1; i < M - 1; i++) {
			for (j = 1; j < N - 1; j++){
				 tempor=_mm_set_ps(fpix[((i-1)*N+j)-1],fpix[((i-1)*N+j)],fpix[((i-1)*N+j)+1],fpix[(i*N+j)-1]);
				temp=_mm_set_ps(fpix[(i*N+j)+1],fpix[((i+1)*N+j)-1],fpix[((i+1)*N+j)],fpix[((i+1)*N+j)+1]);
				tempor=_mm_mul_ps(tempor,k);
				temp=_mm_mul_ps(temp,k);
				trans[i*N+j]=tempor+temp;
		 getWallTime(&timeEnd);
		 
		 printf("ektelestike se %lf sec\n", (timeEnd - timeStart));
		free(fpix);
		free(ftrans);
		return 0;
}
