class Solution {
public:
    bool isHappy(int n) {
        if(n == 0)
            return false;
        vector<int> computed_num;
        return subIsHappy(n, computed_num);
    }

    bool subIsHappy(int n, vector<int>& computed_num){
        if(n == 1)
            return true;
        int square = 0;
        if(n < 10)
            square += n*n;
        else{
            int m = n;
            while(m%10 == 0 || (m==1)){
                if(m == 1)
                    return true;
                else if(m >= 10)
                    m /= 10;
                else
                    break;
            }

            int i = 1;
            while(n > pow(10, i-1)){
                long long tmp = pow(10, i);
                int tmp2 = (n % tmp)/(tmp/10);
                square += pow(tmp2, 2);
                i++;
            }
        }

        for(int j=0; j<computed_num.size(); j++){
            if(square == computed_num[j])
                return false;
        }

        computed_num.push_back(square);
        subIsHappy(square, computed_num);
    }
};
