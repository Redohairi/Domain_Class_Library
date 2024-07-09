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
 * @brief Fun��o de teste para a classe Pagamento.
 *
 * Esta fun��o testa os m�todos de set e get da classe Pagamento, verificando se as valida��es e opera��es est�o corretas.
 */
void testPagamento() {
    Pagamento pagamento;

    // Teste de c�digo
    pagamento.setCodigo("PAG123");
    assert(pagamento.getCodigo() == "PAG123");
    std::cout << "Teste de setCodigo e getCodigo passou!" << std::endl;

    // Teste de CPF
    pagamento.setCpf("12345678909");
    assert(pagamento.getCpf() == "12345678909");
    std::cout << "Teste de setCpf e getCpf passou!" << std::endl;

    // Teste de data v�lida
    try {
        pagamento.setData("01/01/2022");
        assert(pagamento.getData() == "01/01/2022");
        std::cout << "Teste de setData e getData com data v�lida passou!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao definir data v�lida: " << e.what() << std::endl;
    }

    // Teste de data inv�lida
    try {
        pagamento.setData("31/02/2022"); // Data inv�lida
        std::cerr << "Erro: Data inv�lida foi aceita." << std::endl;
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Data inv�lida.");
        std::cout << "Teste de setData com data inv�lida passou!" << std::endl;
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
