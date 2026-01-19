# 🚢 Batalha Naval - Desafio Completo

Bem-vindo ao desafio **Batalha Naval**! Este projeto desenvolve um jogo simulador de Batalha Naval em C, utilizando matrizes para representar tabuleiros e habilidades especiais. O projeto é dividido em três níveis progressivos de complexidade.

---

## 📋 Índice
- [Funcionamento Geral](#funcionamento-geral)
- [Compilação e Execução](#compilação-e-execução)
- [Nível Novato](#-nível-novato)
- [Nível Aventureiro](#-nível-aventureiro)
- [Nível Mestre](#-nível-mestre-atual)
- [Estrutura do Código](#estrutura-do-código)

---

## 🎮 Funcionamento Geral

O jogo de Batalha Naval é um clássico de estratégia onde:

1. **Objetivo:** Acertar todos os navios inimigos antes que seus navios sejam destruídos
2. **Mecânica:** Lançar ataques em coordenadas do tabuleiro para descobrir a localização dos navios
3. **Progressão:** Os níveis aumentam em complexidade, adicionando mais navios e habilidades especiais

---

## 🔧 Compilação e Execução

### Pré-requisitos
- Compilador GCC instalado
- Terminal ou Prompt de Comando

### Compilar
```bash
gcc batalhaNaval.c -o batalhaNaval
```

### Executar
```bash
./batalhaNaval
```

---

## 🏅 Nível Novato

**Status:** Desenvolvimento esperado  
**Objetivo:** Implementar posicionamento básico de navios

### 🚩 Funcionalidades Esperadas:

| Funcionalidade | Descrição |
|---|---|
| **Tabuleiro** | Matriz 5x5 |
| **Quantidade de Navios** | 2 navios (1 horizontal, 1 vertical) |
| **Representação** | 0 = posição vazia, 3 = posição com navio |
| **Entrada** | Coordenadas inseridas manualmente no código |
| **Saída** | Coordenadas dos navios exibidas no console |

### 📝 Exemplo de Funcionamento:

```
Navio 1 (Horizontal): (0,1) (0,2) (0,3)
Navio 2 (Vertical):   (2,1) (3,1) (4,1)
```

### 💡 Dica de Implementação:
Use dois vetores bidimensionais para armazenar as coordenadas dos navios e um loop para exibi-las.

---

## 🏅 Nível Aventureiro

**Status:** Desenvolvimento esperado  
**Objetivo:** Expandir tabuleiro e adicionar posicionamentos diagonais

### 🆕 Novas Características:

| Característica | Descrição |
|---|---|
| **Tabuleiro** | Matriz 10x10 |
| **Quantidade de Navios** | 4 navios (2 horizontais, 2 na diagonal) |
| **Padrões de Posicionamento** | Horizontal, Vertical e Diagonal |
| **Representação** | 0 = vazio, 1 = navio, 2 = acertado, 3 = água |
| **Funcionalidade Nova** | Exibição completa do tabuleiro |

### 📝 Exemplo de Matriz:

```
Tabuleiro 10x10:
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 0 0 0 0 0  (Navio Horizontal)
0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0  (Navio Vertical)
0 0 0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0  (Navio Diagonal)
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0
```

### 💡 Dica de Implementação:
Crie funções para posicionar navios em diferentes direções e use loops aninhados para exibir a matriz.

---

## 🏅 Nível Mestre (ATUAL)

**Status:** ✅ Implementado  
**Objetivo:** Adicionar habilidades especiais com padrões geométricos

### 🎯 Funcionalidades Implementadas:

O código atual implementa **3 habilidades especiais** representadas por matrizes 5x5:

#### 1️⃣ **Habilidade CONE**
Expande em forma de cone de cima para baixo.

```
Padrão:
0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
```

**Lógica:**
```c
if (j >= (TAM/2 - i) && j <= (TAM/2 + i)) {
    cone[i][j] = 1;
}
```
- Começa com 1 célula no topo
- Expande 2 células por linha
- Afeta a metade inferior da matriz

---

#### 2️⃣ **Habilidade CRUZ**
Forma um padrão de linha horizontal e vertical que se cruzam.

```
Padrão:
0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
```

**Lógica:**
```c
if (i == TAM/2 || j == TAM/2) {
    cruz[i][j] = 1;
}
```
- Afeta toda a linha central (i = 2)
- Afeta toda a coluna central (j = 2)
- Total: 9 células em formato de cruz

---

#### 3️⃣ **Habilidade OCTAEDRO (Losango)**
Cria um padrão em forma de losango.

```
Padrão:
0 0 1 0 0
0 1 1 1 0
0 0 1 0 0
```

**Lógica:**
```c
if ((abs(i - TAM/2) + abs(j - TAM/2)) <= TAM/2) {
    octaedro[i][j] = 1;
}
```
- Usa distância Manhattan para formar losango
- Células afetadas: máximo 9
- Centro da matriz é sempre atingido

---

### 📊 Saída do Programa:

```
HABILIDADE EM CONE:

0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0

HABILIDADE EM CRUZ:

0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0

HABILIDADE EM OCTAEDRO:

0 0 1 0 0
0 1 1 1 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
```

---

## 📂 Estrutura do Código

```
batalhaNaval.c
├── #include <stdio.h>        // Entrada/Saída padrão
├── #define TAM 5              // Constante para tamanho da matriz
│
├── void imprimirMatriz()      // Função para exibir matriz 5x5
│
└── int main()                 // Função principal
    ├── Declaração de 3 matrizes (cone, cruz, octaedro)
    ├── Loop para preencher CONE
    ├── Loop para preencher CRUZ
    ├── Loop para preencher OCTAEDRO
    └── Exibição das 3 matrizes
```

### 🔑 Componentes Principais:

| Componente | Tipo | Descrição |
|---|---|---|
| `TAM` | Constante | Define dimensão 5x5 das matrizes |
| `cone[][]` | Matriz | Armazena padrão de cone (1 = afetado, 0 = não afetado) |
| `cruz[][]` | Matriz | Armazena padrão de cruz |
| `octaedro[][]` | Matriz | Armazena padrão de losango |
| `imprimirMatriz()` | Função | Exibe matriz formatada linha por linha |

---

## 🎓 Conceitos-Chave Utilizados

### Matrizes Bidimensionais
```c
int matriz[5][5];  // Matriz 5x5
matriz[i][j] = 1;  // Acesso a elemento
```

### Loops Aninhados
```c
for (i = 0; i < TAM; i++) {        // Loop de linhas
    for (j = 0; j < TAM; j++) {    // Loop de colunas
        // Verificação e preenchimento
    }
}
```

### Condições Lógicas
```c
if (j >= (TAM/2 - i) && j <= (TAM/2 + i)) {
    // Condição atende se está dentro do intervalo
}
```

### Função abs() (Valor Absoluto)
```c
abs(i - TAM/2)  // Distância entre i e o centro
```

---

## 📌 Próximos Passos para Expansão

1. **Integrar Navios:** Combinar posicionamento de navios com habilidades
2. **Sistema de Ataque:** Implementar função que verifica acerto/erro
3. **Interatividade:** Adicionar entrada do usuário para ataques
4. **IA Inimiga:** Criar lógica para ataques automáticos do computador
5. **Validação:** Verificar limites de coordenadas

---

## 📝 Requisitos Não-Funcionais

- ✅ **Performance:** Execução instantânea sem atrasos
- ✅ **Documentação:** Código bem comentado
- ✅ **Manutenibilidade:** Estrutura clara e organizada
- ✅ **Modularidade:** Funções reutilizáveis

---

## 🏆 Desafios Adicionais

- Expandir matrizes para 10x10 ou maior
- Criar 5+ padrões diferentes de habilidades
- Implementar sistema completo de jogo com turnos
- Adicionar salvamento de partidas
- Criar interface gráfica (COM GTK ou SDL)

---

**Desenvolvido por:** Equipe de Ensino - MateCheck  
**Data:** Janeiro 2025  
**Versão:** 1.0 (Nível Mestre)






