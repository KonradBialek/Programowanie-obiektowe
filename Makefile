#
#  To sa opcje dla kompilacji
#
TASKNO=7
APP=sterowanie-dronem
TASKDIR=${HOME}/kpo/z${TASKNO}
CXXFLAGS=-g -Iinc -W -Wall -pedantic -std=c++0x

__start__: ${APP}
	rm -f core.* core; ./${APP}

${APP}: obj obj/main.o obj/Scena.o obj/Dron.o obj/Prostopadloscian.o obj/Graniastoslup6.o obj/Graniastoslup_prosty.o\
	       obj/lacze_do_gnuplota.o obj/ObiektSceny.o obj/PrzeszkodaPr.o obj/Sciezka.o obj/FabrykaObiektow.o
	g++ -Wall -pedantic -std=c++0x -o ${APP} obj/main.o obj/Scena.o obj/Dron.o obj/Prostopadloscian.o\
	    obj/Graniastoslup6.o obj/Graniastoslup_prosty.o obj/lacze_do_gnuplota.o obj/ObiektSceny.o obj/PrzeszkodaPr.o\
	    obj/Sciezka.o obj/FabrykaObiektow.o

obj:
	mkdir obj

dat:
	mkdir dat

ext: ./${APP}_rozszerzony
	rm -f core.* core; echo "2i 1+3.1i 2 ? / + ?" | ./${APP}_rozszerzony

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Scena.hh inc/Dron.hh inc/Prostopadloscian.hh obj/Graniastoslup6.o\
	    inc/Graniastoslup_prosty.hh inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh\
	    inc/Wektor.hh inc/lacze_do_gnuplota.hh inc/PrzeszkodaPr.hh inc/FabrykaObiektow.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/PrzeszkodaPr.o: src/PrzeszkodaPr.cpp inc/PrzeszkodaPr.hh inc/Prostopadloscian.hh 
	g++ -c ${CXXFLAGS} -o obj/PrzeszkodaPr.o src/PrzeszkodaPr.cpp

obj/FabrykaObiektow.o: src/FabrykaObiektow.cpp inc/FabrykaObiektow.hh inc/Prostopadloscian.hh inc/Dron.hh\
	               inc/PrzeszkodaPr.hh
	g++ -c ${CXXFLAGS} -o obj/FabrykaObiektow.o src/FabrykaObiektow.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh inc/Prostopadloscian.hh inc/Graniastoslup6.hh
	g++ -c ${CXXFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh inc/Dron.hh inc/lacze_do_gnuplota.hh inc/ObiektSceny.hh inc/PrzeszkodaPr.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh\
	  inc/Wektor3D.hh inc/Wektor.hh inc/Graniastoslup_prosty.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Graniastoslup6.o: src/Graniastoslup6.cpp inc/Graniastoslup6.hh\
	  inc/Wektor3D.hh inc/Wektor.hh inc/Graniastoslup_prosty.hh
	g++ -c ${CXXFLAGS} -o obj/Graniastoslup6.o src/Graniastoslup6.cpp

obj/Sciezka.o: src/Sciezka.cpp inc/Sciezka.hh\
	  inc/Wektor3D.hh inc/Wektor.hh inc/Graniastoslup_prosty.hh
	g++ -c ${CXXFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/Graniastoslup_prosty.o: src/Graniastoslup_prosty.cpp inc/Graniastoslup_prosty.hh\
	  inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Graniastoslup_prosty.o src/Graniastoslup_prosty.cpp

obj/ObiektSceny.o: src/ObiektSceny.cpp inc/ObiektSceny.hh
	g++ -c ${CXXFLAGS} -o obj/ObiektSceny.o src/ObiektSceny.cpp

#obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh inc/Wektor.hh
#	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

#obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh
#	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

clean:
	rm -f obj/*.o ${APP}
	rm -f obj/* ${APP} core.* core

${TASKDIR}:
	mkdir -p ${TASKDIR}/bin.diablo ${TASKDIR}/bin.panamint

__TARGET__:
	if [ ! "${HOST}" = "diablo" ] && [ ! "${HOST}" = "panamint" ]; then exit 1; fi

export: __TARGET__ ./${APP}  ./${APP}_rozszerzony ${TASKDIR}
	mv ${APP} ${APP}_rozszerzony ${HOME}/edu/po/zad/z${TASKNO}/bin.${HOST}/

help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make ext    - tworzenie i uruchomienie aplikacji w wersji rozszerzonej"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo

