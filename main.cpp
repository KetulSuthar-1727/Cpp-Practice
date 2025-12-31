#include <bits.stdc++.h>
using namespace std;

// This function is for finding the first occurance of the digit in an sorted array using binary search
int firstOccurance(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size() - 1;

    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }

        else if (arr[mid] < target)
        {
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
        
        
    }

    return ans;
    
}

// This function is for finding the last occurance of the digit in an sorted array using binary search
int lastOccurance(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size() - 1;

    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }

        else if (arr[mid] < target)
        {
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
        
        
    }

    return ans;
    
}

// This function is used to find the missing number in the array containing 0 to n numbers
int findMissing(vector<int>& arr){

    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] - mid == 2)
        {
            high =  mid;
        }

        else if (arr[mid] - mid == 1)
        {
            low = mid + 1;
        }
    }

    return arr[high] - 1;
    
    
}

// This function is used to find the sqaure root of the number using the binary search
double squareRoot(int n){

    int low = 0;
    int high = n - 1;
    double ans = -1;

    while (low <= high){

        int mid = low +(high - low) / 2;

        int sqOfMid = mid * mid;

        if (sqOfMid == n) return mid;
        

        if (sqOfMid > n)
        {
            high = mid - 1;
        }
        
        else{
            ans = mid;
            low = mid + 1;
        }
    }
 
    double step = 0.1; 

    for (int i = 0 ;i < 3 ; i++){

        for (double j = ans ; j * j <= n ;j = j + step){

            ans = j;
        }
        step = step / 10;
    }

    return ans;
}

// This function finds the element in the 2d array using the binary search
pair<int ,int> binarySearch(vector<vector<int>>& matrix, int target) {

    int row = matrix.size();
    int col = matrix[0].size();

    int low = 0;
    int high = (row * col) - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int rowIndex = mid / col;
        int colIndex = mid % col;

        if (matrix[rowIndex][colIndex] == target) return {rowIndex, colIndex};

        else if (matrix[rowIndex][colIndex] < target)
        {
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
        
        
    }

    return {-1, -1};
    
}

// This is the book allocationproblem helper function
bool isAnsPossible(vector<int>arr,int s,int mid){
    int student = 1;
    int pageSum = 0;

    for (int i = 0 ; i < arr.size() ; i++){
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }

        else{
            student += 1;
            if (student > s)
            {
                return false;
            }
            else{
                pageSum = 0;
                pageSum += arr[i];
            }
        }

        
    }
    return true;
}

// This is the ekoSpoj helper funtion
long long woodSum(vector<int>arr,int mid){
        
        long long sumOfWood = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < mid)
            {
                continue;
            }
            else{
                sumOfWood += arr[i] - mid;
            }
            
        }
        return sumOfWood;
}

// This is the ekoSpoj main fucntion
int ekoSpoj(vector<int>arr,int m){

    int low = 0;
    int high = *max_element(arr.begin() , arr.end());
    int ans = 0;

    while(low <= high){
        long long mid = low + (high - low) / 2;
        long long possibleAns = woodSum(arr,mid);
        if (possibleAns >= m)
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

// This function is used to find the length of the given array
int getLength(char name[]){

    int length = 0;
    int i = 0;

    while (name[i] != '\0')
    {
        length += 1;
        i += 1;
    }

    return length;   
}

// This function reverse the array of the char using two pointer
int reverse(char name[]){

    int i = 0;
    int n = getLength(name);
    int j = n - 1;

    while (i <= j)
    {
        swap(name[i],name[j]);
        i ++;
        j --;
    }

    for (int i = 0; i <= j; i++)
    {
        swap(name[i],name[j]);
        j--;
    }
    

    return 0;  

}

// This function check if the array is palindrome or not
bool palindrome(string name){

    int i = 0;
    int n = name.length();
    int j = n - 1;

    while (i <= j)
    {
        if (name[i] != name[j])
        {
            return false;
            
        } 
        i++;
        j--; 
    }
    return true;
    
}

// This function converts the char array to the uppercase
int convertUpper(char name[]){

    int n = getLength(name);

    for (int i = 0; i < n; i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            name[i] = name[i] - 'a' + 'A';
        }
        
            
    }
    return 0;
}

// This function converts the char array to the lowercase
int convertLower(char name[]){

    int n = getLength(name);

    for (int i = 0; i < n; i++)
    {
        if (name[i] != ' ')
        {
            name[i] = name[i] - 'A' + 'a';
        }
        
        
    }
    
    return 0;
}

// This function compares the both string by one by one char
bool compareString(string a ,string b){

    if (a.length() != b.length())
    {
        return false;
    }
    else{

        int i = 0;
        int j = 0;

        while (i <= a.length())
        {
            if (a[i] != b[j])
            {
                return false;
            }
            
            i++;
            j++;
        }
        
    }
    return true;
}   

// This function removes the same neighbour char in a string
string removeAdjucent(string s){

    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (ans.length() == 0)
        {
            ans.push_back(s[i]);
        }
        else if (ans[ans.length() - 1] == s[i])
        {
            ans.pop_back();
        }
        else{
            ans.push_back(s[i]);
        }
        
    }
    return ans;
    
}

