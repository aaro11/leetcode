
int result, bound;
void setmask(vector<int> &mask, int step, int pos){
    int len = mask.size();
    
    for (int i = step+1; i != len; i++){
      mask[i] |= 1 << pos;
	}
    
    int lb = max((int)0, 0 - min(pos, step)), ub = len - max(step, pos);
    for (int i = lb; i != ub; i++){
		mask[step+i] |= 1 << (pos + i);
    }
    
    for (int i = -13; i != 14; i++){
        if (step-i < len && step-i>-1 && pos+i < len && pos + i > -1)
			mask[step-i] |= 1 << (pos + i);
    }
    
    return ;
}

int search(vector<int> & mask, int step, int sz){
    if (step == sz){
        return 1;
    }
    int x = 0;
    for (int i = 0; i != sz; i++){
        if (!(1<<i & mask[step])){
            vector<int> tmp = mask;
            setmask(tmp, step, i);

            x += search(tmp, step + 1, sz);
        }
    }
	return x;
}

class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		result = 0;
        vector<int> mask(n);
        return search(mask, 0, n);
        
    }
};
