#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> array) {
    for(auto i : array) {
        cout << i << endl;
    }
}

void quickSort(vector<int> &array, int low, int high) {
    int i = low;
    int j = high;
    int pivot = array[(i+j)/2];
    int temp;

    while (i <= j) {
        while (array[i]<pivot) i++;
        while (array[j]>pivot) j--;
        if (i<=j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low) quickSort(array, low, j);
    if (i < high) quickSort(array, i, high);
} 

int main(){
    vector<int> array ={95, 45, 48, 98, 1, 485, 65, 478, 1, 2325};
    printVector(array);
    int n = array.size();
    quickSort(array, 0, n);
    printVector(array);
    return 0;
}