add_test( [==[read_route_file Test1]==] [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build/test]==] [==[read_route_file Test1]==]  )
set_tests_properties( [==[read_route_file Test1]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build]==])
add_test( [==[read_route_file Test2]==] [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build/test]==] [==[read_route_file Test2]==]  )
set_tests_properties( [==[read_route_file Test2]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build]==])
add_test( [==[read_airport_file Test1]==] [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build/test]==] [==[read_airport_file Test1]==]  )
set_tests_properties( [==[read_airport_file Test1]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build]==])
add_test( [==[read_airport_file Test2]==] [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build/test]==] [==[read_airport_file Test2]==]  )
set_tests_properties( [==[read_airport_file Test2]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build]==])
add_test( [==[Matrix Test1]==] [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build/test]==] [==[Matrix Test1]==]  )
set_tests_properties( [==[Matrix Test1]==] PROPERTIES WORKING_DIRECTORY [==[/workspaces/final project/yunheyue_final_project-main/yunheyue_final_project/build]==])
set( test_TESTS [==[read_route_file Test1]==] [==[read_route_file Test2]==] [==[read_airport_file Test1]==] [==[read_airport_file Test2]==] [==[Matrix Test1]==])
