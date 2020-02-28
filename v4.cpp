#include <iostream>
#include <time.h>
#include <stdio.h>
#define CHAR_LENGTH 50

//#include <sstream>
// C++ program for implementation of Heap Sort 
#include <string>
#pragma warning(disable: 4996)
using namespace std;
struct dict_t {
    int key;
    char value[CHAR_LENGTH];
};

void heapify(dict_t* dict, int i, int N) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && dict[left].key > dict[largest].key)
        largest = left;
    if (right < N && dict[right].key > dict[largest].key)
        largest = right;
    if (largest != i) {
        swap(dict[i], dict[largest]);
        heapify(dict, largest, N);
    }
}
void sortArray(dict_t* dict, double len) {
    for (int i = len / 2; i >= 0; i--) {
        heapify(dict, i, len);
    }
    for (int i = len - 1; i >= 0; i--) {
        swap(dict[0], dict[i]);
       
        heapify(dict, 0, i);
    }
}
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        clock_t tStart = clock();
        long len;
        FILE* op = freopen("input345.txt", "r", stdin);  // <-----
        if (op == NULL) {
            
            return 2;
        }
        scanf("%li", &len);
        dict_t* inp_Dict = (dict_t*)malloc(len*sizeof(dict_t));
        //string* value = (string*)malloc(len * sizeof(string));
        int i = 0;
        while (i< len) {
            scanf("%d", &inp_Dict[i].key);
            fgets(inp_Dict[i].value, CHAR_LENGTH, op);
            i++;
        };
        fclose(op);
        printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

        sortArray(inp_Dict, len);
        
        printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
        FILE* fp = freopen("ouput23.txt", "w", stdout);
        if (fp == NULL) {
            return 3;
        }
        i = 0;
        printf("%li\n", len);
        while (i<len) {
            fprintf(fp, "%d", (inp_Dict+i)->key);
            fputs((inp_Dict+i)->value, fp);
            //printf("%d %s",(inp_Dict+i)->key, (inp_Dict+i)->value);
            i++;
        };        
                
        fflush(fp);fflush(stdout);
        cout<<"Time taken: %.8fs\n"<< (double)(clock() - tStart) / CLOCKS_PER_SEC<<endl;
        fclose(fp);
        return 0;
}