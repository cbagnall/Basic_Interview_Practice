
float powerIterative(float base, int exponent){
  float temp = 1.0;
  for(int i = 0; i < exponent; i++){
    temp *= base;
  }
  return temp;
};

float power_recursive(float base, int exponent){
  if(exponent == 0){
    return 1.0;
  }
  else if (exponent > 0){
    return base *= power_recursive(a, exponent-1);
  } 
  else{
    return base *= power_recursive(a, exponent+1);
  }
};

float power(float base, int exponent, bool recursive){
  float result = 0.0;
  if (exponent < 0){base = (1/base);}  //accounts for negative exponents

  if(recursive){
    result = power_recursive(base, exponent);
  }
  else{
    result = powerIterative(base, exponent);
  }
  
  return result;
};