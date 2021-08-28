#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int N = 10000;
int data[N];

int result_sum, result_max;
void *compute_sum(void *param);
void *compute_max(void *param);

int main(int argc, char *argv[]) {
	// initialize data
	for (int i = 0; i < N; i++) data[i] = i + 1;
	std::random_shuffle(data, data + N);

	pthread_t tid_sum, tid_max;
	pthread_attr_t attr;
	char array_size[1024];
	sprintf(array_size, "%d", N); // conver N to char*

	pthread_attr_init(&attr);

	pthread_create(&tid_sum, &attr, compute_sum, (void *) array_size);
	pthread_create(&tid_max, &attr, compute_max, (void *) array_size);

	pthread_join(tid_sum, NULL);
	pthread_join(tid_max, NULL);

	printf("sum = %d  max = %d\n", result_sum, result_max);
}

void *compute_sum(void *param) {
	int limit = atoi((char *) param);
	result_sum = 0;
	for (int i = 0; i < limit; i++)
		result_sum += data[i];
	
	pthread_exit(0);
}

void *compute_max(void *param) {
	int limit = atoi((char *) param);
	result_max = data[0];
	for (int i = 1; i < limit; i++)
		if (data[i] > result_max)
			result_max = data[i];
	
	pthread_exit(0);
}