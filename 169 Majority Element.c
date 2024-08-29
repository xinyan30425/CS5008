//divide and conquer

int majorityElement(int *nums, int numsSize){
    return majorityElementRec(nums,0,numsSize-1);
}

// helper funciton 
int majorityElementRec(int *nums, int left, int right){
    // left, and right represents the range in the array to search for the majority element 
    // return the majority element found in the given range
    if(left == right){
        return nums[left];//if the range has only one element, return that element 
    }

    int mid = (left+right)/2; //calculate the middle index of the range
    int leftMajority = majorityElementRec (nums, left, mid);// recursively find the majority element in the left half of the range
    int rightMajority = majorityElementRec (nums, mid+1, right);// recursively find the majority element in the left half of the range

    if(leftMajority == rightMajority){//if the majority elements from both halves are the same, return either one of them
        return leftMajority;
    }

    int leftCount = countInRange(nums, leftMajority, left, right); //count the occurences of the left half
    int rightCount = countInRange(nums, rightMajority, left, right); //count the occurences of the right half

    return leftCount > rightCount ? leftMajority :rightMajority;//return the element with more occurences in the entire range
}

// count the occurentces of an element in a given range of the array
int countInRange(int *nums, int num, int left, int right){
    int count = 0;
    for (int i = left; i<=right; i++){ //iterate through the range from left to right
        if (nums[i] == num){
            count++;
        }
    }
    return count;
}