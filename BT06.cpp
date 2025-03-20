#include<iostream>
#include<vector>
using namespace std ; 

void swap( int & a, int&b){
    int temp = a; 
    a = b ; 
    b = temp ; 
}
void output( const vector<int> v){
    for( int a : v){
        cout<<a<<" ";
    }cout<<endl;
}
void InsertionSort( vector<int> &nums){
    int  n = nums.size() ;
    for ( int i = 0 ; i < n  ; i++){
        int temp = nums[i];
        int j = i - 1; 
        while( j >= 0 && temp < nums[j]){
            nums[j+1] = nums[j];
            output( nums);
            j--;
        }
        nums[j+1] = temp;
        if( i != 0 ) output(nums);
    }
}
int main(){
    vector<int> nums ;
    int n ; cin>>n ; 
    for( int i = 0 ; i < n ; i++){
        int temp ; 
        cin>>temp ; 
        nums.push_back(temp);
    }
    InsertionSort(nums);

    system("pause");
    return 0 ; 
}