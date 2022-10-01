# Scene

Implementação dos cenários

## background

Background da primeira fase

```c
void initScene();
```

- Função para a inicialização da cena

```c
void drawScene();
```

- Função para o desenho da cena

```c
void closeScene();
```

- Função para fechar a cena

```c
int hasAColision(Vector2 object);
```

- Função para verificar se há colisão na cena

```c
void loadImageColision(char *file_name);
```

- Carrega uma bitmap _.txt_ que serve de base para a função anterior 

