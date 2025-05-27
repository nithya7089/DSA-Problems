class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = (n*(n+1))/2;
        int d = n/m;
        int diff = m * (d*(d+1))/2;
        return (total - 2*diff);
    }
};