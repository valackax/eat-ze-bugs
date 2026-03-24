#include <stdio.h>

int main(){
  int d, S, D;
  
  printf("Enter d:");
  scanf("%d", &d);
  
  printf("Enter S:");
  scanf("%d", &S);
  
  printf("Enter D:");
  scanf("%d", &D);
  
  S = (d / 1000) + ((d / 100) % 10) + ((d / 10) % 10) + (d % 10);
  D = (d / 1000) * ((d / 100) % 10) * ((d / 10) % 10) * (d % 10);
    
  printf("Вхідні дані: d = %d\n", d);
  printf("Вихідні дані: S = %d, D = %d\n", S, D);
    
  return 0;
}
