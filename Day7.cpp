/*Manasa is out on a hike with friends. She finds a trail of stones with numbers on them. She starts following the trail and notices that any two consecutive stones’ numbers differ by one of two values. Legend has it that there is a treasure trove at the end of the trail. If Manasa can guess the value of the last stone, the treasure will be hers.

Example

n = 2
a = 2
b = 3

She finds  stones and their differences are a = 2 or b = 3. We know she starts with a 0 stone not included in her count. The permutations of differences for the two stones are [2, 2], [2, 3], [3, 2] or [3, 3]. Looking at each scenario, stones might have [2, 4], [2, 5], [3, 5] or [3, 6] on them. The last stone might have any of 4, 5 or 6 on its face.

Compute all possible numbers that might occur on the last stone given a starting stone with a 0 on it, a number of additional stones found, and the possible differences between consecutive stones. Order the list ascending.*/
//SOLUTION.........
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        vector<int>arr;
        if(a == b){
            arr.push_back((n-1)*a);
        }else{
            for(int i = 1;i<=n;i++){
                arr.push_back(((n-i)*a) + (i-1)*b);
            }
        }
        sort(arr.begin(),arr.end());
        for(int i = 0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*QUESTION 2: A driver is driving on the freeway. The check engine light of his vehicle is on, and the driver wants to get service immediately. Luckily, a service lane runs parallel to the highway. It varies in width along its length.

You will be given an array of widths at points along the road (indices), then a list of the indices of entry and exit points. Considering each entry and exit point pair, calculate the maximum size vehicle that can travel that segment of the service lane safely.

Example

n = 4
width = [2, 3, 2, 1]
cases = [[1, 2], [2, 4]]

If the entry index, i = 1 and the exit, j = 2, there are two segment widths of 2 and 3 respectively. The widest vehicle that can fit through both is 2. If i = 2 and j = 4, the widths are [3, 2, 1] which limits vehicle width to 1.*/
//SOLUTION........
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int w = 0;w<n;w++){
        cin>>arr[w];
    }
    int min;
    for(int a = 0;a<t;a++){
        int i,j;
        cin>>i>>j;
        min = arr[i];
        for(int b = i+1;b<=j;b++){
            if(arr[b]<min){
                min = arr[b];
            }
        }
        cout<<min<<endl;
    }
}

/*QUESTION 3: There is a sequence of words in CamelCase as a string of letters, s, having the following properties:

It is a concatenation of one or more words consisting of English letters.
All letters in the first word are lowercase.
For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.
Given s, determine the number of words in s.*/
//SOLUTION....

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int camelcase(string s) {
    int words = 1;
    int n = s.length();
    for(int i = 0;i<n;i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            words++;
    }
    return words;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

/*We say that a string contains the word hackerrank if a subsequence of its characters spell the word hackerrank. Remeber that a subsequence maintains the order of characters selected from a sequence.

More formally, let p[0], p[1], . . . , p[9] be the respective indices of h, a, c, k, e, r, r, a, n, k in string s. If p[0] < p[1] < p[2] < . . . < p[9] is true, then s contains hackerrank.

For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO.*/

//SOLUTION

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'hackerrankInString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string hackerrankInString(string s) {
   string ans = "NO";
   string s1 = "hackerrank";
   int index = 0;
   for(int i = 0;i<s.length();i++){
       if(s[i] == s1[index]){
           index++;
       }
       if(index == s1.length()){
           ans = "YES";
       }
   }
   return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

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

