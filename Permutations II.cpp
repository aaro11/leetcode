vector<vector<int> > result;
bool visited[1000];

void search(vector<int> &num, vector<int> &tmp){
    bool hasone = false;
    
    for (int i = 0; i != num.size(); i++){
        if  (!visited[i]){
            if (i == 0 || num[i-1] != num[i] || visited[i-1]){
                visited[i] = true;
                tmp.push_back(num[i]);
                search(num, tmp);
                tmp.pop_back();
                visited[i] = false;
                hasone = true;
            }
        }
    }
    if (!hasone){
        result.push_back(tmp);
    }
}

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        result.clear();
        memset(visited, 0, sizeof(visited));
        vector<int> tmp;
        sort(num.begin(), num.end());
        search(num, tmp);
        
        return result;
    }
};