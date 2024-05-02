#include <iostream>
#include <vector>

void shellSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = nums[i]; 
            int j;
            for (j = i; j >= gap && nums[j - gap] > temp; j -= gap) {
                nums[j] = nums[j - gap];
            }
            nums[j] = temp;
        }
    }
}

int main() {
    std::vector<int> numbers = {1, 6, 9, 2, 3, 7, 5, 4, 8};
    shellSort(numbers); 
    std::cout << "Sorted Array: ";
    for (int num : numbers) { 
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
