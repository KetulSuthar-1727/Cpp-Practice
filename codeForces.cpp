#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr){

    int maximum = 0;
    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        sum += arr[i];
    }

    int left = 0;
    int right = 3;

    while(right < arr.size()){

        if(sum % 3 == 0){
            maximum = max(sum, maximum);
        }

        sum -= arr[left];
        sum += arr[right];
        left ++;
        right ++;
    }

    return maximum;

}

int main() {
    #define fast_io ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fast_io;
    
    
    vector<int> arr = {8,7,4,3};

    int ans = solve(arr);

    cout << ans << endl;
    
    return 0;
}
