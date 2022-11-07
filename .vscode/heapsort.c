#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* function to heapify a subtree. Here 'i' is the   
index of root node in array a[], and 'n' is the size of heap. */   
void heapify(int a[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  
/*Function to implement the heap sort*/  
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        /* Move current root element to end*/  
        // swap a[0] with a[i]  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  
/* function to print the array elements */  
void printArr(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }  
          
}  
int main()  
{  
    // using clock_t to store time
    clock_t start, end;
    start = clock();
    
    int h=15;
    int it = 0;
    double tim1[10];
    int a[h];
    
    //int a[] = {7,6,5,4,3,2,1};  
    for (int i = 0; i < h; i++) 
        {
            long int no = rand() % h + 1;
            a[i] = no;
        }
    int n = sizeof(a) / sizeof(a[0]);  
    
    printf("Before sorting array elements are - \n");  
    printArr(a, n); 

    heapSort(a, n);  

    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    end = clock();
    tim1[it] = ((double)(end - start));
    printf("\n Time taken is : %li\n",(long int)tim1[it]);
    return 0;  
} 