cmake_minimum_required(VERSION 3.6)
project(Ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp src/VehicleFactory.cpp src/VehicleFactory.h src/Point.cpp src/Point.h src/Vertex.cpp src/Vertex.h
        src/Graph.cpp src/Graph.h src/Grid.cpp src/Grid.h src/Bfs.cpp src/Bfs.h src/Driver.cpp
        src/Driver.h src/Vehicle.cpp src/Vehicle.h src/LuxuryVehicle.cpp src/LuxuryVehicle.h
        src/StandardVehicle.cpp src/StandardVehicle.h src/IObserver.h src/ISubject.h src/MainFlow.cpp
        src/MainFlow.h src/Passenger.cpp src/Passenger.h
        src/Taxi.cpp src/Taxi.h src/TaxiCenter.cpp src/TaxiCenter.h src/Trip.cpp src/Trip.h src/Menu.cpp src/Menu.h
        src/BaseParser.h src/StringParser.cpp src/StringParser.h test/VehicleTest.cpp test/BfsTest.cpp test/DriverTest.cpp
        test/GridTest.cpp test/MainFlowTest.cpp test/PassengerTest.cpp test/PointTest.cpp test/GridTest.cpp
        test/TaxiCenterTest.cpp test/TaxiTest.cpp test/TripTest.cpp test/VertexTest.cpp)
add_executable(Ex3 ${SOURCE_FILES})
target_link_libraries(Ex3 gtest gtest_main)