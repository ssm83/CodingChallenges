#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    unordered_set<int> setOfInts;
    //Optimization
    for (int i : nums) {
        setOfInts.insert(i);
    }
    if (setOfInts.size() == nums.size()) //No repetition
        return false;
    setOfInts.clear();
    int start = 0;
    int end = k + 1;
    int size = nums.size();
    if (end > size) end = size;
    while (end <= size) {
        for (int i = start; i < end; i++) {
            setOfInts.insert(nums[i]);
        }
        if (setOfInts.size() < (end - start))
            return true;
        setOfInts.clear();
        start++;
        end++;
    }
    return false;
}

int main() {
	// your code goes here
	vector<int> v1 { 34, 23, 34, 35, 10, 23, 100, 101, 102, 103, 10 };
	vector<int> v2 { 13, 23, 1, 2, 3 };
	vector<int> v3 { 4, 1, 2, 3, 1, 5 };
	
	if (containsNearbyDuplicate(v1, 2))
	    cout << "Contains Nearby K -- 2" << endl;
	if (containsNearbyDuplicate(v1, 4))
	    cout << "Contains Nearby K -- 4" << endl;
	if (containsNearbyDuplicate(v2, 5))
	    cout << "Contains Nearby K -- 5" << endl;
	if (containsNearbyDuplicate(v3, 3))
	    cout << "Contains Nearby K -- 3" << endl;

	return 0; 
}
