# Desafio Super Trunfo - Países

Este projeto foi desenvolvido como parte do desafio proposto pela disciplina de Lógica de Programação. O objetivo é comparar cartas de cidades com base em seus atributos. O sistema foi implementado com os três níveis: **Novato**, **Aventureiro** e **Mestre**.

## 📚 Níveis Implementados

### 🟢 Nível Novato
- Cadastro manual de duas cartas via terminal.
- Atributos: Estado, Código, Nome da Cidade, População, Área, PIB, Pontos Turísticos.
- Comparação baseada em um atributo fixo.
- Exibição da carta vencedora com base no maior valor (exceto densidade populacional).

### 🟡 Nível Aventureiro
- Menu interativo com `switch` para o usuário escolher qual atributo comparar.
- Lógica aninhada de decisão para múltiplos atributos.
- Exibição clara do resultado com o atributo utilizado.

### 🔴 Nível Mestre
- Comparação de dois atributos ao mesmo tempo.
- Uso de operadores ternários e decisões complexas.
- Tratamento de empate com mensagem apropriada.
- Navegação dinâmica entre as opções de comparação.

## 💻 Como executar

1. Compile o código:
   
   gcc logicaSuperTrunfo.c -o supertrunfo

2. Execute no terminal: 

./supertrunfo
