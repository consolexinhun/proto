set(ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# add_library(test_protobuf ${ROOT}/test.pb.cc)
# add_executable(test_person ${ROOT}/test_person.cpp)
# target_link_libraries(test_person test_protobuf protobuf)



add_executable(test_person ${ROOT}/test_person.cpp ${ROOT}/test.pb.cc)
target_link_libraries(test_person protobuf)