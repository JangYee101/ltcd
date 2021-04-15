
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int maxNum(int *nums, int startI, int endI) {
    if(startI >=  endI)
        return 0;
    if(startI+1 == endI)
        return nums[startI];
    if(startI+2 == endI)
        return nums[startI]>nums[startI+1]?nums[startI]:nums[startI+1];
    int i, max_num=0, l_max, r_max, t;
    for(i=startI; i<endI; i++) {
        l_max = maxNum(nums, startI, i-1);
        r_max = maxNum(nums, i+2, endI);
        t = nums[i] + l_max + r_max;
        max_num = max_num>t?max_num:t;
    }
    return max_num;
} 

int rob(int* nums, int numsSize){
    return maxNum(nums, 0, numsSize);
}

int main(int argc, char ** argv) {
    int size=argc-1, i, *nums = (int *)malloc(sizeof(int)*size);
    for(i=0;i<size;i++) {
        nums[i] = atoi(argv[i+1]);
    }
    printf("%d\n", rob(nums, size));
    return 0;
}
