#include <iostream>
#include <vector>
#include <time.h>
//#include <sstream>
// C++ program for implementation of Heap Sort 
#include <fstream>
#include <string>
using namespace std;

// typedef struct {
//     int key;
//     string value;
// } StringOrInt;
// void swapARR(StringOrInt *x, StringOrInt *y) {
//     StringOrInt tmp = *x;
//     *x = *y;
//     *y = tmp;
// };
//
//
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 

void swap( int* x, int* y ) 
{
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void heapify(std::vector<int> &arr,std::vector<string> &value, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest])
        largest = l;


    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        swap(value[i], value[largest]);
        //swapARR(&matrix->at(i), &matrix->at(largest));
        // Recursively heapify the affected sub-tree 
        heapify(arr, value, n, largest);
    }
}

// main function to do heap sort 
void heapSort(std::vector<int> &arr,std::vector<string> &value, int n)
{
    // Build heap (rearrange array) 
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr,value, n, i);

    // One by one extract an element from heap 
    for (int i = n-1; i >= 0; i--) {
        // Move current root to end 
        swap(arr[0], arr[i]);
        swap(value[0], value[i]);
        //swapARR(&matrix->at(0), &matrix->at(i));
        // call max heapify on the reduced heap 
        heapify(arr, value, i, 0);
    }
}
int writeFile(std::vector<int> &key,std::vector<string> &value,  string path) {
    ofstream myfile(path);
    if (myfile.is_open()) {
        myfile << key.size() << "\n";
        for (int j = 0; j < key.size(); j++) {
            myfile << key[j]<< " "<< value[j]<< "\n";
        }
        return 0;
    }
    else {
        return -1;
    }
}
int main(int argc, char* argv[])
{
        clock_t tStart = clock();
        //std::vector<StringOrInt> matrix;
        std::vector<int> key;
        std::vector<string> value;
        double len;
        int x;string st;
        ifstream inFile;
        //int* arr;
        inFile.open("input345.txt");
        if (!inFile) {
            return 3;
        }
        if (inFile >> len) {
            
            //arr = new int[len];
            for (int i = 1; i <= len; ++i)
            {
                inFile >> x >> st;
                //StringOrInt row{x,st};
                //arr[i] = x;
                key.push_back(x);
                value.push_back(st);

            }
        }
        printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
        heapSort(key, value, len);
        printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

        int ret = writeFile(key, value, "output233.txt");
        printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

        return ret;
    
}