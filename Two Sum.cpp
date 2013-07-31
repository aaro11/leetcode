struct number{
    int value;
    int ind;
};

int comp(const number &n1, const number &n2){
    return n1.value < n2.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<number> arr;
        vector<int> result;
        int len = numbers.size();
        
        for (int i = 0; i != len; i++){
            number n = number();
            n.value = numbers[i];
            n.ind = i;
            arr.push_back(n);
        }
        sort(arr.begin(), arr.end(), comp);
        
        int startind = 0, endind = len - 1;
        while(endind > startind){
            int sum = arr[startind].value + arr[endind].value;
            if (sum == target){
                result.push_back(arr[startind].ind + 1);
                result.push_back(arr[endind].ind + 1);
                break;
            }
            if (sum < target){
                startind++;
                continue;
            }
            if (sum > target){
                endind--;
                continue;
            }
            
        }
        sort(result.begin(), result.end());
        return result;
    }
};