// This function removes the given part from the existing string
string removeOccurrences(string s , string part){

    int indexOfPart = s.find(part);
    int removeChrLength = part.length();

    while (indexOfPart != string::npos)
    {
        s.erase(indexOfPart , removeChrLength);
        indexOfPart = s.find(part);
    }
    
    return s;
}

// This function check if stirng is palindrome or not its helper function of the below fucntion
bool checkPalindrome(string name , int i ,int j){

    while (i <= j)
    {
        if (name[i] != name[j])
        {
            return false;
            
        } 
        i++;
        j--; 
    }
    return true;
    
}

// This function check the string is palindrome or not after removing one chr from the string
bool validPalindrome2(string s){

    int i = 0 ;
    int j = s.length() - 1;
    

    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        
        else{
            return checkPalindrome(s,i + 1,j) || checkPalindrome(s,i,j - 1);
        }
    }
    return true;
}

// This is the leetcode problem fidning the minimum time diffrence 
int minimumTimeDiffrence(vector<string>& timePoints){
    vector<int> minutes;
    int ans = INT_MAX;

    for (int i = 0 ; i < timePoints.size(); i++){

        string curr = timePoints[i];
        int hours = stoi(curr.substr(0,2));
        int minute = stoi(curr.substr(3,2));

        int totalMinutes = hours*60 + minute;

        minutes.push_back(totalMinutes);

    }

    sort(minutes.begin() , minutes.end());

    for (int i = 0; i < minutes.size() - 1; i++)
    {
        int diff =  minutes[i] - minutes[i + 1];

        ans = min(ans,diff);
    }

    int temp = 1440 - minutes[minutes.size() - 1] + minutes[0];
    
    ans = min(ans,temp);


    return ans;

}

// This is the helper fucntion of the below function
int checkingAllIndex(string s ,int i ,int j){
    int count = 0;

    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count ++;
        i --;
        j ++;
    }
    return count;
    
}

// This function counts the possible palindrome substrings from the original string
int countSubString(string s){
    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        // For odd cases
        int oddAns = checkingAllIndex(s, i ,i);
        count += oddAns;

        // For Even cases
        int evenAns = checkingAllIndex(s,i,i+1);
        count += evenAns;
    }
    return count;
    
}

int wavePrintMatrix(vector<vector<int>>& matrix){


    vector<int>ans;
    int rowLength = matrix.size();
    int colLength = matrix[0].size();

    for (int col = 0; col < colLength; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < rowLength; row++)
            {
                ans.push_back(matrix[row][col]);
            }
            
        }
        else{
            for (int row = rowLength - 1; row >= 0; row--)
            {
                ans.push_back(matrix[row][col]);
            }
            
        }
        
    }
    for (auto val : ans){
        cout << val << " ";
    }
    return 0;
    
}

string reverseOnlyLetters(string s){

    int i = 0;
    int j = s.length() - 1;

    while(i <= j){
        if (! isalpha(s[i]))
        {
            i ++;
        }
        else if (! isalpha(s[j])){
            j --;
        }        
        else{
            swap(s[i],s[j]);
            i ++;
            j --;
        }
    }
    return s;


}

