#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int my_pow_iterative(int n,int e){
	if(e == 0){
		return 1;
	}else{
		int i=0;
		for(i=0;i<e;i++){
			n = n * n ;
		}
		return n;
	}
}

int my_pow_recursivee(int n,int e){
	if(e == 0){ return 1 ; }
	else if(e == 1){ return n; }
	else{
		return n * my_pow_recursivee(n,e-1);
	}
}

int factorielle_iterative(int n){
	int res=1;
	while(n > 0){
		res *= n;
		n--;
	}
	return res;
}

int factorielle_recursive(int n){
	if( n == 0 ){ return 1 ; }
	else if(n == 1){ return n ;}
	else{ return n * factorielle_recursive(n-1); }
}

unsigned long bench_fac_rec(int nbOp,int param){
	unsigned long start=time(NULL);
	int i=0;
	for(i=0;i<nbOp;++i){
		factorielle_recursive(param);
	}
	unsigned long end=time(NULL);

	return end-start;
}
unsigned long bench_fac_iter(int nbOp,int param){
	int start=time(NULL);
	int i=0;
	for(i=0;i<nbOp;++i){
		factorielle_iterative(param);
	}
	unsigned long end=time(NULL);

	return end-start;
}


int fibonacci_iterative(int n){
	if ( n == 0){ return 0 ; }
	else if(n == 1) return 1 ; 
	else if (n == 2) return 1;
	else{
		int m1=1,m2=1,mem,i;
		for(i=1;i<n-2;++i){
			mem = m2;
			m2 = m1 + m2;
			m1 = mem;	
		}

		return m1+m2;
	}
}

int fibonacci_recursive(int n){
	if ( n == 0){ return 0 ; }
	else if(n == 1) return 1 ; 
	else if (n == 2) return 1;
	else{
		return fibonacci_recursive(n-2) + fibonacci_recursive(n-1);	}

}

unsigned long bench_fib_iter(int nbOp,int param){
	int start=time(NULL);
	int i=0;
	for(i=0;i<nbOp;++i){
		fibonacci_iterative(param);
	}
	unsigned long end=time(NULL);

	return end-start;
}

unsigned long bench_fib_rec(int nbOp,int param){
	int start=time(NULL);
	int i=0;
	for(i=0;i<nbOp;++i){
		fibonacci_recursive(param);
	}
	unsigned long end=time(NULL);

	return end-start;
}
void main(){
	
	//printf("function=%s ; nbOp=%d ; param = %d ; Ellapsed time = %d\n" ,"factorielle_iterative",1000000000,42,bench_fac_iter(1000000000,42 ));


	//printf("function=%s ; nbOp=%d ; param = %d ; Ellapsed time = %d\n" ,"factorielle_recursive",1000000000,42,bench_fac_rec(1000000000,42 ));

	// printf("test fibonacci_recursive(5)=%d\n",fibonacci_recursive(5));
	// printf("test fibonacci_recursive(8)=%d\n",fibonacci_recursive(8));
	// printf("test fibonacci_recursive(12)=%d\n",fibonacci_recursive(12));

	// printf("test fibonacci_iterative(5)=%d\n",fibonacci_iterative(5));
	// printf("test fibonacci_iterative(8)=%d\n",fibonacci_iterative(8));
	// printf("test fibonacci_iterative(12)=%d\n",fibonacci_iterative(12));

	printf("function=%s ; nbOp=%d ; param = %d ; Ellapsed time = %d\n" ,"fibonacci_iterative",100000000,42,bench_fib_iter(100000000,42 ));
	printf("function=%s ; nbOp=%d ; param = %d ; Ellapsed time = %d\n" ,"fibonacci_recursive",100000000,42,bench_fac_rec(100000000,42 ));


}