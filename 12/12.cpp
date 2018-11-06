class Solution {
public:
    string intToRoman(int num) {
        string outs("");
        while(num){
            if(num >= 1000){
                outs += "M";
                num-=1000;
            }
            else if(num < 1000 && num >=900){
                outs += "CM";
                num -= 900;
            }
            else if(num < 900 && num >= 500){
                outs += "D";
                num -= 500;
            }
            else if(num < 500 && num >= 400){
                outs += "CD";
                num  -= 400;
            }
            else if(num <400 && num >= 100){
                outs += "C";
                num  -= 100;
            }
            else if(num < 100 && num >= 90){
                outs += "XC";
                num  -= 90;
            }
            else if(num < 90 && num >= 50){
                outs += "L";
                num  -= 50;
            }
            else if(num < 50 && num >= 40){
                outs += "XL";
                num  -= 40;
            }
            else if(num < 40 && num >= 10){
                outs += "X";
                num  -= 10;
            }
            else if(num == 9){
                outs += "IX";
                num -= 9;
            }
            else if(num < 9 && num >= 5){
                outs += "V";
                num -= 5;
            }
            else if(num == 4){
                outs += "IV";
                num -= 4;
            }
            else{
                outs += "I";
                num--;
            }
        }
        return outs;
    }
};