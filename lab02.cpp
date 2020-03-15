#include <iostream> 
#define MAX_INT 2000000
using namespace std; 


void Merge(int * A, int p, int q, int r){ //p = begin; q= middle; r = end; 
    int n1 = q-p +1; //length of subarray A[p..q]
    int n2 = r - q;//length of subarray ofA[q+1..r]
    int Left[n1 +1];//extra space for sentinal
    int Right[n2 +1];

    for(int i = 1; i < n1; i++){
        Left[i]=A[p+i-1];//copies subarray A[p..q] into L[1...n1]
    } 
    for(int j = 1; j< n2; j++){
        Right[j]= A[q +j]; //copies subarray A[q+1..r]into R[1..n2]
    }
    //place sentinals at the end of array 
    Left[n1+1] = MAX_INT;
    Right[n2+1] = MAX_INT;
    int i =0;
    int j =0; 
    
    for(int k = p; k <= r; k++){//looop invariant ;perform the r-p+1 basic reps to maintain the following loop invariant
        if (Left[i] <= Right[j]){
            A[k]=Left[i];
            i = i +1;
        }
        else{
            A[k] =Right[j];
            j =j+1;
        }
    }
}
void MergeSort(int * A, int p, int r){//will merge sort the array 
    if(p < r){
        int q = (p+q)/2;
        MergeSort(A, p, q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

int main(int argc, char **argv){
    int length;
    cin>>length;
    int* A = new int[length];

    for(int i = 0; i<length; i++){//makes the new array 
        cin>> A[i];
    }
    MergeSort(A, 0, length-1);

    for(int b = 0; b< length; b++){//prints the new array 
        cout <<A[b]<< ";";
    }
}