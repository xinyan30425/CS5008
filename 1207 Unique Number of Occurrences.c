// Bubble Sort function to sort an integer array
void bubbleSort(int *arr, int arrSize) {
    // Outer loop iterates through the array
    for (int i = 0; i < arrSize - 1; i++) {
        // Inner loop iterates through the remaining unsorted part of the array
        for (int j = 0; j < arrSize - i - 1; j++) {
            // Compare adjacent elements and swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool uniqueOccurrences(int* arr, int arrSize) {
    // If the array is empty, return true
    if (arrSize == 0) {
        return true;
    }

    // Sort the input array using the bubbleSort function
    bubbleSort(arr, arrSize);

    // Allocate memory for the occurrences array
    int *occurrences = (int *)calloc(arrSize, sizeof(int));
    int uniqueCount = 0;
    int count = 1;

    // Iterate through the sorted input array and count occurrences of each value
    for (int i = 1; i < arrSize; i++) {
        // If the current element is equal to the previous element, increment the count
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            // If the current element is different from the previous one,
            // store the count in the occurrences array and reset the count to 1
            occurrences[uniqueCount++] = count;
            count = 1;
        }
    }
    // Store the count of the last element in the occurrences array
    occurrences[uniqueCount++] = count;

    // Sort the occurrences array using the bubbleSort function
    bubbleSort(occurrences, uniqueCount);

    // Iterate through the sorted occurrences array and check for duplicate counts
    for (int i = 1; i < uniqueCount; i++) {
        // If a duplicate count is found, free the memory and return false
        if (occurrences[i] == occurrences[i - 1]) {
            free(occurrences);
            return false;
        }
    }

    // If no duplicate counts are found, free the memory and return true
    free(occurrences);
    return true;
}