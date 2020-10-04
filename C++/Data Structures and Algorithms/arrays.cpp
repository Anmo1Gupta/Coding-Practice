#include<iostream>

using namespace std;

int main(){
    
    //Array Rotation
    int arr[] = {1,2,3,4,5,6};
    const int d = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int i =0;
    int temp[d];
    for(i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(i=0;i<n-d;i++){
        arr[i]=arr[i+d];
    }
    for(i=0;i<d;i++){
        arr[n-d+i]=temp[i];
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}