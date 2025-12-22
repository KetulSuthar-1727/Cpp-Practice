#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

// For finding factorial using the recursive approch
int factorial(int n){

    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

// For finding the sum using the recursive approch
int sumOf(int n){

    if (n == 0)
    {
        return 0;
    }
    
    return n + sumOf(n - 1);
}

void printCounting(int n){

    if (n == 0)
    {
        return;
    }
    
    printCounting(n - 1);

    cout << n << " ";
}

// For finding the fibbonacci number using the recursion
int fibbonacci(int n){

    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;

    }
    return fibbonacci(n - 1) + fibbonacci(n - 2);
    
    
}

int books(int arr[],int n,int page){
    int curr = 0;
    int sum = 0;

    while (sum < page)
    {
        sum += arr[curr];
        curr++ % 7;
    }
    curr--;
    
    return (curr) % 7;

}

int lowerBound(vector<int> arr,int target){

    int low = 0;
    int high = arr.size();

    while(low < high){
        int mid = low + (high - low) / 2;

        if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid;
        }
        cout << low << " " << high << endl;
    }
    return low;
}

int floor(vector<int> arr,int target){

    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target)
        {
            ans = mid;
            low = mid + 1;
            
        }
        else{
            high = mid - 1;
        }

        
    }
    return ans;
}

int climbStairs(int n){

    if (n == 0  || n == 1)
    {
        return 1;
    }

    return climbStairs(n - 1) + climbStairs(n - 2);
    

}


int main() {
    
    int arr[7] = {2,3,4,5,6,7,8};

    int *ptrArr = arr;

    cout << ptrArr + 1 << endl;
    cout << &arr[1];
}
