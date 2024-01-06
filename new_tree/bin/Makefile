APP_NAME = learnopengl
BUILD_DIR = ./
CPP_FILES = ../src/*.cpp
C_FILES = ../src/*.c

APP_DEFINES:=
APP_INCLUDES := -I../include/ -framework Opengl -framework Cocoa -framework IOKit
APP_LINKERS := -L../lib -lglfw3

build: 
	c++ $(CPP_FILES) $(C_FILES) -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES)  $(APP_LINKERS)
	./$(BUILD_DIR)/$(APP_NAME)
