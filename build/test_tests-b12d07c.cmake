add_test( [==[test for test case]==] /workspaces/CS225/Final-project/build/test [==[test for test case]==]  )
set_tests_properties( [==[test for test case]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225/Final-project/build)
add_test( [==[test read data from file]==] /workspaces/CS225/Final-project/build/test [==[test read data from file]==]  )
set_tests_properties( [==[test read data from file]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225/Final-project/build)
set( test_TESTS [==[test for test case]==] [==[test read data from file]==])
