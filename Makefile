FLAGS := -g -w

vai:
	g++ -c cod/QU.c $(FLAGS)
	g++ -c cod/grafo.c $(FLAGS)
	g++ -c cod/tratamento.c $(FLAGS)
	g++ -c main.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o