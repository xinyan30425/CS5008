#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "queue.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);

Status test_get_totalItems_on_init_default_returns_0(char* buffer, int length);

Status test_xinyanliu_init_default_creates_empty_queue(char* buffer, int length);

Status test_xinyanliu_dequeue_on_empty_queue_returns_Failure(char* buffer, int length);

Status test_xinyanliu_dequeue_empty_queue(char* buffer, int length);

Status test_xinyanliu_destory_sets_handle_to_NULL(char* buffer, int length);

Status test_xinyanliu_queue_destroy(char* buffer, int length);

Status test_xinyanliu_printFrontItem(char* buffer, int length);

Status test_xinyanliu_print_queue_indices(char* buffer, int length);

Status test_kekezhang_just_reach_full_capacity(char* buffer, int length);

Status test_kekezhang_insert_capacity_plus_one_number(char* buffer, int length);

Status test_kekezhang_insert_one_number(char* buffer, int length);

Status test_kekezhang_check_front_item_when_insert_less_than_cap_num(char* buffer, int length);

Status test_kekezhang_check_tail_item_when_insert_less_than_cap_num(char* buffer, int length);

Status test_kekezhang_check_front_item_when_insert_more_than_cap_num(char* buffer, int length);

Status test_kekezhang_check_tail_item_when_insert_more_than_cap_num(char* buffer, int length);

Status test_kekezhang_enqueue_cap_nums_and_then_dequeue_once(char* buffer, int length);

Status test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_once(char* buffer, int length);

Status test_kekezhang_enqueue_cap_nums_and_then_dequeue_cap_times(char* buffer, int length);

Status test_kekezhang_enqueue_cap_plus_one_nums_and_then_dequeue_cap_times(char* buffer, int length);

Status test_kekezhang_enqueue_and_dequeue_cap_times_alternately(char* buffer, int length);

Status test_kekezhang_enqueue_once_and_dequeue_twice(char* buffer, int length);







#endif