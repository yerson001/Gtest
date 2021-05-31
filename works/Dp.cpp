#include<iostream> 
using namespace std; 
  
int maxSubArraySum(int a[], int size) { 
   int ans = a[0]; 
   int ite = a[0]; 
  
   for (int i = 1; i < size; i++) { 
        ite = max(a[i], ite + a[i]); 
        ans = max(ans, ite); 
   } 
   return ans; 
} 
  
/* Driver program to test maxSubArraySum */
int main() { 
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3}; 
   int n = sizeof(a)/sizeof(a[0]); 
   int max_sum = maxSubArraySum(a, n); 
   cout << "Maximum contiguous sum is " << max_sum; 
   return 0; 
} 
