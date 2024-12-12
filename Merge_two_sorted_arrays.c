#include <stdio.h>
#include <stdlib.h>
int *mtsa(int *nums1, int nums1size, int *nums2, int nums2size) {
    int *retArr = (int *)malloc((nums1size + nums2size) * sizeof(int));
    int smaller_size = nums1size < nums2size ? nums1size : nums2size;
    int i, j, k;
    for (int i = 0, j = 0, k = 0; k < smaller_size; i++, j++)
    {
        if(nums1[i] == nums2[j]) {
            retArr[k++] = retArr[k++] = nums1[i];
            i++, j++;
        }   
        else if(nums1[i] > nums2[j]) {
            retArr[k++] = nums2[j++];
        }
        else {
            
        }
    }
    
}