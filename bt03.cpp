#include <iostream>
#include <vector>

using namespace std;

int findMEX(int arr[], int n)
{
    bool checked[n + 1] = {false};
    for( int i  = 0  ; i < n ; i++){

        if( arr[i] >= 0 && arr[i] <= n  ) {
            checked[arr[i]] = true ;
        } 
    }
    for( int i = 0 ; i < n ; i++){
        if( checked[i] == false ) return i ; 
    }
    return -1 ; 
}
int main()
{
    int n ;
    cin>>n ; 
    int arr[n] ={};
    for( int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<findMEX(arr,n);
    system("pause");
    return 0;
}