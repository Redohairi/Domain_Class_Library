#include "ServicoFinanceiro.h"
#include <algorithm>
#include <stdexcept>

// Métodos para Conta

/**
 * @brief Cria uma nova conta e adiciona ao vetor de contas gerenciadas.
 *
 * @param conta A conta a ser criada e adicionada.
 */
void ServicoFinanceiro::criarConta(const Conta& conta) {
    contas.push_back(conta);
}

/**
 * @brief Busca e retorna uma conta pelo CPF.
 *
 * @param cpf O CPF da conta a ser buscada.
 * @return Conta A conta correspondente ao CPF fornecido.
 * @throw std::invalid_argument Se a conta não for encontrada.
 */
Conta ServicoFinanceiro::lerConta(const std::string& cpf) const {
    auto it = std::find_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == cpf; });
    if (it != contas.end()) {
        return *it;
    }
    throw std::invalid_argument("Conta não encontrada.");
}

/**
 * @brief Atualiza os dados de uma conta existente.
 *
 * @param conta A conta com os dados atualizados.
 * @throw std::invalid_argument Se a conta não for encontrada.
 */
void ServicoFinanceiro::atualizarConta(const Conta& conta) {
    auto it = std::find_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == conta.getCpf(); });
    if (it != contas.end()) {
        *it = conta;
    } else {
        throw std::invalid_argument("Conta não encontrada.");
    }
}

/**
 * @brief Exclui uma conta com base no CPF fornecido.
 *
 * @param cpf O CPF da conta a ser excluída.
 * @throw std::invalid_argument Se a conta não for encontrada.
 */
void ServicoFinanceiro::excluirConta(const std::string& cpf) {
    auto it = std::remove_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == cpf; });
    if (it != contas.end()) {
        contas.erase(it, contas.end());
    } else {
        throw std::invalid_argument("Conta não encontrada.");
    }
}

/**
 * @brief Retorna todas as contas gerenciadas.
 *
 * @return std::vector<Conta> Um vetor contendo todas as contas.
 */
std::vector<Conta> ServicoFinanceiro::lerContas() const {
    return contas;
}

// Métodos para Titulo

/**
 * @brief Cria um novo título e adiciona ao vetor de títulos gerenciados.
 *
 * @param titulo O título a ser criado e adicionado.
 */
void ServicoFinanceiro::criarTitulo(const Titulo& titulo) {
    titulos.push_back(titulo);
}

/**
 * @brief Busca e retorna todos os títulos associados a um código.
 *
 * @param codigo O código dos títulos a serem buscados.
 * @return std::vector<Titulo> Um vetor contendo todos os títulos associados ao código fornecido.
 */
std::vector<Titulo> ServicoFinanceiro::lerTitulos(const std::string& codigo) const {
    std::vector<Titulo> resultados;
    for (const auto& titulo : titulos) {
        if (titulo.getCodigo() == codigo) {
            resultados.push_back(titulo);
        }
    }
    return resultados;
}

/**
 * @brief Atualiza os dados de um título existente.
 *
 * @param titulo O título com os dados atualizados.
 * @throw std::invalid_argument Se o título não for encontrado.
 */
void ServicoFinanceiro::atualizarTitulo(const Titulo& titulo) {
    auto it = std::find_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == titulo.getCodigo(); });
    if (it != titulos.end()) {
        *it = titulo;
    } else {
        throw std::invalid_argument("Titulo não encontrado.");
    }
}

/**
 * @brief Exclui um título com base no código fornecido.
 *
 * @param codigo O código do título a ser excluído.
 * @throw std::invalid_argument Se o título não for encontrado.
 */
void ServicoFinanceiro::excluirTitulo(const std::string& codigo) {
    auto it = std::remove_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == codigo; });
    if (it != titulos.end()) {
        titulos.erase(it, titulos.end());
    } else {
        throw std::invalid_argument("Titulo não encontrado.");
    }
}

// Métodos para Pagamento

/**
 * @brief Cria um novo pagamento e adiciona ao vetor de pagamentos gerenciados.
 *
 * @param pagamento O pagamento a ser criado e adicionado.
 */
void ServicoFinanceiro::criarPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

/**
 * @brief Busca e retorna todos os pagamentos associados a um código.
 *
 * @param codigo O código dos pagamentos a serem buscados.
 * @return std::vector<Pagamento> Um vetor contendo todos os pagamentos associados ao código fornecido.
 */
std::vector<Pagamento> ServicoFinanceiro::lerPagamentos(const std::string& codigo) const {
    std::vector<Pagamento> resultados;
    for (const auto& pagamento : pagamentos) {
        if (pagamento.getCodigo() == codigo) {
            resultados.push_back(pagamento);
        }
    }
    return resultados;
}

/**
 * @brief Atualiza os dados de um pagamento existente.
 *
 * @param pagamento O pagamento com os dados atualizados.
 * @throw std::invalid_argument Se o pagamento não for encontrado.
 */
void ServicoFinanceiro::atualizarPagamento(const Pagamento& pagamento) {
    auto it = std::find_if(pagamentos.begin(), pagamentos.end(), [&](const Pagamento& p) { return p.getCodigo() == pagamento.getCodigo(); });
    if (it != pagamentos.end()) {
        *it = pagamento;
    } else {
        throw std::invalid_argument("Pagamento não encontrado.");
    }
}

/**
 * @brief Exclui um pagamento com base no código fornecido.
 *
 * @param codigo O código do pagamento a ser excluído.
 * @throw std::invalid_argument Se o pagamento não for encontrado.
 */
void ServicoFinanceiro::excluirPagamento(const std::string& codigo) {
    auto it = std::remove_if(pagamentos.begin(), pagamentos.end(), [&](const Pagamento& p) { return p.getCodigo() == codigo; });
    if (it != pagamentos.end()) {
        pagamentos.erase(it, pagamentos.end());
    } else {
        throw std::invalid_argument("Pagamento não encontrado.");
    }
}
