#include <stdio.h>
/* Given an array of integers, every element appears twice except for one. Find that single one. */

/*   Note: */
/*   Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? */

int sigleNumber(int *nums, int numsSize){

  int res = nums[0];
  int i;
  for(i=1; i<numsSize; i++){
    res ^= nums[i];
  }
  return res;
}

int main(void){
  int test[] = {3, 5, 8, 1, 2, 6, 7, 10, -1, 0, -3, 3, 5, 8, 1, 2, 6, 7, 10, -1, 0};
  printf("%d\n", sigleNumber(test, 21));
  return 0;
}
