#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void printRepeating(int arr[], int size)
{
  int *count = (int *)malloc(sizeof(size));
  unsigned int newarray[size];
  memset(newarray, 0,size*(sizeof(int)));
  int i;
  int k = 0;
  for(i = 0; i < size; i++)
  {  
    if(count[arr[i]] == 1)
      printf("duplicate array value : %d \n", arr[i]);
    else
	{
	if (arr[i] > 0 )
		newarray[k] = arr[i];
	k++;
	count[arr[i]]++;
	}
  }    
  int j;
  for (j = 0; j < sizeof(newarray)/sizeof(int);j++){
	if (newarray[j] != '\0')
  		printf("new array : %d\n",newarray[j]);
  }

}     


int main()
{ 
   
  int arr[] = {4, 2, 4, 5, 2, 3, 1};
  int arr_size = sizeof(arr)/sizeof(arr[0]);  
  printRepeating(arr, arr_size);
  return 0;
}
