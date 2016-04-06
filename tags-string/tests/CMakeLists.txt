# add the executable
set(EXTRA_LIBS tags-string)
add_executable(Tests tests.cpp)
target_link_libraries(Tests  ${EXTRA_LIBS})
