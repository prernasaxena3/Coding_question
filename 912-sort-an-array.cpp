//sort-an-array

class Solution {
public:

    void mergeSort(vector<int>& nums,int start,int end){

        if(start >= end){
            return;
        }
        int mid = start + (end- start) / 2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }

    void merge(vector<int>& nums,int start,int mid,int end){
        int n1 = mid-start+1;
        int n2 = end-mid;
        int L[n1],M[n2];
        for(int i = 0;i<n1;i++)
            L[i]= nums[start+i];
        for(int j = 0;j<n2;j++){
            M[j] = nums[mid+j+1];
        } 
        int i =0,j=0,k=start;
        //compare
        while(i<n1 && j<n2){
            if(L[i] <= M[j]){
                nums[k] = L[i];
                i++;
            }else{
                nums[k] = M[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            nums[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k] = M[j];
            j++;
            k++;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};
