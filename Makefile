build:
	g++ -w -std=c++14 -Wfatal-errors \
	./src/*.cpp \
	./src/*.h   \
	-o game.exe \
	-I"./lib/lua" \
	-L"./lib/lua" \
	-I"./lib/glm" \
	-L"./lib/glm" \
	-I"C:\libSDL\SDL2\include" \
	-L"C:\libSDL\SDL2\lib" \
	-llua54 \
	-lmingw32 \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer

clean:
	rm ./game.exe

run:
	./game.exe
