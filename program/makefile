OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Conj_Individuos.o Conj_Rasgos.o Individuo.o Rasgo.o Par_Cromosomas.o
	     g++ -o program.exe program.o Conj_Individuos.o Conj_Rasgos.o Individuo.o Rasgo.o Par_Cromosomas.o

Conj_Individuos.o:  Conj_Individuos.cc Conj_Individuos.hh
	      g++ -c Conj_Individuos.cc $(OPCIONS)

Conj_Rasgos.o:  Conj_Rasgos.cc Conj_Rasgos.hh
	      g++ -c Conj_Rasgos.cc $(OPCIONS)

Individuo.o:  Individuo.cc Individuo.hh
	      g++ -c Individuo.cc $(OPCIONS)

Rasgo.o:  Rasgo.cc Rasgo.hh
	      g++ -c Rasgo.cc $(OPCIONS)

Par_Cromosomas.o:  Par_Cromosomas.cc Par_Cromosomas.hh
	      g++ -c Par_Cromosomas.cc $(OPCIONS)

program.o: program.cc
	   g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe

#tar -cvf program.tar *.cc *.hh MakeFile
