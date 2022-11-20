hello: window.cpp
	g++ -c window.cpp
	g++ window.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm *.o