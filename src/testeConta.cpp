#include <iostream>
#include <cassert>
#include "Conta.h"

/**
 * @brief Função de teste para a classe Conta.
 *
 * Esta função testa os métodos de set e get da classe Conta, verificando se as validações estão corretas.
 */
void testConta() {
    Conta conta;

    // Teste de CPF válido
    try {
        conta.setCpf("12345678909");
        assert(conta.getCpf() == "12345678909");
        std::cout << "Teste de setCpf e getCpf com CPF válido passou!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao definir CPF válido: " << e.what() << std::endl;
    }

    // Teste de CPF inválido
    try {
        conta.setCpf("1234567890"); // CPF inválido
        std::cerr << "Erro: CPF inválido foi aceito." << std::endl;
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "CPF inválido");
        std::cout << "Teste de setCpf com CPF inválido passou!" << std::endl;
    }

    // Teste de nome válido
    try {
        conta.setNome("Joao Silva");
        assert(conta.getNome() == "Joao Silva");
        std::cout << "Teste de setNome e getNome com nome válido passou!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao definir nome válido: " << e.what() << std::endl;
    }

    // Teste de nome inválido
    try {
        conta.setNome("Jo"); // Nome inválido
        std::cerr << "Erro: Nome inválido foi aceito." << std::endl;
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "O nome não pode ser vazio e deve ter pelo menos 3 caracteres");
        std::cout << "Teste de setNome com nome inválido passou!" << std::endl;
    }

    // Teste de senha válida
    try {
        conta.setSenha("Senha123");
        assert(conta.getSenha() == "Senha123");
        std::cout << "Teste de setSenha e getSenha com senha válida passou!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao definir senha válida: " << e.what() << std::endl;
    }

    // Teste de senha inválida
    try {
        conta.setSenha("senha"); // Senha inválida
        std::cerr << "Erro: Senha inválida foi aceita." << std::endl;
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Senha deve conter pelo menos 8 caracteres, incluindo letras e números");
        std::cout << "Teste de setSenha com senha inválida passou!" << std::endl;
    }

    std::cout << "Todos os testes de Conta passaram!" << std::endl;
}
