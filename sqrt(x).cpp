unsigned int arr[100000];
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i != 100000; i++)
            arr[i] = i * i;
            
        for (int i = 0; i != 99999; i++){
            if (arr[i] <= x && arr[i+1]>x)
                return i;
        }
    }
};