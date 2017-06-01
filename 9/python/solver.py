class Solution:
    def isPalindrome(self,x):
        if x <0:return False
        factor=1
        while x/factor >=10:
            factor*=10

        while(factor):
            l=x/factor
            r=x%10
            if l != r:
                return False
            x%=factor
            x/=10
            factor/=100
        return True


solver=Solution()
print(solver.isPalindrome(1000031))
print(solver.isPalindrome(10000310))
print(solver.isPalindrome(1))