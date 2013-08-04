class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<char *> paths;
        int ind = 0, len = path.size();
    	char *cpath = new char[len + 1];

		strcpy(cpath, path.c_str());
		char *p = strtok(cpath, "/");
		while(p){
			paths.push_back(p);
			p = strtok(NULL, "/");
		}
		bool useful[1000];
		
        for(int i = 0; i != paths.size(); i++){
			useful[i] = true;
            if (strcmp(paths[i], "..") == 0){
				int ind = i;
				useful[ind] = 0;
				while(ind > 0){
					ind--;
					if (useful[ind]) {
    			        useful[ind] = false;
                        break;
					}
				}
            } else if (strcmp(paths[i], ".") == 0 || strcmp(paths[i], "") == 0){
				useful[i] = false;
			}
        }
		string result = "";
		for (int i = 0; i != paths.size(); i++){
			if (useful[i]){
				result = result + "/" + paths[i];
			}
		}
        if (!result.size()) result = "/";
		return result;
    }
};