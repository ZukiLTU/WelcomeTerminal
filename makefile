COMPILER = gcc

SOURCE = WelcomeTerminal.c
TARGET = WelcomeTerminal

$(TARGET):
	$(COMPILER) $(SOURCE) -o $(TARGET)

install: $(TARGET)
	echo "~/.WelcomeTerminal/$(TARGET) $(USERNAME)" >> ~/.bashrc
	chmod 777 greeting
	chmod 777 $(TARGET)

	./$(TARGET) $(USERNAME)