string longestCommomPrefix(vector<string>str){

    string ans = "";
    int ch = 0;
    while (ch <= str[0].length() - 1)
    {
        
        char current_ch = str[0][ch];

        for (int i = 0 ; i < str.size() - 1 ; i++){
            if (!(current_ch == str[i][ch]))
            {
                return ans;
            }
            
        }
        ans.push_back(current_ch);
        ch += 1;

    }
    return ans;
}

// // vector<vector<string>> groupAnagrams(vector<string>& strs){

//     map<string,vector<string>> hashmap;
//     vector <vector<string>> ans;
//     for(auto value:strs){

//         string temp = value;
//         string tempfinal = sort(temp.begin(),temp.end());

//         hashmap[tempfinal].push_back(value);

//     }

//     for (auto it = hashmap.begin() ; it != hashmap.end() ; it++){
//         ans.push_back(it -> second);
//     }

//     return ans;
    
// }

int findTheIndexOfTheFirstOccurance(string haystack , string needle){

    if (needle.length() > haystack.length()) return -1;
    
    for (int i = 0 ; i < haystack.length() - needle.length() + 1 ; i++){

        if (haystack.substr(i , needle.length()) == needle)
        {
            return i;
        }
        
    }
    return -1;
    
}



//  this is problem no 415 in leetcode sum of given two string 

void addRE(string& num1, string& num2, int p1, int p2, int carry, string& ans){

    // base case
    if(p1 < 0 && p2 < 0){
        if(carry != 0){
            ans.push_back(carry + '0');
        }
        return;
    }

    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

    int sum = n1 + n2 + carry;
    int digit = sum % 10;
    carry = sum / 10;
    ans.push_back(digit + '0');


    addRE(num1, num2, p1 - 1, p2 - 1, carry, ans);
    
}

int main() {
    
    string num1 = "455";
    string num2 = "76";

    int p1 = num1.length() - 1;
    int p2 = num2.length() - 1;

    int carry = 0;
    string ans = "";

    addRE(num1, num2, p1, p2, carry, ans);

    reverse(ans.begin(),ans.end());

    cout << ans << endl;

    return 0;
}


//  this is the problem no 198 named house robber problem in which we use include exclude pattern

void solve(vector<int> arr, int ans, int i, int& maximum){

    // base case
    if(i >= arr.size()){
        maximum = max(ans,maximum);
        return;
    }

    // include
    solve(arr, ans + arr[i], i + 2, maximum); 
    
    // exclude
    solve(arr, ans, i + 1, maximum); 
    
}

int main() {
    
    vector<int> arr = {1,2,3,4,5,6};
    int ans = 0;
    int i = 0;
    int maximum = INT_MIN;

    solve(arr, ans, i, maximum);

    cout << maximum << endl;

    return 0;
}
//  another way to solve the same house robber problem same approch but different ways

int solve(vector<int>nums, int i){

    //  base case
    if(i >= nums.size()){
        return 0;

    }
    // include
    int include = nums[i] + solve(nums, i + 2);

    // exclude
    int exclude = 0 + solve(nums, i + 1);

    return  max(include, exclude);
}


int main() {
    
    vector<int> arr = {1,2,3,4,5,6};

    int i = 0;

    int finalAns = solve(arr, i);

    cout << finalAns << endl;

    return 0;
}


// this is the problem number 44 named wildcard matching in which we use include-exclude pattern wither we include the * as a character or we use * as a null character

bool solve(string s, string p, int i, int j){

    // base case
    if(i == s.size() && j == p.size()){
        return true;
    }

    if(i == s.size() && j < p.size()){
        while (j < p.size())
        {
            if(p[j] != '*'){
                return false;        
            }
            j ++;
        }
        return true;
        
    }

    // solving case
    if(s[i] == p[j] || p[j] == '?'){
        return solve(s, p, i + 1, j + 1);
    }

    else if(p[j] == '*'){
        // treating the '*' as a null character
        bool caseA = solve(s, p, i, j + 1);

        // treating the '*' as a character
        bool caseB = solve(s, p, i + 1, j);

        return caseA || caseB;
    }

    return false;

}

