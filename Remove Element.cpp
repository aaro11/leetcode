class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ind1 = 0, ind2 = n-1;
        while(ind1 <= ind2){
            while(ind1 <= ind2 && A[ind1] != elem)
                ind1++;
            while(ind2 > ind1 && A[ind2] == elem){
                ind2--;
      		n--;
			}
    		if (ind2 < ind1)
				break;
            n--;
            A[ind1++] = A[ind2--];
            
        }
        return n;
    }
};
