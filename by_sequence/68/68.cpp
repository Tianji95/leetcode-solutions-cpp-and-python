class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> out;
        int len = words.size();
        int nowLen = 0;
        vector<string> tmpVector;
        
        for(int i = 0; i < len; i++){
            if(words[i].size() + 1 + nowLen <=maxWidth || words[i].size()+nowLen == maxWidth){
                tmpVector.push_back(words[i]);
                nowLen += words[i].size() + 1;
            }
            else{
                int tmpSize = tmpVector.size();
                string tmpString("");
                int tmpTotalSize = 0;
                nowLen = 0;
                if(tmpSize == 1){
                    int spaceSize = maxWidth - tmpVector[0].size();
                    tmpString = tmpVector[0];
                    for(int j = 0; j < spaceSize; j++){
                        tmpString = tmpString + " ";
                    }
                }
                else{
                    for(int j = 0; j < tmpSize; j++){
                        tmpTotalSize += tmpVector[j].size();
                    }
                    int spaceSize = maxWidth - tmpTotalSize;
                    int averageSpaceSize = spaceSize / (tmpSize-1);
                    int leftSpaceSize = spaceSize % (tmpSize-1);
                    
                    tmpString = tmpVector[0];
                    for(int j = 1; j < tmpSize; j++){
                        if(leftSpaceSize!=0){
                            tmpString += ' ';
                            leftSpaceSize--;
                        }
                        tmpString += string(averageSpaceSize, ' ') + tmpVector[j];
                    }
                    
                }

                out.push_back(tmpString);
                tmpVector.clear();
                nowLen = 0;
                i--;
            }
        }
        
        int tmpVectorSize = tmpVector.size();
        if(tmpVectorSize!=0){
            string tmpString("");
            nowLen = 0;
            for(int i = 0; i < tmpVectorSize - 1; i++){
                tmpString += tmpVector[i] + " ";
                nowLen += tmpVector[i].size() + 1;
            }
            tmpString += tmpVector[tmpVectorSize - 1];
            nowLen += tmpVector[tmpVectorSize - 1].size();
            tmpString += string(maxWidth-nowLen, ' ');
            out.push_back(tmpString);
        }
        return out;
    }
};