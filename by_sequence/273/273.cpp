class Solution {
public:
            vector<string> below20={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousand = {"", "Thousand", "Million", "Billion"};
        
    string calculBelow1000(int num){
        if (num == 0)
            return "";
        else if (num < 20)
            return below20[num] + " ";
        else if (num < 100)
            return tens[num / 10] + " " + calculBelow1000(num % 10);
        else
            return below20[num / 100] + " Hundred " + calculBelow1000(num % 100);
    }
    
    
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string out;
        int i = 0;
        while(num){
            if(num%1000!=0){
                out = calculBelow1000(num%1000) + thousand[i] + " " + out;
            }
            num /= 1000;
            i++;
        }
        int blankCount = 0;
        int back = out.size()-1;
        while(back>=0&&out[back--] == ' '){
            blankCount++;
        }
        out = out.substr(0, out.size()-blankCount);
        return out;
    }
    
};