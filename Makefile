#A Flag -c diz para gerar o arquivo de objeto, o -o $@ diz para colocar a saída da compilação no arquivo nomeado no lado esquerdo do:, o $ <é o primeiro item na lista de dependências, e o A macro CFLAGS é definida como acima.
#Como simplificação final, vamos usar as macros especiais $@ e $ ^, que são os lados esquerdo e direito de :, respectivamente, para tornar a regra geral de compilação mais geral. 
#No exemplo abaixo, todos os arquivos de inclusão devem ser listados como parte da macro DEPS e todos os arquivos de objetos devem ser listados como parte da macro OBJ.

#Flags interessantes
#-Wall dispara todos os warnings em seu código
#-g necessário para avaliar o código do valgrind
#-lm obrigatorio caso utilize a biblioteca math.h

CC=gcc
CFLAGS=-I. -Wall -g  -lm
DEPS = arquivo.h grafo.h fila.h QU.h euclides.h
OBJ = cod/arquivo.o cod/grafo.o cod/QU.o cod/fila.o cod/euclides.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

trab1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
	rm -f cod/*.o
