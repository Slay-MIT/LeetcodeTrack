class Solution {
public:
    int binaryGap(int n) {
        int max_c = 0;
        string binary_str = bitset<32>(n).to_string();
        int len = binary_str.length();
        for(int i=0; i<len; i++){
            if(binary_str[i] == '1'){
                int j = i+1;
                while(j<len){
                    if(binary_str[j] == '1'){
                        max_c = max(j - i, max_c);
                        break;
                    }
                    j++;
                }
            }
        }       
        return max_c;
    }
};