#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <time.h>
#include<pthread.h>
#include <stdlib.h> 
//int SharedVariable = 0;
pthread_mutex_t mutex;
pthread_mutex_t mutex1;
pthread_barrier_t our_barrier;

int SharedVariable = 0;

void *SimpleThread(void *which){
	int num,val;
	long wh;
	wh = (long) which;
	for(num = 0; num < 20; num++){
		if(rand() > RAND_MAX/2)
	      		usleep(500);		
			  
	pthread_mutex_lock(&mutex);
	val = SharedVariable;
	printf("*** thread %ld sees value %d\n",wh,val);
	//printf("%d\n",num);
	SharedVariable = val+1;
	pthread_mutex_unlock(&mutex);
	//printf("*** after thread %ld sees value %d\n",wh,SharedVariable);
	}
	pthread_barrier_wait(&our_barrier);
	val = SharedVariable;
	printf("Finaly Thread %ld sees final value %d\n",wh,val);
}




int main(int argc, char *argv[])
{
	void *SimpleThread(void *which);
	//int SharedVariable = 0;
	//printf("%s",argv[1]);
	//SimpleThread(5);
	char *p;
	long arg = strtol(argv[1], &p, 10);
	pthread_barrier_init(&our_barrier,NULL,arg);
	if (*p != '\0')
	{
		printf("Please provide a number");
	
	}
	else{
	//printf("%ld\n",arg);
	pthread_t threads[arg];
	//long t_num = 5;
	int rc;
	for(long t = 0; t < arg; t++){
		//printf("In main: creating thread %ld\n", t);
		//pthread_mutex_lock(&mutex1);
		rc = pthread_create(&threads[t], NULL, SimpleThread, (void*)t);
		//pthread_mutex_unlock(&mutex1);}
	}
}
pthread_exit(NULL);
}
	
