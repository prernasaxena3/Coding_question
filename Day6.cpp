/*The only thing you should print is the number of shifts made by the algorithm to completely sort the array using insertion sort. A shift occurs when an element's position changes in the array. Do not shift an element if it is not necessary.*/
//SOLUTION
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'runningTime' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int runningTime(vector<int> arr) {
    int ans = 0;
    for(int i = 1; i<arr.size(); i++){
        int temp = arr[i];
        int j = i-1;
        for( ; j>=0 ; j--){
            if(arr[j] > temp){
                // right shift larger numbers
                arr[j+1] = arr[j];
                ans ++;
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;

    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = runningTime(arr);

    fout << result << "\n";

    fout.close();

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

/*Question 2: Using Quick Sort, Choose some pivot element, p, and partition your unsorted array, arr, into three smaller arrays: left, right, and equal, where each element in left < p, each element in right > p, and each element in equal = p.*/
//SOLUTION
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void quickSort(vector<int> arr) {
    int pivot = arr[0];
    vector<int> left;
    vector<int> right;
    for(int i = 1;i<arr.size();i++){
        if(arr[i] >= pivot){
            right.push_back(arr[i]);
        }else{
            left.push_back(arr[i]);
        }
    }
    for(int j = 0;j<left.size();j++){
        cout<<left[j]<<" ";
    }
    cout<<pivot<<" ";
    for(int j = 0;j<right.size();j++){
        cout<<right[j]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    quickSort(arr);
}
