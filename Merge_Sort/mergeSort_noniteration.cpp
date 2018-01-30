#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;


void Merge(int arr[], int tmp[], int left, int mid, int right)
{
	 	int i = left;
	 	int j = mid+1;
	 	int idt = left;
	 
	 	while(i <= mid && j <= right)  // 合并两个序列 按升序
	 	{
	 		if (arr[i] <= arr[j])
	 		{
	 			tmp[idt++] = arr[i++];
	 		}
	 		else
	 		{
	 			tmp[idt++] = arr[j++];
	 		}
	 	}
	 
	 	while(i <= mid)	// 合并剩余序列
	 	{
	 		tmp[idt++] = arr[i++];
	 	}
	 
	 	while(j <= right)// 合并剩余序列
	 	{
	 		tmp[idt++] = arr[j++];
		}
}

void MergePass(int arr[], int tmp[], int step, int n)
{
	int i = 0;
	while (n - i >= 2 * step)
	{   // 将两两相邻的有序子序列合并成一个2倍长度的子序列
		Merge(arr, tmp, i, i+step-1, i+2*step-1);
		i = i + 2 * step;
	}

	// 若剩余序列超过一个序列长度将再次合并不足两个序列长度的两个序列
	if (n - i > step)	
		Merge(arr, tmp, i, i+step-1, n-1);
	else   // 将剩下来的不大于一个序列长度的剩余元素并入
		for (int j = i; j < n; j++)
			tmp[j] = arr[j];
	
}

void MergeSort(int arr[], int n)
{
	int step = 1;
	int* tmp = new int[n];	// 申请额外的辅助空间
	
	while(step < n)
	{	
		// 将arr的元素按照step归并到tmp
		MergePass(arr, tmp, step, n);
		step *= 2;
		// 将tmp的元素按照新step归并到arr
		MergePass(tmp, arr, step, n);
		step *= 2;	
	}

	delete[] tmp;
}


int main()
{
	int i=0,temp=0;
	int a[10]={0};
	for(i=0;i<10;i++)
	{
		a[i]=rand()% 20;
		cout<<a[i]<<" ";
	}
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

	MergeSort(a,10`

	for(i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}