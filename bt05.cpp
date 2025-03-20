#include <iostream>
#include <vector>
using namespace std;
void PrintMerge( vector<int> p , int l , int r){
    for(  int i = 0 ; i < p.size() ; i++){
        if( i == l) cout<<"[ ";
        cout<<p[i]<<" ";
        if( i == r) cout<<"] ";
    }
    cout<<endl;
}
void mergeTwoSortArr(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

    int i = 0, j = 0;
    int start = l;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            a[start++] = left[i++];
        } else {
            a[start++] = right[j++];
        }
    }

   
    while (i < left.size()) {
        a[start++] = left[i++];
    }
    while (j < right.size()) {
        a[start++] = right[j++];
    }
    PrintMerge(a,l,r);
}


void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        mergeTwoSortArr(arr, l, m, r);
    }
}


int main() {
    int n ; cin>>n ; 
    vector<int> nums ; 
    for( int i = 0 ; i < n ; i++){
        int temp; 
        cin>>temp ;
        nums.push_back(temp);
    }
    mergeSort(nums, 0 , nums.size() -1  );
    system("pause");
    return 0;
}
