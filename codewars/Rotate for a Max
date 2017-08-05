long long maxRot(long long n) {
  long long t_digit = 10;
  long long tmp = n, max=n;
  
  while(t_digit<n) t_digit *= 10;  
  t_digit /=10;

  while(t_digit !=0 ){
        long long k_digit = t_digit * 10;
        long long bottom_n = tmp%t_digit;
        long long top_n = (tmp/t_digit)%10;
        long long k_n = tmp/k_digit;
        tmp = k_n*k_digit + bottom_n*10 + top_n;
        t_digit /= 10;
        max = tmp>max?tmp:max;
  }
  
  return max;
}
