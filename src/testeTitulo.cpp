#ifndef TESTETITULO_H_INCLUDED
#define TESTETITULO_H_INCLUDED

/**
 * @file testTitulo.cpp
 * @brief Arquivo de teste para a classe Titulo.
 */

#include <iostream>
#include <cassert>
#include "Titulo.h"

/**
 * @brief Função de teste para a classe Titulo.
 *
 * Esta função testa os métodos de set e get da classe Titulo, verificando se as operações e validações estão corretas.
 */
void testTitulo() {
    Titulo titulo;

    // Teste de código
    titulo.setCodigo("TIT123");
    assert(titulo.getCodigo() == "TIT123");
    std::cout << "Teste de setCodigo e getCodigo passou!" << std::endl;

    // Teste de emissor
    titulo.setEmissor("Empresa XYZ");
    assert(titulo.getEmissor() == "Empresa XYZ");
    std::cout << "Teste de setEmissor e getEmissor passou!" << std::endl;

    // Teste de setor
    titulo.setSetor("Financeiro");
    assert(titulo.getSetor() == "Financeiro");
    std::cout << "Teste de setSetor e getSetor passou!" << std::endl;

    // Teste de data de emissão
    titulo.setDataEmissao("01/01/2022");
    assert(titulo.getDataEmissao() == "01/01/2022");
    std::cout << "Teste de setDataEmissao e getDataEmissao passou!" << std::endl;

    // Teste de data de vencimento
    titulo.setDataVencimento("01/01/2023");
    assert(titulo.getDataVencimento() == "01/01/2023");
    std::cout << "Teste de setDataVencimento e getDataVencimento passou!" << std::endl;

    // Teste de valor
    titulo.setValor(1000.00);
    assert(titulo.getValor() == 1000.00);
    std::cout << "Teste de setValor e getValor passou!" << std::endl;

    // Teste de CPF
    titulo.setCpf("12345678909");
    assert(titulo.getCpf() == "12345678909");
    std::cout << "Teste de setCpf e getCpf passou!" << std::endl;

    std::cout << "Todos os testes de Titulo passaram!" << std::endl;
}

#endif // TESTETITULO_H_INCLUDED