int main() {
    
    string s = "ab";
    string p = "??*efg";
    int i = 0;
    int j = 0;
    bool finalAns = solve(s, p, i, j);

    cout << finalAns << endl;

    return 0;
}


// find the minimum number of perfectSquares sum to acheive n

int solve(int n){
    int finalAns = INT_MAX;
    // base case
    if(n <= 0){
        return 0;
    }

    // solving one case
    int i = 1;
    int end = sqrt(n);
    while(i <= end){
        int perfectSquare = i * i;
        int ans = 1 + solve(n - perfectSquare);

        finalAns = min(ans,finalAns);

        i++;
    }
    
    return finalAns;
}

int main() {

    int n = 13;

    int ans = solve(n);

    cout << ans << endl;

    return 0;
}


// * This is the Merge sort program *//

// this function creates the two different arrays first for copying the values because we just divides the array in dividing fucntion not creating them seperate so we have to create a seperate arrays for both the part and then we can do the merrging

// so first we have created the two empty arrays then we copied all the values of the first half in one array and the second half in the second array

// after that we have applied the merge two sorted array logic and merged the arrays 

void merge(vector<int>& arr, int s, int e){

    int mid = s + (e - s) / 2;

    int leftsize = mid - s + 1;
    int rightsize = e - mid;

    int* leftArr = new int[leftsize];
    int* rightArr = new int[rightsize];

    int k = s;

    for (int i = 0; i < leftsize; i++){
        leftArr[i] = arr[k];
        k ++;
    }
    
    int m = mid + 1;

    for (int i = 0; i < rightsize; i++){
        rightArr[i] = arr[m];
        m ++;
    }
    
    int i = 0;
    int j = 0;
    int mainIndex = s;

    while(i < leftsize && j < rightsize){

        if(leftArr[i] < rightArr[j]){
            arr[mainIndex] = leftArr[i];
            mainIndex ++;
            i ++;
        }
        else{
            arr[mainIndex] = rightArr[j];
            mainIndex ++;
            j ++;
        }
    }

    if(i < leftsize){
        while (i < leftsize){
            arr[mainIndex] =  leftArr[i];
            mainIndex ++;
            i ++;
        }
    }

    else{
        while(j < rightsize){
            arr[mainIndex] =  rightArr[j];
            mainIndex ++;
            j ++;
        }
    }
}

// this fucntion divides the two arrays and then send it to the other function for the mergin in the sorted manner
void mergeSort(vector<int>& arr, int start, int end){

    // base case
    if(start >= end){
        return;
    }

    int mid = start + (end - start) / 2;

    // sorting left part
    mergeSort(arr, start, mid);

    // sorting right part
    mergeSort(arr, mid + 1, end);

    // merging the arrays
    merge(arr, start, end);
}


int main() {
    
    vector<int> arr = {7,3,2,16,24,4,11,9};
    int start = 0;
    int end = arr.size() - 1;

    mergeSort(arr, start, end);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

//*  This it the qucikSort using the recursion approch taking NlogN time  *//

// this is the partitioning fucntion in which we set the pivot element at the right place and then we check all the elements and all the elements less then pivot we keep it on the left side and others on the right side

// we check all the elements frommt the next element to the end and then we check if there is any left greater element on the left side checking everythiing and if swap if elements are on the opposite side

// and then wee return the pivot index to the quickSort function
int partition(vector<int>& arr, int start, int end){

    int pivot = start;
    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if(arr[i] <= arr[pivot]){
            count ++;
        }
    }

    swap(arr[pivot], arr[start + count]);

    pivot = start + count;
    int i = start;
    int j = end;

    while (i < pivot && j > pivot)
    {
        while(i < pivot && arr[i] <= arr[pivot]){
            i++;
        }

        while(j > pivot && arr[j] > arr[pivot])
        {
            j--;
        }

        if(i < pivot && j > pivot){
            swap(arr[i], arr[j]);
        }
    }

    return pivot;

}

// this is the main qucikSort fucntiion which take pivot from the helper function and then againi do a recursive call for the leffhalf and the right half

void quickSort(vector<int>& arr, int start, int end){

    if(start >= end){
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);

}

