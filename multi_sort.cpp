#include <iostream>
#include <vector>
#include <time.h>
//#include <sstream>
// C++ program for implementation of Heap Sort 
#include <fstream>
#include <string>
using namespace std;
void heapify(vector <int> & arr,vector <string> & value, int i,int N){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left < N && arr[left] > arr[largest])
            largest = left;
        if(right < N && arr[right] > arr[largest])
            largest = right;
        if(largest != i){
            swap(arr[i], arr[largest]);
            swap(value[i], value[largest]);
            heapify(arr,value,largest,N);
        }
    }
void sortArray(vector<int>& nums, vector<string>& value) {
        for(int i = nums.size()/2; i >= 0; i--){
            heapify(nums,value,i,nums.size());
        }
        for(int i = nums.size()-1; i >= 0; i--){
            swap(nums[0] , nums[i]);
            swap(value[0] , value[i]);
            heapify(nums,value,0,i);
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

        
        scanf("%lf", &len);

        //int myAr[n];
        int i = 0;
        while (i < len) {
        scanf("%d %s",&x,&st);
        i++;
        key.push_back(x);
        value.push_back(st);
        };
        fclose(op);
        // ifstream inFile;
        // //int* arr;
        // inFile.open("input345.txt");
        // if (!inFile) {
        //     return 3;
        // }
        // if (inFile >> len) {
            
        //     //arr = new int[len];
        //     for (int i = 1; i <= len; ++i)
        //     {
        //         inFile >> x >> st;
        //         //StringOrInt row{x,st};
        //         //arr[i] = x;
        //         key.push_back(x);
        //         value.push_back(st);

        //     }
        // }
                printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

        sortArray(key, value);
                printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
        FILE * fp = freopen ("output345.txt","w",stdout);
        i = 0;
        printf("%lf\n", len);
        while (i < len) {
        printf("%d %s\n",key[i],value[i].c_str());
        i++;
        };
        fclose (fp);
        //int ret = writeFile(key, value, "output233.txt");
        printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

        return 0;
    
}