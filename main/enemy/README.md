# Enemy

Código dos inimigos

## zombie

Este arquivo contêm as funções para a implementação do zumbi. Vale salientar que há mais de um método para a I.A. do zumbi.


```c
void initZombie();
```

- Função para a inicialização do zumbi

```c
void goAt(Vector2 point);
```

- Função para mover o zumbi até determinado ponto

```c
void setMovementByBacktracking(Vector2 zombie_pos, Vector2 player_pos, int map_input[450][800]);
```

- Faz a chamada da I.A. do zumbi para a perseguição do personagem por backtracking

```c
void backtracking(Vector2 **path, int *length, Vector2 player);
```

- Algoritmo de busca para o caminho até o personagem

```c
void whichDirect(Vector2 zombie_pos, Vector2 player_pos);
```

- Define as direções ortogonais na matriz de caminho de modo que force a busca pelo menor caminho

```c
void setMap(int a[450][800]);

```

- Importa a bitmap para o arquivo zumbi

```c
void append(Vector2 **path, int *length, Vector2 element);
```

- Metodo para à adição de elementos na lista de caminho 

```c
void pop(Vector2 **path, int *length);
```

- Remove o último elemento da lista

##### OBs.: Na main apenas chame ```void initZombie()``` e ```void setMovementByBacktracking(Vector2 zombie_pos, Vector2 player_pos, int map_input[450][800]);``` para a utilização do algoritmo por backtracking. 


