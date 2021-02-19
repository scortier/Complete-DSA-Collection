
class Solution {
public:
    int searchInRotatedSorted(vector<int>&arr, int low, int high, int target) {
        if (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[low] <= arr[mid]) { // Left Side of the Array is Sorted.
                if (arr[low] <= target && target < arr[mid]) {
                    return searchInRotatedSorted(arr, low, mid - 1, target);
                } else {
                    return searchInRotatedSorted(arr, mid + 1, high, target);
                }
            } else { // Right Side is sorted.
                if (arr[mid] < target && target <= arr[high]) {
                    return searchInRotatedSorted(arr, mid + 1, high, target);
                } else {
                    return searchInRotatedSorted(arr, low, mid - 1, target);
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        return searchInRotatedSorted(nums, low, high, target);
    }
};
