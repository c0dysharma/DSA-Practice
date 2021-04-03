/*Quick sort
    place first element to its right postition by knowing how many elements are smaller or greater
    then arrange all smaller element to left and greater to the right by swapping
    recursive call on both parts(left and right)
*/
#include <iostream>

void swapVal(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partitionArr(int arr[], int s, int e)
{
    /*Method 1: CN*/

    // // Placing first element in correct place
    // int pivot = arr[s];
    // int size = (e-s)+1;
    // int smallerCount = 0;

    // for(int i=s; i<e; i++){
    //     if(pivot >= arr[i+1])
    //         smallerCount++;
    // }
    // int index = s+smallerCount;
    // swapVal(arr[s],arr[index]);

    // // arranging array such that <x--|x|---x>
    // int i = s;
    // int j = e;
    // while(i!=j){
    //     if(arr[i] <= pivot)
    //         i++;
    //     else if(arr[j] > pivot)
    //         j--;
    //     else
    //         swapVal(arr[i++], arr[j--]);
    // }

    // return index;

    /*Method 2: RBR*/
    // https://www.youtube.com/embed/3DV8GO9g7B4?v=848
    int pivot = arr[e];
    int i = s - 1;

    for (int j = s; j <= e - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            swapVal(arr[++i], arr[j]);
        }
        // else{
        //     j++;
        // }
    }
    swapVal(arr[++i], arr[e]);
    return i;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partioning
    int point = partitionArr(arr, s, e);
    //recursive call
    quickSort(arr, s, point - 1);
    quickSort(arr, point + 1, e);
    //smaller calculation
}

int main(void)
{

    int arr[6] = {7, 9, -1, 1, -8, -10};
    quickSort(arr, 0, 5);

    for (auto i : arr)
    {
        std::cout << i << std::endl;
    }
    return 0;
}