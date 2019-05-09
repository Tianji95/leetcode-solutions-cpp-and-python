class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStk;
        int len = path.size();
        string out;
        string tmpName("");
        bool isNowName = false;
        
        for(int i = 0; i < len; i++){
            if(path[i] == '.'&& i+2 < len && path[i+1] == '.' && path[i+2]=='/' && tmpName==""){
                if(pathStk.size()!=0){
                    pathStk.pop();
                }
            }
            else if(path[i] == '.'&& i+1 < len && path[i+1] == '/' && tmpName==""){
                continue;
            }
            else if(path[i] == '/'){
                if(tmpName!=""){
                    pathStk.push(tmpName);
                    tmpName = "";
                }
            }
            else{
                tmpName = tmpName + path[i];
            }
            
        }
        if(tmpName!="" && tmpName!="." && tmpName!=".."){
            pathStk.push(tmpName);
        }
        else if(tmpName==".."){
            if(pathStk.size()!=0)
                pathStk.pop();
        }
        if(pathStk.size()==0){
            out = "/";
        }
        else{
            out = pathStk.top();
            pathStk.pop();
            while(pathStk.size()!=0){
                out = pathStk.top() +'/'+ out;
                pathStk.pop();
            }
            out = '/' + out;
        }
        
        
        return out;
    }
};