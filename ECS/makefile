.SILENT: build clean example

build : 
	@echo \\033[33mCOMPILATION STARTED..\\033[0m""
	
	find . -maxdepth 1 -type d \( ! -name . \) -exec bash -c "cd '{}' && make" \;

	@echo \\033[32mCOMPILATION FINISHED\\033[0m""

example :
	@echo \\033[33mCOMPILATION OF EXAMPLES STARTED..\\033[0m""

	cd Examples/ && make

	@echo \\033[32mCOMPILATION FINISHED\\033[0m""

clean: 
	@echo \\033[31mCLEANING STARTED..\\033[0m""

	find . -maxdepth 1 -type d \( ! -name . \) -exec bash -c "cd '{}' && make clean” \;

	@echo \\033[31mCLEANING FINISHED\\033[0m""