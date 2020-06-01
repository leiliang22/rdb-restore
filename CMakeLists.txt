project (rdb-restore)

set(INC_DIR ./)
#set(LINK_DIR ./rocksdb-master/)

include_directories(${INC_DIR})
#link_directories(${LINK_DIR})

aux_source_directory(. DIR_SRCS)
#add_subdirectory(rocksdb-master)

add_executable(rdb-restore ${DIR_SRCS})

#target_link_libraries(Demo rocksdb)
