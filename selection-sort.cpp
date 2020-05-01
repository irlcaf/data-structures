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

int main(){
    cout << "Selection sort"<<endl;
    int size = 10;
    int array[size] = {64, 12, 22, 11, 12, 45, 54, 67, 13, 15};
    selectionSort(array, size);
    bubbleSort(array, size);
    return 0;
}