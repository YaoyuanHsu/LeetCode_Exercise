bool isUgly(int n){
    if ((n == 1) || (n == 2) || (n == 3) || (n == 5))
        return true;
    for (int i = 2;i <= ceil(sqrt(n));i ++)
        if(n%i == 0)
            return isUgly(i) & isUgly(n / i);
    
    return false;
}