
# Projeto: Biblioteca de Classes de Domínios para Gestão Financeira

Este projeto é uma implementação de uma biblioteca de classes de domínios que encapsula a lógica de negócios e operações CRUD para gerenciar contas, títulos e pagamentos em um sistema financeiro.

## Estrutura do Projeto

O projeto está organizado nas seguintes pastas e arquivos:

```
TI-TP1-DAVI/
├── bin/
├── docs/
├── html/
├── include/
│   ├── Conta.h
│   ├── ContaManager.h
│   ├── Pagamento.h
│   ├── PagamentoManager.h
│   ├── ServicoFinanceiro.h
│   ├── Titulo.h
│   └── TituloManager.h
├── latex/
├── obj/
├── src/
│   ├── Conta.cpp
│   ├── ContaManager.cpp
│   ├── main.cpp
│   ├── Pagamento.cpp
│   ├── PagamentoManager.cpp
│   ├── ServicoFinanceiro.cpp
│   ├── Titulo.cpp
│   └── TituloManager.cpp
├── TI-TP1-DAVI.cbp
├── TI-TP1-DAVI.depend
├── TI-TP1-DAVI.layout
└── Doxyfile
```

## Descrição das Classes

### Classe Conta

Representa uma conta de usuário.

### Classe Titulo

Representa um título financeiro.

### Classe Pagamento

Representa um pagamento associado a um título.

### Classe ContaManager

Gerencia as operações CRUD para a classe Conta.

### Classe TituloManager

Gerencia as operações CRUD para a classe Titulo.

### Classe PagamentoManager

Gerencia as operações CRUD para a classe Pagamento.

### Classe ServicoFinanceiro

Encapsula a lógica de negócios e interage com os gerenciadores.

## Como Executar o Projeto

1. Certifique-se de ter um compilador C++ instalado.
2. Abra o projeto no Code::Blocks.
3. Compile e execute o projeto.
