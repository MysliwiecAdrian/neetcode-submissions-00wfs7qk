class Solution {
public:
    double myPow(double x, int n) {
        double res;
        int count;

        if (n < 0){
            count = n * -1;
            res = 1 / x;
            for (int i = 0; i < count - 1; i++){
                res *= 1 / x;
            }
        }
        else if (n > 0){
            res = x;
            for (int i = 0; i < n - 1; i++){
                res *= x;
            }
        }
        else{
            res = 1;
        }

        return res;
    }
};
