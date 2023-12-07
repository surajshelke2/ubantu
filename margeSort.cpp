#include<iostream>
#include<vector>
using namespace std;



void merge (vector<int>& arr , int s , int m , int e){

    
   int i=s;
   int j=m;

   int temp[e-s];


    int k=0;

    while(i<m && j<e){

        if(arr[i]<arr[j]){

            temp[k++]=arr[i++];
        }else{

            temp[k++]=arr[j++];
        }
    }

    while(i<m){
        temp[k++]=arr[i++];
    }

    while(j<e){
        temp[k++]=arr[j++];
    }


     for (int i = s, k = 0; i < e; i++, k++) {
        arr[i] = temp[k];
    }



}

void mergeSort (vector<int>&arr, int start , int end ){


    if(start<end-1){
    int mid = (start+end)/2;

    mergeSort(arr,start,mid);

    mergeSort(arr,mid,end);

    merge(arr,start ,mid,end);


    }   

}


int main(){


    vector<int> arr={1,2,5,62,4,5,22,3,5,8};

    mergeSort(arr,0,arr.size());

    for(auto i : arr){

        cout<<i<<" ";
    }
}