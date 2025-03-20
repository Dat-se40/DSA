#include <iostream>
#include <vector>
using namespace std;

// Hàm so sánh đúng yêu cầu bài toán
bool comparePair(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return true;
    if (a.first == b.first) return a.second > b.second; // y giảm dần khi x bằng nhau
    return false;
}

// Hàm xuất kết quả
void output(const vector<pair<int, int>>& nums) {
    for (pair<int, int> a : nums)   
        cout << a.first << " " << a.second << "\n\n";
}

// Insertion Sort, truyền tham chiếu để chỉnh trực tiếp trên vector gốc
void InsertionSortPair(vector<pair<int, int>>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {  
        pair<int, int> temp = nums[i];
        int j = i - 1;
        // Đẩy các phần tử lớn hơn temp về sau
        while (j >= 0 && comparePair(temp, nums[j])) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp; // Đặt temp vào đúng vị trí
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points;

    // Nhập dữ liệu
    for (int i = 0; i < n; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        points.push_back(temp);
    }

    // Sắp xếp và in ra kết quả
    InsertionSortPair(points);
    output(points);

    
    return 0;
}

