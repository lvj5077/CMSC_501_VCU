#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}

void mergeSort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(a, first, mid, temp);    		//左边有序
		mergeSort(a, mid + 1, last, temp); 		//右边有序
		mergearray(a, first, mid, last, temp); 	//再将二个有序数列合并
	}
}


bool MergeSorted(int a[], int length){

	int *temp = new int[length];
	if(temp == NULL){
		return false;
	}

	mergeSort (a, 0, length-1, temp);
	return true;
}

int main(){
	int a[10]={0};
	for (int i=0;i<10;i++){
		a[i] = rand()%20;
	}

	int length = sizeof(a)/sizeof(*a);

	for (int i=0;i<length;i++){
		cout << a[i] <<" ";
	}

	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

	bool gotResult = MergeSorted(a,length);
	if (gotResult){
		for (int i=0;i<length;i++){
			cout << a[i] <<" ";
		}
	}

	return 0;
}