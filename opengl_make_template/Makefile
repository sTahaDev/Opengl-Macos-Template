APP_NAME = openglApp
BUILD_DIR = ./bin
C_FILES = ./src/*.cpp

APP_DEFINES:=
APP_INCLUDES := -I./include -framework Opengl -framework Cocoa -framework IOKit
APP_LINKERS := -L./lib -lglfw3

build: 
	clang -std=c++17 $(C_FILES) -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES) $(APP_LINKERS)
	./bin/$(APP_NAME)
