project(StructPattern)


#aux_source_directory(. single_file_examples)	
set(single_file_examples
	BridgePattern
AdapterPattern
DecoratorPattern
ProxyPattern
CompositePattern
FacadePattern
  )

foreach(example ${single_file_examples})
    add_executable(${example} "${example}.cpp")
    #target_link_libraries(${example} PRIVATE torrent-rasterbar)
endforeach(example)

#add_executable(client_test
#    client_test.cpp
#    print.cpp
#    torrent_view.cpp
#    session_view.cpp)
#target_link_libraries(client_test PRIVATE torrent-rasterbar)
