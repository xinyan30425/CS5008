//linear approach, nased on merging two sorted array then find the median

// double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
//     int size = nums1Size+ nums2Size;
//     int* combined = (int*) malloc (sizeof(int)*size);
//     int i=0,j=0,k=0;

//     //combine two integer array into a single sorted array
//     while(i<nums1Size && j< nums2Size){
//         if(nums1[i]<nums2[j]){
//             combined[k++]=nums1[i++];//current element is assigned and both indeces are increment by 1
//         }else{
//             combined[k++]=nums2[j++];
//         }
//     }

//     //remaining elements in nums1
//     while(i<nums1Size){
//         combined[k++]=nums1[i++];
//     }

//     //remaining elements in num2
//     while(j<nums2Size){
//         combined[k++]=nums2[j++];
//     }

//     //find median for the single sorted array
//     double median;
//     if(size %2 ==0){
//         median =(combined[size/2-1]+combined[size/2])/2.0;
//     }else{
//         median = combined[size/2];
//     }

//     free(combined);
//     return median;

//     }

//binary search algorithm
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }//make sure nums1 is the smaller array by swapping arrays 

    //initialize the low and high pointers for binary search on the smaller array nums1
    int low = 0;
    int high = nums1Size;
    int half_len = (nums1Size + nums2Size + 1) / 2;//add 1 to account for odd-length arrays

    while (low <= high) {//start the binary search loop, continues as long as low is less than or equal to high
        //calculate the partition points for both array
        int partitionX = (low + high) / 2;
        int partitionY = half_len - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((nums1Size + nums2Size) % 2 == 0) {
                return (fmax(maxLeftX, maxLeftY) + fmin(minRightX, minRightY)) / 2.0;
            } else {
                return fmax(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    return -1.0; // This line should never be reached, but it's added to avoid compiler warnings
}









 