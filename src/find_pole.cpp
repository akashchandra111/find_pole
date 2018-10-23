#include "find_pole.h"

int min_num(int num1, int num2)	{
	return (num1<num2)? num1:num2;
}

int max_num(int num1, int num2)	{
	return (num1>num2)? num1:num2;
}

int average(int* array, int count)	{
	if (count == 0)	return INFINITY;
	int total = 0;
	
	#if DEBUG
	PRINT_DBG;
	printf("total: %d\tcount: %d\n", total, count);
	#endif
	
	for (int i=0; i<count; ++i)	{
		total += array[i];

		#if DEBUG
		PRINT_DBG;
		printf("total = total + %d: %d\n", array[i], total);
		#endif

	}
	
	#if DEBUG
	PRINT_DBG;
	printf("avg: %d\n", total/count);
	#endif

	return total/count;
}

int max(int* array, int count)	{
	int max = 0;
	
	#if DEBUG
	PRINT_DBG;
	printf("max: %d\t count: %d\n", max, count);
	#endif

	for(int i=0; i<count; ++i)	{
		if (max < array[i])	max = array[i];

		#if DEBUG
		PRINT_DBG;
		printf("max: %d\n", max);
		#endif

	}
	return max;
}

int total_by_2(int* array, int count)	{
	int total = 0;
	for (int i=0; i<count; ++i)	{
		total += array[i];

		#if DEBUG
		PRINT_DBG;
		printf("total: %d\tarray: %d\n", total, array[i]);
		#endif

	}

	#if DEBUG
	PRINT_DBG;
	printf("half: %d\n", total/2);
	#endif
	
	return total/2;
}

int suitable_pole_len(int* array, int count)	{
	int arr[count];

	int most_suitable = total_by_2(array, count);
	bool max_found = false;

	while(!max_found)	{
		int suitables_1[count/2+1]={0}, remained[count/2+1]={0}, total1=0, total2=0;
		for (int i=0; i<count; ++i)	arr[i] = array[i];

		for (int i=count-1, itr1=0, itr2=0; i>=0; --i)	{
			if((array[i] != -1) && (total1+array[i] <= most_suitable))	{
				total1 += arr[i];
				suitables_1[itr1++] = arr[i];
				
				#if DEBUG
				PRINT_DBG;
				printf("[%d] [a1] suitable[%d]: %d\n", i, itr1-1, suitables_1[itr1-1]);
				#endif
			}
			else if((array[i] != -1) && (total2+array[i] <= most_suitable))	{
				total2 += arr[i];
				remained[itr2++] = arr[i];
				
				#if DEBUG
				PRINT_DBG;
				printf("[%d] [a2] remain[%d]: %d\n", i, itr2-1, remained[itr2-1]);
				#endif

			}
			else	{
				#if DEBUG
				PRINT_DBG;
				printf("[%d] [outside] \n", i);
				#endif
			}

		}
	
		most_suitable = (total1+total2)/2;

		#if DEBUG
		PRINT_DBG;
		printf("suitable number: %d\n", most_suitable);
		#endif

		if (total1 == total2)	return total1;
	}
	return 0;
}
