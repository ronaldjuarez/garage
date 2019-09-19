#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int quickSelectPartition(std::vector<int>& v, int l, int r) {
	int size = v.size();
	if (size == 0) return -1;

	int i = l, pivot = r;

	for (int j = l; j < pivot; j++) {
		if (v[j] < v[pivot]) {
			std::swap(v[i], v[j]);
			i++;
		}
	}
	std::swap(v[i], v[pivot]);
	return i;
}

int randomPartition(vector<int> &arr, int l, int r)
{
	int n = r - l + 1;
	int pivot = rand() % n;
	std::swap(arr[l + pivot], arr[r]);
	return quickSelectPartition(arr, l, r);
}

int kthSmallestElementh(vector<int>& v, int l, int r, int k) {
	if (k > 0 && k <= r - l + 1) {
		int i = randomPartition(v, l, r);
		if (i - l == k - 1) {
			return v[i];
		}
		if (i - l > k - 1) {
			return kthSmallestElementh(v, l, i - 1, k);
		}
		return kthSmallestElementh(v, i + 1, r, k - (i + 1) + l);
	}
	return INT_MAX;
}


int main(){
    vector<int> v{7, 10, 4, 3, 20, 15};
    cout << kthSmallestElementh(v, 0, v.size() - 1, 4) << endl;
    return 0;
}