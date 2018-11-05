int checkV(int &i, string& s){
    if(i > 0 && s[i-1] == 'I'){
        i--;
        return 4;
    }
        
    else
        return 5;
}

int checkX(int &i, string& s){
    if(i > 0 && s[i-1] == 'V'){
        i--;
        return 10 - checkV(i, s);
    }
    else if(i > 0 && s[i-1] == 'I'){
        i--;
        return 10 - 1;
    }    
    else
        return 10;
}

int checkL(int &i, string& s){
    if(i > 0 && s[i-1] == 'X'){
        i--;
        return 50 - checkX(i, s);
    } 
    else if(i > 0 && s[i-1] == 'V'){
        i--;
        return 50 - checkV(i, s);
    }  
    else if(i > 0 && s[i-1] == 'I'){
        i--;
        return 50 - 1;
    } 
        
    else
        return 50;
}

int checkC(int &i, string& s){
    if(i > 0 && s[i-1] == 'L'){
        i--;
        return 100 - checkL(i, s);
    }
    else if(i > 0 && s[i-1] == 'X'){
        i--;
        return 100 - checkX(i, s);
    }
    else if(i > 0 && s[i-1] == 'V'){
        i--;
        return 100 - checkV(i, s);
    }  
    else if(i > 0 && s[i-1] == 'I'){
        i--;
        return 100 - 1;
    }    
    else
        return 100;
}

int checkD(int &i, string& s){
    if(i > 0 && s[i-1] == 'C'){
        i--;
        return 500 - checkC(i, s);
    }
    else if(i > 0 && s[i-1] == 'L'){
        i--;
        return 500 - checkL(i, s);
    }
    else if(i > 0 && s[i-1] == 'X'){
        i--;
        return 500 - checkX(i, s);
    }
    else if(i > 0 && s[i-1] == 'V'){
        i--;
        return 500 - checkV(i, s);
    }  
    else if(i > 0 && s[i-1] == 'I'){
        i--;
        return 500 - 1;
    }    
    else
        return 500;
}

int checkM(int &i, string& s){
    if(i > 0 && s[i-1] == 'D'){
        i--;
        return 1000 - checkD(i, s);
    }
    else if(i > 0 && s[i-1] == 'C'){
        i--;
        return 1000 - checkC(i, s);
    }
    else if(i > 0 && s[i-1] == 'L'){
        i--;
        return 1000 - checkL(i, s);
    }
    else if(i > 0 && s[i-1] == 'X'){
        i--;
        return 1000 - checkX(i, s);
    }
    else if(i > 0 && s[i-1] == 'V'){
        i--;
        return 1000 - checkV(i, s);
    }  
    else if(i > 0 && s[i-1] == 'I'){
        i--;
        return 1000 - 1;
    }  
    else
        return 1000;
}



class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int out = 0;
        for(int i = len; i >= 0; i--){
            if(s[i] == 'M'){
                out += checkM(i, s);
            }
            else if(s[i] == 'D'){
                out += checkD(i, s);
            }
            else if(s[i] == 'C'){
                out += checkC(i, s);
            }
            else if(s[i] == 'L'){
                out += checkL(i, s);
            }
            else if(s[i] == 'X'){
                out += checkX(i, s);
            }
            else if(s[i] == 'V'){
                out += checkV(i, s);
            }
            else if(s[i] == 'I'){
                out += 1;
            }
        }
        return out;
    }
};