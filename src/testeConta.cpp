#include <iostream>
#include <cassert>
#include "Conta.h"

/**
 * @brief Fun��o de teste para a classe Conta.
 *
 * Esta fun��o testa os m�todos de set e get da classe Conta, verificando se as valida��es est�o corretas.
 */
void testConta() {
    Conta conta;

    // Teste de CPF v�lido
    try {
        conta.setCpf("12345678909");
        assert(conta.getCpf() == "12345678909");
        std::cout << "Teste de setCpf e getCpf com CPF v�lido passou!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao definir CPF v�lido: " << e.what() << std::endl;
    }

    // Teste de CPF inv�lido
    try {
        conta.setCpf("1234567890"); // CPF inv�lido
        std::cerr << "Erro: CPF inv�lido foi aceito." << std::endl;
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "CPF inv�lido");
        std::cout << "Teste de setCpf com CPF inv�lido passou!" << std::endl;
    }

    // Teste de nome v�lido
    try {
        conta.setNome("Joao Silva");
        assert(conta.getNome() == "Joao Silva");
        std::cout << "Teste de setNome e getNome com nome v�lido passou!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao definir nome v�lido: " << e.what() << std::endl;
    }

    // Teste de nome inv�lido
    try {
        conta.setNome("Jo"); // Nome inv�lido
        std::cerr << "Erro: Nome inv�lido foi aceito." << std::endl;
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "O nome n�o pode ser vazio e deve ter pelo menos 3 caracteres");
        std::cout << "Teste de setNome com nome inv�lido passou!" << std::endl;
    }

    // Teste de senha v�lida
    try {
        conta.setSenha("Senha123");
        assert(conta.getSenha() == "Senha123");
        std::cout << "Teste de setSenha e getSenha com senha v�lida passou!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao definir senha v�lida: " << e.what() << std::endl;
    }

    // Teste de senha inv�lida
    try {
        conta.setSenha("senha"); // Senha inv�lida
        std::cerr << "Erro: Senha inv�lida foi aceita." << std::endl;
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Senha deve conter pelo menos 8 caracteres, incluindo letras e n�meros");
        std::cout << "Teste de setSenha com senha inv�lida passou!" << std::endl;
    }

    std::cout << "Todos os testes de Conta passaram!" << std::endl;
}
