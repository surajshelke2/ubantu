#include<iostream>
#include<vector>
using namespace std;





int partition(vector<int>& arr ,int s , int n){

    int pivot = arr[s];

   int cnt =0;
   for(int i=s+1;i<=n ;i++){

    if(arr[i]<=pivot){
        cnt++;
    }
   }

   int pivotIndex=cnt+s;
   swap(arr[s],arr[pivotIndex]);


    int i=s;
    int j=n;

    while(i<pivotIndex && j>pivotIndex){

        while(arr[i]<=pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){

            swap(arr[i++],arr[j++]);
        }
    }
   return pivotIndex;
}


void quickSort(vector<int>& arr ,int s, int n)
{

    if(s<n){
    int p =partition(arr,s,n);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,n);
    }
}
int main()
{

    vector<int> arr ={5,8,9,2,4,5,6};
     int n = arr.size() - 1;
    quickSort(arr,0,n);

    cout<<"Sorted Array :"<<endl;

   
   for(int i=0;i<n ;i++){

    cout<<arr[i]<<" ";
   }

}