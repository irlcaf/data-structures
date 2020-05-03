#include <iostream>
using namespace std;

void selectionSort(int array[], int size){
    //Prints sorted array
    int indexsmallestNumber = 0;
    int temp = 0;
    for(int i = 0; i < size; i++){
        indexsmallestNumber = i;
        for(int j = i+1; j < size; j++){
            if(array[indexsmallestNumber] >= array[j]){
                indexsmallestNumber = j;
            }
        }
        temp = array[i];
        array[i] = array[indexsmallestNumber];
        array[indexsmallestNumber] = temp;
    }

    for(int i = 0; i < size; i++){
        cout << array[i] << "  ";
    }
}

void bubbleSort(int array[], int size){
    //Prints sorted array
    int temp = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            if(array[j] > array[j+1]){
                //Swap
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++){
        cout << array[i] << "  ";
    }
}

void merge(int array[], int from, int medium, int to){
    int i = 0, j = 0, k = from;
    int n1 = medium - from + 1;
    int n2 = to - medium;

    int L[n1], R[n2];

    for(i = 0; i < n1 ; i++){
        L[i] = array[from+i];
    }
    for(i = 0; i < n2 ; i++){
        R[i] = array[medium + 1 + i];
    }

    while(i < n1 && j < n2){
        if(L[i] <= R[i]){
            array[k] = L[i];
            i++;    
        }else{
            array[k] = R[i];
            j++;
        }
        k++;
    }
    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        array[k] = R[i];
        j++;
        k++;
    }
}

void mergeSort(int array[], int from, int to){
    if(from < to){
        int medium = from + (to - from)/2;

        mergeSort(array, from, medium);
        mergeSort(array, medium+1, to);

        merge(array, from, medium, to);
    }
}

int main(){
    cout << "Selection sort"<<endl;
    int size = 10;
    int array_bubble[size] = {64, 16, 22, 11, 12, 25, 14, 65, 14, 15};
    int array_merge[size] = {64, 12, 22, 11, 12, 45, 54, 67, 13, 15};
    selectionSort(array_bubble, size);
    cout << "Bubble sort" << endl; 
    bubbleSort(array_bubble, size);
    cout << "Merge sort" << endl;
    mergeSort(array_merge, 0, size - 1);
    for(int i = 0; i < size; i++){
        cout << array_merge [i] << "  ";
    }
    return 0;
}