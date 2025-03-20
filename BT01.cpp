#include <iostream>
#include <vector>
using namespace std;

bool compareTriple(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.first < b.first) return true;
    if (a.first == b.first) {
        if (a.second.first > b.second.first) return true; // y giảm dần
        if (a.second.first == b.second.first) return a.second.second < b.second.second; // z tăng dần
    }
    return false;
}

void merge(vector<pair<int, pair<int, int>>>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int, pair<int, int>>> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compareTriple(L[i], R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<pair<int, pair<int, int>>>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void output(const vector<pair<int, pair<int, int>>>& points) {
    for (const auto& p : points)
        cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> points;

   
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        points.push_back({x, {y, z}});
    }


    mergeSort(points, 0, n - 1);
    output(points);

    return 0;
}
