FLAGS := -g -w

vai:
	g++ -c cod/QU.c $(FLAGS)
	g++ -c cod/arvore.c $(FLAGS)
	g++ -c cod/kruskal.c $(FLAGS)
	g++ -c main.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o