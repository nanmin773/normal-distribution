#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "MT.h"
#define pi 3.14159265358979323846
//正規分布を発生させる関数 sgma 分散の平方根 mu 平均
double gn1(double sgma,double mu){
  double z,x,u;
  u=genrand_real3();
  z=sgma*(sqrt(2.0*log(1.0/(1.0-u))));
  u=genrand_real3();
  x=z*cos(2.0*pi*u);
  return x+mu;
}
// sgma muに対して乱数をN回発生させて回数を数える関数
void count_positive(double sgma,double mu, long *counter, long N){
	long A=0;
	for (long i = 0; i < N; i++){
		if (gn1(sgma,mu)>0){
			A++;
		}
	}
	*counter=A;
}
int main(void){
	clock_t st, ed;
	// time start
	st = clock();
	long N=100000000;
	unsigned int now=(unsigned int)time(NULL);
	init_genrand(now);//初期シード
	long c0,c1,c2; //counter 
	double u0=0;
	double u1=-0.1;
	double u2=-0.2;
	double sgma=1.0;
	count_positive(sgma,u0,&c0,N);
	count_positive(sgma,u1,&c1,N);
	count_positive(sgma,u2,&c2,N);
	printf("   u,  result\n");
	printf("%+.1f,%.6f\n",u0,(double)c0/(double)N);
	printf("%+.1f,%.6f\n",u1, (double)c1/(double)N);
	printf("%+.1f,%.6f\n", u2,(double)c2/(double)N);
	//time end
	ed = clock();
	// out time
	printf("Elapsed Time: %lf sec\n", (double)(ed - st) / CLOCKS_PER_SEC);
}
