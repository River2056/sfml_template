exe_name := task

all: run

clean:
	if [ -d "./build/_deps" ]; then mv ./build/_deps ./; fi
	rm -rf ./build
	mkdir build
	if [ -d "./_deps" ]; then mv ./_deps ./build; fi

generate: clean
	cmake -S . -B ./build -GNinja
	cmake --build ./build
	mv ./build/compile_commands.json .

run: generate
	./build/app/$(exe_name).exe
