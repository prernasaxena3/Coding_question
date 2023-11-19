/*QUESTION 1: Given a sorted list with an unsorted number c in the rightmost cell, can you write some simple code to insert e into the array so that it remains sorted? */
//SOLUTION
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;
#define INT_MIN -1000000
void output(const vector<int>& a){
    cout << a[1];
    for(int j = 2; j < a.size(); ++j){
        cout << " " << a[j];
    }
    cout << endl;
}
void insertionSort(vector <int>&  a) {
    a.insert(a.begin(), INT_MIN);
    int n = a.size();
    int num = a[n - 1];
    for(int i = n-2; i >= 0; --i){
        if(a[i] > num){
            a[i + 1] = a[i];
            output(a);
        }else{
            a[i + 1] = num;
            output(a);
            break;
        }
    }

}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
   for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
      int _ar_tmp;
      cin >> _ar_tmp;
      _ar.push_back(_ar_tmp); 
   }

insertionSort(_ar);
   
   return 0;
}
/*QUESTION 2: Sort the entire array using insertion sort*/
//SOLUTION
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'insertionSort2' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

void insertionSort2(int n, vector<int> arr) {
    for(int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        for( ; j>=0 ; j--){
            if(arr[j] > temp){
                // right shift larger numbers
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
        for(int k = 0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort2(n, arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

/*Question 3: Correctness and loop invariant for insertion sort*/
//SOLUTION
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int N, int arr[]) {
    int i,j;
    int value;
    for(i=1;i<N;i++)
    {
        value=arr[i];
        j=i-1;
        //while(j>0 && value<arr[j])  ....this line contains the error
        while(j>=0 && value<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=value;
    }
    for(j=0;j<N;j++)
    {
        printf("%d",arr[j]);
        printf(" ");
    }
}
int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}