#include <cstdio>
#include "src/find_pole.cpp"

int main()	{
	int arr[]={1, 2, 4, 6, 9};
	int count=sizeof(arr)/sizeof(arr[0]);
	printf("avg: %d\tmax: %d\ttotal/2: %d\n", average(arr, count), max(arr, count), total_by_2(arr, count));
	printf("max pole length: %d\n", suitable_pole_len(arr, count));	
	return 0;
}
