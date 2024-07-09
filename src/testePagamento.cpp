#ifndef TESTEPAGAMENTO_H_INCLUDED
#define TESTEPAGAMENTO_H_INCLUDED

/**
 * @file testPagamento.cpp
 * @brief Arquivo de teste para a classe Pagamento.
 */

#include <iostream>
#include <cassert>
#include "Pagamento.h"

/**
 * @brief Função de teste para a classe Pagamento.
 *
 * Esta função testa os métodos de set e get da classe Pagamento, verificando se as validações e operações estão corretas.
 */
void testPagamento() {
    Pagamento pagamento;

    // Teste de código
    pagamento.setCodigo("PAG123");
    assert(pagamento.getCodigo() == "PAG123");
    std::cout << "Teste de setCodigo e getCodigo passou!" << std::endl;

    // Teste de CPF
    pagamento.setCpf("12345678909");
    assert(pagamento.getCpf() == "12345678909");
    std::cout << "Teste de setCpf e getCpf passou!" << std::endl;

    // Teste de data válida
    try {
        pagamento.setData("01/01/2022");
        assert(pagamento.getData() == "01/01/2022");
        std::cout << "Teste de setData e getData com data válida passou!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao definir data válida: " << e.what() << std::endl;
    }

    // Teste de data inválida
    try {
        pagamento.setData("31/02/2022"); // Data inválida
        std::cerr << "Erro: Data inválida foi aceita." << std::endl;
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Data inválida.");
        std::cout << "Teste de setData com data inválida passou!" << std::endl;
    }

    // Teste de valor
    pagamento.setValor(100.50);
    assert(pagamento.getValor() == 100.50);
    std::cout << "Teste de setValor e getValor passou!" << std::endl;

    // Teste de estado
    pagamento.setEstado("Previsto");
    assert(pagamento.getEstado() == "Previsto");
    std::cout << "Teste de setEstado e getEstado passou!" << std::endl;

    // Teste de nome
    pagamento.setNome("Joao Silva");
    assert(pagamento.getNome() == "Joao Silva");
    std::cout << "Teste de setNome e getNome passou!" << std::endl;

    // Teste de percentual
    pagamento.setPercentual(10);
    assert(pagamento.getPercentual() == 10);
    std::cout << "Teste de setPercentual e getPercentual passou!" << std::endl;

    std::cout << "Todos os testes de Pagamento passaram!" << std::endl;
}

#endif // TESTEPAGAMENTO_H_INCLUDED
