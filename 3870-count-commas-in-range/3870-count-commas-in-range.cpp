class Solution {
public:
    int countCommas(int n) {
        if(n==1e5){
          return (100000 - 1000 + 1);
        }
        
        if(n<1000){
            return 0;
        }
        return n - 1000 + 1;
    }
};