int main() {
    
    vector<int> arr = {4,5,6,7,8,3,2,12,23,21,23,12,65};

    int start = 0;
    int end = arr.size() - 1;

    quickSort(arr, start, end);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// this is the backtracking question finding all the permutations of the string 

void permutations(string& s, int i){

    if(i >= s.size()){
        cout << s << endl;
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        // swapping the characters
        swap(s[j], s[i]);
        
        // recursive function call
        permutations(s, i + 1);
        
        // backtracking call why ? -> because we have used the string as a reference so it changes the original string and we need the same string for the next call after reaching the one depth so be again swap to make it original
        swap(s[j], s[i]);
    }
    
    
    
}

int main() {
    
    string str = "abc";
    int i = 0;
    
    permutations(str, i);

    return 0;
}

// * This is the backtracking famous question rat in the maze using recursion and the backtracking for inding the all possible solution *//

// this is the function for checking if the loaction we are trying to check is in the matrix or not
// this function returns the boolean value if it possible
bool isSafe(int arr[4][4], int rows, int cols, int i, int j, vector<vector<bool>>& visited){

    if(((i < rows && i >= 0) && (j < cols && j >= 0)) && (visited[i][j] == false) && (arr[i][j] == 1)){
        return true;
    }
    else{
        return false;
    }
}

// by using this function we check each and every direction of the loaction and check if it is safe location or possible locatiion or not and if true then we we mark that location as a true and call the function again and then again mark that location as the false
void solve(int arr[4][4], int rows, int cols, vector<vector<bool>>& visited, vector<string>& allAns,string ans, int i, int j){

    if(i >= rows- 1 && j >= cols - 1){
        allAns.push_back(ans);
        return ;
    }

    // down
    if(isSafe(arr, rows, cols, i + 1, j, visited)){

        visited[i + 1][j] = true;
        solve(arr, rows, cols, visited, allAns, ans + 'D', i + 1, j);

        // backtracking
        visited[i + 1][j] = false;
    }

    // left
    if(isSafe(arr, rows, cols, i, j - 1, visited)){

        visited[i][j - 1] = true;
        solve(arr, rows, cols, visited, allAns, ans + 'L', i, j - 1);

        // backtracking
        visited[i][j - 1] = false;
    }

    // right
    if(isSafe(arr, rows, cols, i, j + 1, visited)){

        visited[i][j + 1] = true;
        solve(arr, rows, cols, visited, allAns, ans + 'R', i, j + 1);

        // backtracking
        visited[i][j + 1] = false;
    }

    // up
    if(isSafe(arr, rows, cols, i - 1, j, visited)){

        visited[i - 1][j] = true;
        solve(arr, rows, cols, visited, allAns, ans + 'U', i - 1, j);

        // backtracking
        visited[i - 1][j] = false;
    }

}

int main() {

    int arr [4][4] = {{1,0,1,0}, {1,1,1,1}, {0,1,1,0}, {0,1,1,1}};

    int rows = 4;
    int cols = 4;
    vector<vector<bool>> visited(rows, vector<bool>(cols,false));

    visited[0][0] = true;

    vector<string> allAns;
    string ans = "";

    solve(arr, rows, cols, visited, allAns, ans, 0, 0);

    for(auto it : allAns){
        cout << it << " "; 
    }
    cout << endl;
    return 0;
}


// this is the n-queens problem using backtracking

void printSolution(vector<vector<char>>& board, int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

bool isSafe(int row, int col, vector<vector<char>>& board, int n){

    int i = row;
    int j = col;

    // check left row
    while (j >= 0)
    {
        if(board[i][j] == 'Q'){
            return false;
        }
        j --;
    }

    i = row;
    j = col;
    // check upper left diagonal
    while(i >= 0 && j >= 0){

        if(board[i][j] == 'Q'){
            return false;
        }
        i --;
        j --;
    }
    i = row;
    j = col;
    // check bottom left diagnal
    while (i < n && j >= 0)
    {
        if(board[i][j] == 'Q'){
            return false;
        }
        i ++;
        j --;
    }

    return true;
}

void solve(vector<vector<char>>& board, int col, int n){

    // base case
    if(col >= n){
        printSolution(board, n);
        return;
    }

    // solving one case
    for (int row = 0; row < n; row++)
    {
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(board, col + 1, n);
            board[row][col] = '-';
        }
    } 
}


int main() {
    
    int n = 8;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    
    solve(board, col, n);

    return 0;
}

// this is the generate parentheses problem using backtracking

void solve(int open, int close, int n, string ans, vector<string>& finalAns){

    // base case
    if(open == 0 && close == 0){
        finalAns.push_back(ans);
        return;
    }

    // include open bracket
    if(open > 0){
        ans.push_back('(');
        solve(open - 1, close, n, ans, finalAns);
        ans.pop_back();
    }

    // include close bracket
    if(close > open){
        ans.push_back(')');
        solve(open, close - 1, n, ans, finalAns);
        ans.pop_back();
    }

}

int main() {

    int n = 3;
    int open = 3;
    int close = 3;
    string ans = "";
    vector<string> finalAns;

    solve(open, close, n, ans, finalAns);

    for(auto it : finalAns){
        cout << it << " " ;
    }

    return 0;
}

// this is the letter combination of a phone number problem in the leetcode problem number 17

void solve(string digits, vector<string>& ans, string output, int index, vector<string>& hp){

    if(index >= digits.size()){
        ans.push_back(output);
        return;
    }

    int digit = digits[index] + '0' // in this line we convert the first element of the given input into the integer so we can access it using the index in hp

    string value = hp[digit];  // in this we store the value of the coresponding number like 2 : "abc" in the string value 

    // then we will apply the loop for each value in the string and check all the possible combinations

    for(int i = 0; i < value.size(); i++){
        char ch = value[i];
        
        solve(digits, ans, output + ch, index + 1, hp);
        
    }



}

int main(){

    string digits = "234";
    vector<string> ans;
    string output = "";
    int index = 0;

    vector<string> hp(10);
    hp[2] = "abc";
    hp[3] = "def";
    hp[4] = "ghi";
    hp[5] = "jkl";
    hp[6] = "mno";
    hp[7] = "pqrs";
    hp[8] = "tuv";
    hp[9] = "wxyz";

    solve(digits, ans, output, index, hp);

    for(auto it : ans){
        cout << it << endl;
    }
}

// This is the combination sum problem of the leetcode

void combinationSum(vector<int>& arr, vector<int>& ans, vector<vector<int>>& finalAns, int index, int target){

    // if the target is below zero means we have to pop back the number
    if(target < 0){
        return;
    }

    // if the sum is eqaul to target then we add ans to the list
    if(target == 0){
        finalAns.push_back(ans);
        return;
    }

    // we apply the loop for the all the element in the array
    for (int i = index; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
        combinationSum(arr, ans, finalAns, index, target - arr[i]);
        ans.pop_back();
    }
    

}

int main() {
    
    vector<int> arr = {2,3,6,7};
    vector<int> ans;
    vector<vector<int>> finalAns;
    int i = 0;
    int target = 7;
    combinationSum(arr, ans, finalAns, i, target);

}

// This is the combinationSum 2 problem of the leetcode same as the combination sum but the only difference is the we dont have to use same digit again and no duplicate ans are allowed


void combinationSum(vector<int>& arr, vector<int>& ans, vector<vector<int>>& finalAns, int index, int target){

    if(target < 0){
        return;
    }
    if(target == 0){
        finalAns.push_back(ans);
    }

    for (int i = index; i < arr.size(); i++)
    {
        // This is the checking condition in which we check that if the element is same as the previous element so it make the same pair as the above thats why we will chcek if the next element is same then we continue with not inclulding it
        if(i > index && arr[i] == arr[i - 1]){
            continue;
        }
        ans.push_back(arr[i]);
        combinationSum(arr, ans, finalAns, index + 1, target - arr[i]); 
        // we have increased the index by 1 in this because we can not include the same digit again
        ans.pop_back();
    }
    

}

int main() {
    
    vector<int> arr = {10,1,2,7,6,1,5};
    int index = 0;
    vector<int> ans;
    vector<vector<int>> finalAns;
    int target = 8;

    sort(arr.begin() , arr.end());

    combinationSum(arr, ans, finalAns, index, target);

    return 0;
}