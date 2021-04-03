/* merge sort algo
    1- divide the array into half
    2- sort and merge them into temp array
    3- copy back to original   
*/

#include <iostream>

void merge(int arr[], int s, int e){
//small calculation
    int mid = (s+e)/2;
    // temp array to store sorted array
    int tempArr[e+1];
    // i for first half, j for 2nd half and k for temp array
    int i = s,k = s;
    int j = mid+1;

    // merging and sorting
    while(i <= mid && j <= e){
        // put the smaller number and incremnt that index only
        if(arr[i]<arr[j])
            tempArr[k++] = arr[i++];
        else
            tempArr[k++] = arr[j++];
    }

    //appending what values are left in array
    while(i <= mid){
        tempArr[k++] = arr[i++];
    }
    while (j <= e){
        tempArr[k++] = arr[j++];
    }

    //copying temp arr to original
    for(int x =s; x<=e; x++){
        arr[x] = tempArr[x];
    }
}

void mergeSort(int arr[],int s, int e){
    // base case- when array has 1 or no elements
    if(s>=e)
        return;
    int mid = (s+e)/2;
// recursive call
    mergeSort(arr,s,mid);
    mergeSort(arr, mid+1, e);
    //sorting and merging
    merge(arr,s,e);

}
int main(void){
    int arr[6] = {1,4,0,5,2,3};
    mergeSort(arr,0,5);

    for(int a:arr){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}