#include "unit_tests.h"
#include <stdio.h> 

//check if the returned pointer is NULL
Status test_init_default_returns_nonNULL(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();
	// strncpy allows us to copy a message into a buffer that can be returned by the test function. 
	if(hQueue == NULL){
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
		"my_string_init_default returns NULL", length);
		return Failure;
	}
	else{
		queue_destroy(&hQueue);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return Success;
	}
}

//test whether the queue_getTotalItems function returns zero when called on a newly created queue using queue_init_default. 
Status test_get_totalItems_on_init_default_returns_0(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();
	Status status;
	
	if(queue_getTotalItems(hQueue) != 0){
	status = Failure;
	printf("Expected a size of 0 but got %d\n", queue_getTotalItems(hQueue));
	strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	"Did not receive 0 from get_size after init_default\n", length);
   }
	else
	{
	status = Success;
	strncpy(buffer, "test_get_size_on_init_default_returns_0\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}


//Test to verify that the queue is empty after initialization:
Status test_xinyanliu_init_default_creates_empty_queue(char* buffer, int length){
    QUEUE hQueue = queue_init_default();
    if (queue_getTotalItems(hQueue) != 0) {
        strncpy(buffer, "test_init_default_creates_empty_queue\n"
                "Queue was not empty after initialization", length);
        queue_destroy(&hQueue);
        return Failure;
    }
    queue_destroy(&hQueue);
    strncpy(buffer, "test_init_default_creates_empty_queue\n", length);
    return Success;
}

//Test to verify that the queue returns Failure when attempting to dequeue from an empty queue:
Status test_xinyanliu_dequeue_on_empty_queue_returns_Failure(char* buffer, int length){
    QUEUE hQueue = queue_init_default();
    Status status = queue_dequeue(hQueue);
    if (status != Failure) {
        strncpy(buffer, "test_dequeue_on_empty_queue_returns_Failure\n"
                "Dequeue did not return Failure on an empty queue", length);
        queue_destroy(&hQueue);
        return Failure;
    }

    queue_destroy(&hQueue);
    strncpy(buffer, "test_dequeue_on_empty_queue_returns_Failure\n", length);
    return Success;
}

//Testing queue_dequeue with an empty queue:
Status test_xinyanliu_dequeue_empty_queue(char* buffer, int length){
	QUEUE hQueue = queue_init_default();
	Status status;

	// Test whether queue_dequeue returns Failure when the queue is empty
	status = queue_dequeue(hQueue);
	if(status != Failure){
		strncpy(buffer, "test_dequeue_empty_queue\n"
		"queue_dequeue did not return Failure for empty queue", length);
		queue_destroy(&hQueue);
		return Failure;
	}

	queue_destroy(&hQueue);
	strncpy(buffer, "test_dequeue_empty_queue\n", length);
	return Success;
}


Status test_xinyanliu_destory_sets_handle_to_NULL(char* buffer, int length) {
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();
	queue_destroy(&hQueue);

	if(hQueue != NULL){
        strncpy(buffer, "test_destroy_sets_handle_to_NULL\n"
        "queue_destroy failed to set handle to NULL", length);
        return Failure;
    }
    else{
        strncpy(buffer, "\ttest_destroy_sets_handle_to_NULL\n", length);
        return Success;
    }
}

Status test_xinyanliu_queue_destroy(char* buffer, int length) {
    QUEUE hQueue = queue_init_default();
    Status status;
    // Test whether queue_destroy function works correctly
    queue_destroy(&hQueue);
    if (hQueue != NULL) {
        status = Failure;
        strncpy(buffer, "test_queue_destroy\n"
        "Queue was not properly destroyed", length);
    } else {
        status = Success;
        strncpy(buffer, "test_queue_destroy\n", length);
    }
    return status;
}

// Test whether printFrontItem works correctly when queue is empty
Status test_xinyanliu_printFrontItem(char* buffer, int length) {
    QUEUE hQueue = queue_init_default();
    char expected_output[] = "Front is: 10";
    //char result[100];
    
    queue_enqueue(hQueue, 10); 
    char * result = printFrontItem(hQueue);

    printf("%s\n",expected_output);
	printf("%s\n",result);

    if (strcmp(result,expected_output) != 0) {
        return Failure;
    } else{
        queue_destroy(&hQueue);
        strncpy(buffer, "test_printFrontItem", length);
        return Success;
    }
}

// Test whether printQueueIndices prints the frontIndex and backIndex of the queue correctly
Status test_xinyanliu_print_queue_indices(char* buffer, int length){
    QUEUE hQueue = queue_init_default();
    char expected_output[] = "frontIndex: 0\nbackIndex: 1\n";
    char result[100];
    queue_enqueue(hQueue, 10);  
    printf("%s",expected_output);
    printQueueIndices(hQueue);

    if (strcmp(result,expected_output) == 0) {
        strncpy(buffer, "test_print_queue_indices\n", length);
        return Failure;
    }
    else{
        queue_destroy(&hQueue);
        strncpy(buffer, "test_print_queue_indices\n", length);
        return Success;
    }
}

Status test_kekezhang_just_reach_full_capacity(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();
	Status status = Success;
	
	int init_cap = 7;
	// insert [0, 1, 2, 3, 4, 5, 6]
	for (int i = 0; i < init_cap; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			break;
		}
	}

	if (queue_getTotalItems(hQueue) != init_cap) {
		status = Failure;
	}

	if (status == Failure) 
	{
		printf("Expected a size of 7 but got %d\n", queue_getTotalItems(hQueue));
		strncpy(buffer, "test_kekezhang_just_reach_full_capacity\n"
		"Did not receive 7 from get_size after insert 7 numbers\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_just_reach_full_capacity\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_insert_capacity_plus_one_number(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	int init_cap = 7;
	int insert_num = init_cap + 1;
	// insert [0, 1, 2, 3, 4, 5, 6, 7]
	for (int i = 0; i < insert_num; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert failed\n");
			break;
		}
	}

	if (queue_getTotalItems(hQueue) != insert_num) {
		status = Failure;
		printf("Expected a size of %d but got %d\n", insert_num, queue_getTotalItems(hQueue));
	}

	// capacity should be doubled since we are inserting (capacity + 1) values
	int excepted_capacity = init_cap * 2;
	if (excepted_capacity != queue_getCapacity(hQueue)) {
		status = Failure;
		printf("Expected a capacity of %d but got %d\n", excepted_capacity, queue_getCapacity(hQueue));
	}

	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_insert_capacity_plus_one_number\n"
		"Did not operate correctly after overflowing capacity\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_insert_capacity_plus_one_number\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}


Status test_kekezhang_insert_one_number(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [100]
	int val = 100;
	if (queue_enqueue(hQueue, val) == Failure) {
		status = Failure;
		printf("Insert %d failed\n", val);
	}

	if (queue_getTotalItems(hQueue) != 1) {
		status = Failure;
		printf("Expected a size of %d but got %d\n", 1, queue_getTotalItems(hQueue));
	}

	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_insert_one_number\n"
		"Did not operate correctly after insert one value\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_insert_one_number\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_check_front_item_when_insert_less_than_cap_num(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3]
	int num = 4;
	for (int i = 0; i < num; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}	
	}

	if (getFrontItem(hQueue) != 0) {
		status = Failure;
		printf("Expect from item is %d but got %d\n", 0, getFrontItem(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_check_front_item_when_insert_less_than_cap_num\n"
		"Did not operate correctly when get front item\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_check_front_item_when_insert_less_than_cap_num\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_check_tail_item_when_insert_less_than_cap_num(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3]
	int num = 4;
	for (int i = 0; i < num; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}	
	}

	if (getTailItem(hQueue) != 3) {
		status = Failure;
		printf("Expect from item is %d but got %d\n", 3, getTailItem(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_check_tail_item_when_insert_less_than_cap_num\n"
		"Did not operate correctly when get tail item\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_check_tail_item_when_insert_less_than_cap_num\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_check_front_item_when_insert_more_than_cap_num(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3, 4, 5, 6, 7]
	int num = 8;
	for (int i = 0; i < num; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}	
	}

	if (getFrontItem(hQueue) != 0) {
		status = Failure;
		printItems(&hQueue);
		printf("Expect from item is %d but got %d\n", 0, getFrontItem(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_check_front_item_when_insert_more_than_cap_num\n"
		"Did not operate correctly when get front item after inserting more than cap numbers\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_check_front_item_when_insert_more_than_cap_num\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_check_tail_item_when_insert_more_than_cap_num(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3, 4, 5, 6, 7]
	int num = 8;
	for (int i = 0; i < num; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}	
	}

	if (getTailItem(hQueue) != 7) {
		status = Failure;
		printf("Expect from item is %d but got %d\n", 1, getTailItem(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_check_tail_item_when_insert_more_than_cap_num\n"
		"Did not operate correctly when get tail item after inserting more than cap numbers\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_check_tail_item_when_insert_more_than_cap_num\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_enqueue_cap_nums_and_then_dequeue_once(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3, 4, 5, 6]
	int num = 7;
	for (int i = 0; i < num; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}	
	}

	if (queue_dequeue(hQueue) == Failure) {
		status = Failure;
		printf("Dequeue failed\n");
	}	

	if (queue_getTotalItems(hQueue) != 6) {
		status = Failure;
		printf("Expect total num of item is %d but got %d\n", 6, getTailItem(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_enqueue_cap_nums_and_then_dequeue_once\n"
		"Did not operate correctly when insert cap times and dequeue once\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_enqueue_cap_nums_and_then_dequeue_once\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_once(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3, 4, 5, 6, 7]
	int num = 8;
	for (int i = 0; i < num; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}	
	}

	if (queue_dequeue(hQueue) == Failure) {
		status = Failure;
		printf("Dequeue failed\n");
	}	

	if (queue_getTotalItems(hQueue) != 7) {
		status = Failure;
		printf("Expect total num of item is %d but got %d\n", 7, queue_getTotalItems(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_once\n"
		"Did not operate correctly when insert cap plus one times and dequeue once\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_once\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}


Status test_kekezhang_enqueue_cap_nums_and_then_dequeue_cap_times(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3, 4, 5, 6]
	int num = 7;
	for (int i = 0; i < num; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}	
	}
	for (int i = 0; i < num; i++) {
		if (queue_dequeue(hQueue) == Failure) {
			status = Failure;
			printf("Dequeue failed\n");
		}
	}

	
	if (queue_getTotalItems(hQueue) != 0) {
		status = Failure;
		printf("Expect total num of item is %d but got %d\n", 0, queue_getTotalItems(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_enqueue_cap_nums_and_then_dequeue_cap_times\n"
		"Did not operate correctly when insert cap times and dequeue cap times\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_enqueue_cap_nums_and_then_dequeue_cap_times\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_cap_times(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3, 4, 5, 6, 7]
	for (int i = 0; i < 8; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}	
	}
	for (int i = 0; i < 7; i++) {
		if (queue_dequeue(hQueue) == Failure) {
			status = Failure;
			printf("Dequeue failed\n");
		}
	}

	if (queue_getTotalItems(hQueue) != 1) {
		status = Failure;
		printf("Expect total num of item is %d but got %d\n", 1, queue_getTotalItems(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_cap_times\n"
		"Did not operate correctly when insert cap plus one times and dequeue cap times\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_cap_times\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_enqueue_and_dequeue_cap_times_alternately(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	// insert [0, 1, 2, 3, 4, 5, 6]
	for (int i = 0; i < 7; i++) {
		if (queue_enqueue(hQueue, i) == Failure) {
			status = Failure;
			printf("Insert %d failed\n", i);
		}
		if (queue_dequeue(hQueue) == Failure) {
			status = Failure;
			printf("Dequeue failed\n");
		}	
	}
	
	if (queue_getTotalItems(hQueue) != 0) {
		status = Failure;
		printf("Expect total num of item is %d but got %d\n", 0, queue_getTotalItems(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_enqueue_and_dequeue_cap_times_alternately\n"
		"Did not operate correctly when insert cap and dequeue alternately\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_enqueue_and_dequeue_cap_times_alternately\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}

Status test_kekezhang_enqueue_once_and_dequeue_twice(char* buffer, int length){
	QUEUE hQueue = NULL;
	hQueue = queue_init_default();

	Status status = Success;
	
	if (queue_enqueue(hQueue, 1) == Failure) {
		status = Failure;
		printf("Insert %d failed\n", 1);
	}
	if (queue_dequeue(hQueue) == Failure) {
		status = Failure;
		printf("Dequeue failed\n");
	}	

	if (queue_dequeue(hQueue) == Success) {
		status = Failure;
		printf("Dequeue should be failed but sucess\n");
	}	
	
	if (queue_getTotalItems(hQueue) != 0) {
		status = Failure;
		printf("Expect total num of item is %d but got %d\n", 0, queue_getTotalItems(hQueue));
	}
	
	if (status == Failure) 
	{
		strncpy(buffer, "test_kekezhang_enqueue_once_and_dequeue_twice\n"
		"Did not operate correctly when insert once and dequeue twice\n", length);
	} 
	else
	{
		strncpy(buffer, "test_kekezhang_enqueue_once_and_dequeue_twice\n",length);
	}
	queue_destroy(&hQueue);
	return status;
}
