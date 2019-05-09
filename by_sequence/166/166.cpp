class Solution {
public:
	string fractionToDecimal(int numerato, int denominato) {
		bool isMinus = false;
		if ((numerato < 0 && denominato > 0) || (numerato > 0 && denominato < 0))
			isMinus = true;

		long numerator = numerato < 0 ? (long)numerato * (-1) : (long)numerato;
        long denominator = denominato < 0 ? (long)denominato * (-1) : (long)denominato;
		long font = numerator / denominator;
		long de = numerator % denominator;
		std::string out;
		out = std::to_string(font);
		if (de != 0)
			out = out + ".";

		std::map<long, long> fontMap;
		vector<long> fontList;
		long idx = 0;
        
        de *= 10;
		while (de != 0) {
			font = de / denominator;
            
			if (fontList.size()>0 && fontMap.find(de) != fontMap.end()) {
				break;
			}
			else {
				fontList.push_back(font);
				fontMap[de] = idx++;
			}
            de = de % denominator * 10;
		}
		if (de == 0) {
			for (int i = 0; i < fontList.size(); i++) {
				out = out + std::to_string(fontList[i]);
			}
		}
		else {
			auto findIdx = fontMap.find(de);
			for (int i = 0; i < findIdx->second; i++) {
				out = out + std::to_string(fontList[i]);
			}
			out = out + '(';
			for (int i = findIdx->second; i < fontList.size(); i++) {
				out = out + std::to_string(fontList[i]);
			}
			out = out + ')';
		}
		if (isMinus) {
			out = "-" + out;
		}
		return out;


	}
};