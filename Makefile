ObjDir = bin/objects
HeadersDir = src/Headers
ClassesDir = src/Classes

create:
	-if not exist bin\objects mkdir bin\objects
	-if not exist src\DataBase mkdir src\DataBase
	-if not exist src\DataBase\"Flight_Records.txt" type NULL > src\DataBase\Flight_Records.txt
	-if not exist src\DataBase\"User_Records.txt" type NULL > src\DataBase\User_Records.txt


Airport = $(HeadersDir)/Airport.cpp src/Airport.h
Date = $(Airport) $(HeadersDir)/Date.cpp $(ClassesDir)/Date.h
Route = $(HeadersDir)/Route.cpp $(ClassesDir)/Route.h
FlightInfo = $(Airport) $(Route) $(Date) $(HeadersDir)/FlightInfo.cpp $(ClassesDir)/FlightInfo.h
UserInfo = $(Airport) $(Route) $(Date) $(HeadersDir)/UserInfo.cpp $(ClassesDir)/UserInfo.h
Counter = $(FlightInfo) $(UserInfo) $(HeadersDir)/Counter.cpp $(ClassesDir)/Counter.h
Recorder = $(HeadersDir)/Recorder.cpp $(ClassesDir)/Recorder.h $(HeadersDir)/FlightData.cpp $(ClassesDir)/FlightData.h $(HeadersDir)/UserData.cpp $(ClassesDir)/UserData.h $(Counter) $(FlightInfo) $(UserInfo)
FlightData = $(Airport) $(Recorder)
UserData = $(Airport) $(Recorder)
PathFinder = $(Airport) $(FlightData) $(HeadersDir)/PathFinder.cpp $(ClassesDir)/PathFinder.h
Menu = $(Airport) $(PathFinder) $(Recorder) $(HeadersDir)/Menu_func.cpp $(ClassesDir)/Menu_func.h
Main = $(Airport) $(Menu)
OBJECTS := $(ObjDir)/Airport.o $(ObjDir)/Counter.o $(ObjDir)/Date.o $(ObjDir)/FlightData.o $(ObjDir)/FlightInfo.o $(ObjDir)/main.o $(ObjDir)/Menu_func.o $(ObjDir)/PathFinder.o $(ObjDir)/Recorder.o $(ObjDir)/Route.o $(ObjDir)/UserData.o $(ObjDir)/UserInfo.o
Flags = -std=c++0x

clean:
	-del /S/Q bin
	-del /S/Q bin\objects
	-del /S/Q src\DataBase

all: create $(OBJECTS)
	$(CXX) $(Flags) -o bin/Airport $(OBJECTS)

$(ObjDir)/main.o: $(Main)
	$(CXX) $(Flags) -c main.cpp -o $(ObjDir)/main.o

$(ObjDir)/Airport.o: $(Airport)
	$(CXX) $(Flags) -c $(HeadersDir)/Airport.cpp -o $(ObjDir)/Airport.o

$(ObjDir)/Counter.o: $(Airport)
	$(CXX) $(Flags) -c $(HeadersDir)/Counter.cpp -o $(ObjDir)/Counter.o

$(ObjDir)/Date.o: $(Date)
	$(CXX) $(Flags) -c $(HeadersDir)/Date.cpp -o $(ObjDir)/Date.o

$(ObjDir)/FlightData.o: $(FlightData)
	$(CXX) $(Flags) -c $(HeadersDir)/FlightData.cpp -o $(ObjDir)/FlightData.o

$(ObjDir)/FlightInfo.o: $(FlightInfo)
	$(CXX) $(Flags) -c $(HeadersDir)/FlightInfo.cpp -o $(ObjDir)/FlightInfo.o

$(ObjDir)/Menu_func.o: $(Menu)
	$(CXX) $(Flags) -c $(HeadersDir)/Menu_func.cpp -o $(ObjDir)/Menu_func.o

$(ObjDir)/PathFinder.o: $(PathFinder)
	$(CXX) $(Flags) -c $(HeadersDir)/PathFinder.cpp -o $(ObjDir)/PathFinder.o

$(ObjDir)/Recorder.o: $(Recorder)
	$(CXX) $(Flags) -c $(HeadersDir)/Recorder.cpp -o $(ObjDir)/Recorder.o

$(ObjDir)/Route.o: $(Route)
	$(CXX) $(Flags) -c $(HeadersDir)/Route.cpp -o $(ObjDir)/Route.o

$(ObjDir)/UserData.o: $(UserData)
	$(CXX) $(Flags) -c $(HeadersDir)/UserData.cpp -o $(ObjDir)/UserData.o

$(ObjDir)/UserInfo.o: $(UserInfo)
	$(CXX) $(Flags) -c $(HeadersDir)/UserInfo.cpp -o $(ObjDir)/UserInfo.o
