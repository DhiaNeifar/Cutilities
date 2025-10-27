enable_testing()

add_executable(test_linkedList test_linkedList.c)
target_link_libraries(test_linkedList PRIVATE utilities)
add_test(NAME LinkedListTests COMMAND test_linkedList)
