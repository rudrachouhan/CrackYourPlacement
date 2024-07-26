class Solution {
public:
    bool isNumber(string s) {
        if(s.length() == 0) return false;
        // Check for signs
        int i = -1;

        // in order to avoid doing costly string removal operations,
        // it's better to ignore that index and just increment the access variable("i") as if it doesn't exist
        i += (s[0] == '+' || s[0] == '-');

        //  Pre-E numerical
        bool hasDecimal = 0;
        bool hasDigit = 0;
        while(1){
            if(++i == s.length()){
                return hasDigit;
            }
            if(s[i] >= '0' && s[i] <= '9'){
                hasDigit = 1;
            }
            else if(s[i] == '.'){
                if(hasDecimal) return false;
                hasDecimal = 1;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(hasDigit == 0 || i+1 == s.length()) return false;
                break;
            }
            else{
                return false;
            }
        }

        // Post-E numerical

        // Now check the part with the E. If the last loop was broken out of(and did not return false),
        // that implies that there must be an E integer part

        if(s[i+1] == '+' || s[i+1] == '-')
            if(++i == s.length()-1)
                return false;
        
        // Only integers allowed for the E part
        while((++i < s.length()))
            if(!(s[i] >= '0' && s[i] <= '9'))
                return false;
            
        return true;
    }
};