cmake_minimum_required(VERSION 2.6)
project(FIRSTENGINE)

add_definitions(-DSDL_MAIN_HANDLED)


include_directories(
src
)

if(MSVC)
	include_directories(
		${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_64/include)
	link_directories(
		${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86_64/lib
	)
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s DISABLE_EXCEPTION_CATCHING=0")
endif()

add_library(fenet
src/fenet/Exception.cpp
src/fenet/IPEndPoint.cpp
src/fenet/Network.cpp
src/fenet/Packet.cpp
src/fenet/Socket.cpp
src/fenet/SslSocket.cpp

src/fenet/Constants.h
src/fenet/Exception.h
src/fenet/Fenet.h
src/fenet/FenetResult.h
src/fenet/IPVersion.h
src/fenet/IPEndPoint.h
src/fenet/Network.h
src/fenet/Packet.h
src/fenet/Socket.h
src/fenet/SocketHandle.h
src/fenet/SocketOptions.h
src/fenet/SslSocket.h
)

if(MSVC OR MINGW)
	target_link_libraries(fenet Ws2_32.lib libssl.lib libcrypto.lib)
endif()

add_executable(demoClient
src/demoClient/main.cpp
)
add_executable(demoServer
src/demoServer/main.cpp
)

target_link_libraries(demoClient fenet)
target_link_libraries(demoServer fenet)



