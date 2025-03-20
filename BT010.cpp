#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ; 

void smallestDist(  vector<int>& nums){
    sort(nums.begin() , nums.end() );
    // tim small truoc 
    int minD = nums[nums.size() - 1] - nums[0] ; 
    for( int i = 0 ; i < nums.size() - 1 ; i++){
        minD = min( minD , nums[i+1] - nums[i]);
    }
    for( int i = 0 ; i < nums.size() - 1 ; i++){
        int temp =  nums[i+1] - nums[i];
        if( temp == minD) cout<<nums[i]<<" "<<nums[i+1]<<" "; 
    }
}
int main(){
    int n; cin>>n ; 
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    smallestDist(arr);
    system("pause");
    return 0 ; 
}