build : 
	@echo \\033[33mCOMPILATION STARTED..\\033[0m""

	cd Entity/ && make
	cd Component/ && make
	cd EntityMatcher/ && make
	cd Filter/ && make
	cd Systems/ && make

	@echo \\033[32mCOMPILATION FINISHED\\033[0m""

example :
	@echo \\033[33mCOMPILATION OF EXAMPLES STARTED..\\033[0m""

	cd Examples/ && make

	@echo \\033[32mCOMPILATION FINISHED\\033[0m""


clean: 
	@echo \\033[31mCLEANING STARTED..\\033[0m""

	cd Entity/ && make clean
	cd Component/ && make clean
	cd EntityMatcher/ && make clean
	cd Filter/ && make clean
	cd Systems/ && make clean
	cd Examples/ && make clean

	@echo \\033[31mCLEANING FINISHED\\033[0m""