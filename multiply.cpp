//implement multiplier without using multiple and add

int multiply(int x, int y){
    if(x ==0 || y==0) return 0;
    int neg = (x < 0) ^ (y < 0);
    if(x < 0) x = -x;
    if(y < 0) y = -y;
    
    int sum = 0;
    whie(y > 0){
       if(y%2 == 1){
          sum = add(sum,x);
       }
       x = x << 1;
       y = y >> 1;
    }
    if(neg) return -sum;
    else return sum;
}

int add(int a, int b){
   if(a == 0) return b;
   if(b == 0) return a;
   int c = a ^ b;
   int carry = (a&b) << 1;
   return add(c, carry);
}
