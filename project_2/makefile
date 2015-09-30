all: project_2
	

project_2: COP3503su14_Proj2_RicardoRmenu.o COP3503su14_Proj2_RicardoR.o
	g++ -o project_2 COP3503su14_Proj2_RicardoRmenu.o COP3503su14_Proj2_RicardoR.o

COP3503su14_Proj2_RicardoRmenu.o: COP3503su14_Proj2_RicardoRmenu.cpp COP3503su14_Proj2_RicardoR.h
	g++ -c COP3503su14_Proj2_RicardoRmenu.cpp

COP3503su14_Proj2_RicardoR.o: COP3503su14_Proj2_RicardoR.cpp COP3503su14_Proj2_RicardoR.h
	g++ -c COP3503su14_Proj2_RicardoR.cpp

clean:
	rm -rf *.o
	rm -rf project_2
