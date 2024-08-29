#include <stdio.h>
#include "unit_tests.h"

int main(int argc, char* argv[]) {
	Status (*tests[])(char*, int) = {
		test_init_default_returns_nonNULL,
		test_get_totalItems_on_init_default_returns_0,
		test_xinyanliu_init_default_creates_empty_queue,
		test_xinyanliu_dequeue_on_empty_queue_returns_Failure,
		test_xinyanliu_dequeue_empty_queue,
		test_xinyanliu_destory_sets_handle_to_NULL,
		test_xinyanliu_printFrontItem,
		test_xinyanliu_print_queue_indices,
		test_xinyanliu_queue_destroy,
		test_kekezhang_just_reach_full_capacity,
		test_kekezhang_insert_capacity_plus_one_number,
		test_kekezhang_insert_one_number,
		test_kekezhang_check_front_item_when_insert_less_than_cap_num,
		test_kekezhang_check_tail_item_when_insert_less_than_cap_num,
		test_kekezhang_check_front_item_when_insert_more_than_cap_num,
		test_kekezhang_check_tail_item_when_insert_more_than_cap_num,
		test_kekezhang_enqueue_cap_nums_and_then_dequeue_once,
		test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_once,
		test_kekezhang_enqueue_cap_nums_and_then_dequeue_cap_times,
		test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_cap_times,
		test_kekezhang_enqueue_and_dequeue_cap_times_alternately,
		test_kekezhang_enqueue_once_and_dequeue_twice
	};
	
	int number_of_functions = sizeof(tests) / sizeof(tests[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;
	for(i=0; i<number_of_functions; i++){
		if(tests[i](buffer, 500) == Failure){
			printf("FAILED: Test %d failed miserably\n", i);
			printf("\t%s\n", buffer);
			failure_count++;
		}
		else{
		printf("PASS: Test %d passed\n", i);
		printf("\t%s\n", buffer);
		success_count++;
		}
	}
	printf("Total number of tests: %d\n", number_of_functions);
	printf("%d/%d Pass, %d/%d Failure\n", success_count,number_of_functions,failure_count,number_of_functions);
	return 0;
	
}



