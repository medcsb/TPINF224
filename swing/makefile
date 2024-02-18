# Makefile for MainFrame.java

# Java compiler
JAVAC = javac

# Java runtime
JAVA = java

# Source files
SOURCES = MainFrame.java Client.java

# Class files
CLASSES = $(SOURCES:.java=.class)

# Default target
default: $(CLASSES)

# Compile Java source files
%.class: %.java
	$(JAVAC) $<

# Run the MainFrame class
run: $(CLASSES)
	$(JAVA) -cp .:.. swing.MainFrame

# Clean up generated files
clean:
	rm -f $(CLASSES)
