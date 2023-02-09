# Índice de Palavras em um Texto
Este programa é capaz de ler um arquivo de texto e imprimir, em ordem alfabética, todas as palavras com 3 ou mais caracteres, bem como a(s) linha(s) na(s) qual(is) elas aparecem no texto.

## Como funciona
- O arquivo é lido e todos os espaços em branco e sinais de pontuação são desconsiderados como separadores de palavras.
- Todas as letras maiúsculas são convertidas para minúsculas.
- Uma Árvore Patricia é implementada para armazenar as palavras e o número das linhas em que elas aparecem.
- Cada vez que uma nova palavra é lida, o programa pesquisa a árvore para ver se ela já está presente.
  - Se estiver presente, o número da linha é adicionado à lista dessa palavra.
  - Se não estiver presente, uma nova entrada é adicionada na árvore com o número da linha.
- Ao final, as palavras são impressas em ordem alfabética juntamente com suas linhas.

## Como usar
- Compile o código usando o seguinte comando:
```
gcc -o prog main.c
```

- Execute o programa com o seguinte comando:

```
./prog texto.txt
```
Substitua `texto.txt` pelo nome do arquivo de texto que deseja processar.

## Considerações
- Cada palavra contém no máximo 20 letras.
- Não há caracteres acentuados no texto.
