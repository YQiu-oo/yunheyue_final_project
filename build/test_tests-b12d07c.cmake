add_test( [==[read_route_file Test1]==] [==[/workspaces/CS 225 - Final Project/yunheyue_final_project/build/test]==] [==[read_route_file Test1]==]  )
set_tests_properties( [==[read_route_file Test1]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225 - Final Project/yunheyue_final_project/build]==])
add_test( [==[read_route_file Test2]==] [==[/workspaces/CS 225 - Final Project/yunheyue_final_project/build/test]==] [==[read_route_file Test2]==]  )
set_tests_properties( [==[read_route_file Test2]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225 - Final Project/yunheyue_final_project/build]==])
add_test( [==[read_airport_file Test1]==] [==[/workspaces/CS 225 - Final Project/yunheyue_final_project/build/test]==] [==[read_airport_file Test1]==]  )
set_tests_properties( [==[read_airport_file Test1]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225 - Final Project/yunheyue_final_project/build]==])
add_test( [==[read_airport_file Test2]==] [==[/workspaces/CS 225 - Final Project/yunheyue_final_project/build/test]==] [==[read_airport_file Test2]==]  )
set_tests_properties( [==[read_airport_file Test2]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/CS 225 - Final Project/yunheyue_final_project/build]==])
set( test_TESTS [==[read_route_file Test1]==] [==[read_route_file Test2]==] [==[read_airport_file Test1]==] [==[read_airport_file Test2]==])
