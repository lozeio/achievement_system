main: main.cpp login.cpp student.cpp students.cpp
	g++ $^ -o $@

Debug: main.cpp login.cpp student.cpp students.cpp
	g++ $^ -o $@ -g