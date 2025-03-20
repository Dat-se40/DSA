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
void SelectionSort( vector<int>& nums){
    for( int i =  0  ; i < nums.size() ; i++){
        int min = i , j = i + 1 ;
        while(   j < nums.size()   ){
            if ( nums[j] < nums[min] ) min = j;
            j++;
        }
       
        if( nums[min] < nums[i]){
            swap(nums[min] , nums[i]);
            output( nums);
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
    SelectionSort(nums);

    system("pause");
    return 0 ; 
}