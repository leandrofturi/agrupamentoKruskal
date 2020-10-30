# Agrupamento de espaçamento máximo utilizando uma árvore de peso mínimo

Implementação em linguagem C de um algoritmo de agrupamento, chamado de agrupamento de espaçamento máximo, utilizando uma árvore de peso mínimo e estruturas construı́das em sala de aula.

A respeito do problema, seja um conjunto U de N objetos x_1 , x_2 , ..., x_N , com i = 1, 2, ..., M e x i ∈ R^M . Para cada par, x_i e x_j , define-se uma distância d numérica (x_i, x_j), sendo d(x_i, x_j ) > 0 (positiva) e d(x_i , x_j) = d(x_j, x_i) (simétrica) e d(x_i, x_i) = 0. Deseja-se agrupar os objetos de U em k grupos. Denomina-se por k−grupo de U cada elemento duma qualquer partição de U em k conjuntos não vazios C 1 , C 2 , ..., C k tais que C 1 ∩ C 2 ∩ ... ∩ C k = ∅ e C 1 ∪ C 2 ∪ ... ∪ C k = U. O problema se resume em encontrar de forma eficiente a partição de U que conduza ao espaçamento máximo.

Se considerarmos cada ponto x_i como um vértice de um grafo completo, não direcionado e ponderado cujas arestas que ligam x_i a x_j são dadas por d(x_i, x_j), com d definido como a distância euclideana, pode-se solucionar o problema através da procura de uma árvore geradora mı́nima, seguida da remoção das k − 1 arestas de maior peso. Na busca da árvore geradora, utilizou-se o algoritmo de Kruskal, através das estruturas construı́das em sala de aula.

## Funcionamneto
make
./trab1 <nome_arquivo_entrada> k <nome_arquivo_saida>
