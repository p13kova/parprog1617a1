#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define k 0.5
#define k4 5.0

void getWallTime(double *wct){
	struct timeval tp;//domh tou system
	gettimeofday(&tp,NULL);
	*wct = (double)(tp.tv_sec+(tp.tv_usec/1000000.0));}

int main(){
	float *pix , *trans;
	double timeStart , timeEnd;
	int i,j;
	pix = (float *) malloc(M*N*sizeof(float));
	if(pix == NULL){
		exit(1);
	}
	trans = (float *) malloc(M*N*sizeof(float));
	if(trans == NULL){
		free(pix);
		exit(1);
	}

	for(i=0;i<(M*N);i++){
	  pix[i]=(float)rand();
	  trans[i]=0.0;	
	}

	getWallTime(&timeStart);
	
	for (i = 1; i < M - 1; i++) {
       		 for (j = 1; j < N - 1; j++) {
			trans[i*N+j]=k*pix[((i-1)*N+j)-1]+k*pix[(i-1)*N+j]+k*pix[((i-1)*N+j)-1]+k4*pix[(i*N+j)-1]+k*pix[(i*N+j)+1]+k*pix[((i+1)*N+j)+1]+k*pix[(i+1)*N+j]+k*pix[((i+1)*N+j)+1];
	


}}
	getWallTime(&timeEnd);
	free(pix);
	free(trans);
	float time;
	time=(timeEnd - timeStart);
	
	printf("ektelestike se  %lf sec\n",time);
	return 0;

}
