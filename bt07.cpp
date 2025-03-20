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
void BubbleSort( vector<int> &nums){
    int n = nums.size();  
    for( int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < n - i - 1 ; j++){
            if( nums[j+1] < nums[j]){
                swap( nums[j+1] , nums[j] );
                output(nums);
            }
        }
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
    BubbleSort(nums);

    system("pause");
    return 0 ; 
}