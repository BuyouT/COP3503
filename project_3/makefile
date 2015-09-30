all: project_3
	
project_3: COP3503su14_Proj3_RicardoRmenu.o COP3503su14_Proj3_RicardoR.o
	g++ -o project_3 COP3503su14_Proj3_RicardoRmenu.o COP3503su14_Proj3_RicardoR.o tinyxml2.o

COP3503su14_Proj3_RicardoRmenu.o: COP3503su14_Proj3_RicardoRmenu.cpp COP3503su14_Proj3_RicardoR.h
	g++ -c COP3503su14_Proj3_RicardoRmenu.cpp 

COP3503su14_Proj3_RicardoR.o: COP3503su14_Proj3_RicardoR.cpp COP3503su14_Proj3_RicardoR.h
	g++ -c COP3503su14_Proj3_RicardoR.cpp


clean:
	rm -rf *.o
	rm -rf project_3
