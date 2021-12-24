//1, 0 in random order segregrate 0 on left 1 on right any only once traverse the array once

#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter size of array : ";
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array : \n";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int zerocount=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			int temp=arr[i];
			arr[i]=arr[zerocount];
			arr[zerocount]=temp;
			zerocount+=1;
		}
	}
	cout<<"Required array is : \n";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}