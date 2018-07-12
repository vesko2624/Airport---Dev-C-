ObjDir = bin/Objects
HeadersDir = src/Headers
ClassesDir = src/Classes

OBJECTS = $(ObjDir)/Airport.o $(ObjDir)/Counter.o $(ObjDir)/Date.o $(ObjDir)/FlightData.o $(ObjDir)/FlightInfo.o $(ObjDir)/main.o $(ObjDir)/Menu_func.o $(ObjDir)/PathFinder.o $(ObjDir)/Recorder.o $(ObjDir)/Route.o $(ObjDir)/UserData.o $(ObjDir)/UserInfo.o
clean:
	-rm -f $(OBJECTS)

all: $(OBJECTS)
	$(CXX) -o bin/Airport $(OBJECTS)

$(ObjDir)/main.o: main.cpp $(ClassesDir)/Menu_func.h
	$(CXX) -c main.cpp -o $(ObjDir)/main.o

$(ObjDir)/Airport.o: src/Airport.h $(HeadersDir)/Airport.cpp
	$(CXX) -c $(HeadersDir)/Airport.cpp -o $(ObjDir)/Airport.o

$(ObjDir)/Counter.o: $(ClassesDir)/Counter.h $(ClassesDir)/Counter.h $(ClassesDir)/FlightInfo.h $(ClassesDir)/UserInfo.h
	$(CXX) -c $(HeadersDir)/Counter.cpp -o $(ObjDir)/Counter.o

$(ObjDir)/Date.o: src/Airport.h $(HeadersDir)/Airport.cpp $(ClassesDir)/Date.h $(HeadersDir)/Date.cpp
	$(CXX) -c $(HeadersDir)/Date.cpp -o $(ObjDir)/Date.o

$(ObjDir)/FlightData.o: src/Airport.h $(HeadersDir)/Airport.cpp $(ClassesDir)/FlightData.h $(HeadersDir)/FlightData.cpp $(ClassesDir)/Counter.h $(HeadersDir)/Counter.cpp $(ClassesDir)/FlightInfo.h $(HeadersDir)/FlightInfo.cpp
	$(CXX) -c $(HeadersDir)/FlightData.cpp -o $(ObjDir)/FlightData.o

$(ObjDir)/FlightInfo.o: src/Airport.h $(HeadersDir)/Airport.cpp $(ClassesDir)/FlightInfo.h $(HeadersDir)/FlightInfo.cpp $(ClassesDir)/Route.h $(HeadersDir)/Route.cpp $(ClassesDir)/Date.h $(HeadersDir)/Date.cpp
	$(CXX) -c $(HeadersDir)/FlightInfo.cpp -o $(ObjDir)/FlightInfo.o

$(ObjDir)/Menu_func.o: src/Airport.h $(HeadersDir)/Airport.cpp $(ClassesDir)/Menu_func.h $(HeadersDir)/Menu_func.cpp $(ClassesDir)/FlightData.h $(HeadersDir)/FlightData.cpp $(ClassesDir)/UserData.h $(HeadersDir)/UserData.cpp $(ClassesDir)/Recorder.h $(HeadersDir)/Recorder.cpp
	$(CXX) -c $(HeadersDir)/Menu_func.cpp -o $(ObjDir)/Menu_func.o

$(ObjDir)/PathFinder.o: $(ClassesDir)/PathFinder.h $(HeadersDir)/PathFinder.cpp src/Airport.h $(HeadersDir)/Airport.cpp $(ClassesDir)/FlightData.h $(HeadersDir)/FlightData.cpp
	$(CXX) -c $(HeadersDir)/PathFinder.cpp -o $(ObjDir)/PathFinder.o

$(ObjDir)/Recorder.o: $(ClassesDir)/Recorder.h $(HeadersDir)/Recorder.cpp $(ClassesDir)/FlightInfo.h $(HeadersDir)/FlightInfo.cpp $(ClassesDir)/UserInfo.h $(HeadersDir)/UserInfo.cpp
	$(CXX) -c $(HeadersDir)/Recorder.cpp -o $(ObjDir)/Recorder.o

$(ObjDir)/Route.o: $(ClassesDir)/Route.h $(HeadersDir)/Route.cpp
	$(CXX) -c $(HeadersDir)/Route.cpp -o $(ObjDir)/Route.o

$(ObjDir)/UserData.o: src/Airport.h $(HeadersDir)/Airport.cpp $(ClassesDir)/UserData.h $(HeadersDir)/UserData.cpp $(ClassesDir)/Counter.h $(HeadersDir)/Counter.cpp $(ClassesDir)/UserInfo.h $(HeadersDir)/UserInfo.cpp
	$(CXX) -c $(HeadersDir)/UserData.cpp -o $(ObjDir)/UserData.o

$(ObjDir)/UserInfo.o: src/Airport.h $(HeadersDir)/Airport.cpp $(ClassesDir)/UserInfo.h $(HeadersDir)/UserInfo.cpp $(ClassesDir)/Route.h $(HeadersDir)/Route.cpp $(ClassesDir)/Date.h $(HeadersDir)/Date.cpp
	$(CXX) -c $(HeadersDir)/UserInfo.cpp -o $(ObjDir)/UserInfo.o