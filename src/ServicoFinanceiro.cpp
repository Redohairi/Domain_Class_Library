#include "ServicoFinanceiro.h"
#include <algorithm>
#include <stdexcept>

// M�todos para Conta

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
 * @throw std::invalid_argument Se a conta n�o for encontrada.
 */
Conta ServicoFinanceiro::lerConta(const std::string& cpf) const {
    auto it = std::find_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == cpf; });
    if (it != contas.end()) {
        return *it;
    }
    throw std::invalid_argument("Conta n�o encontrada.");
}

/**
 * @brief Atualiza os dados de uma conta existente.
 *
 * @param conta A conta com os dados atualizados.
 * @throw std::invalid_argument Se a conta n�o for encontrada.
 */
void ServicoFinanceiro::atualizarConta(const Conta& conta) {
    auto it = std::find_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == conta.getCpf(); });
    if (it != contas.end()) {
        *it = conta;
    } else {
        throw std::invalid_argument("Conta n�o encontrada.");
    }
}

/**
 * @brief Exclui uma conta com base no CPF fornecido.
 *
 * @param cpf O CPF da conta a ser exclu�da.
 * @throw std::invalid_argument Se a conta n�o for encontrada.
 */
void ServicoFinanceiro::excluirConta(const std::string& cpf) {
    auto it = std::remove_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == cpf; });
    if (it != contas.end()) {
        contas.erase(it, contas.end());
    } else {
        throw std::invalid_argument("Conta n�o encontrada.");
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

// M�todos para Titulo

/**
 * @brief Cria um novo t�tulo e adiciona ao vetor de t�tulos gerenciados.
 *
 * @param titulo O t�tulo a ser criado e adicionado.
 */
void ServicoFinanceiro::criarTitulo(const Titulo& titulo) {
    titulos.push_back(titulo);
}

/**
 * @brief Busca e retorna todos os t�tulos associados a um c�digo.
 *
 * @param codigo O c�digo dos t�tulos a serem buscados.
 * @return std::vector<Titulo> Um vetor contendo todos os t�tulos associados ao c�digo fornecido.
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
 * @brief Atualiza os dados de um t�tulo existente.
 *
 * @param titulo O t�tulo com os dados atualizados.
 * @throw std::invalid_argument Se o t�tulo n�o for encontrado.
 */
void ServicoFinanceiro::atualizarTitulo(const Titulo& titulo) {
    auto it = std::find_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == titulo.getCodigo(); });
    if (it != titulos.end()) {
        *it = titulo;
    } else {
        throw std::invalid_argument("Titulo n�o encontrado.");
    }
}

/**
 * @brief Exclui um t�tulo com base no c�digo fornecido.
 *
 * @param codigo O c�digo do t�tulo a ser exclu�do.
 * @throw std::invalid_argument Se o t�tulo n�o for encontrado.
 */
void ServicoFinanceiro::excluirTitulo(const std::string& codigo) {
    auto it = std::remove_if(titulos.begin(), titulos.end(), [&](const Titulo& t) { return t.getCodigo() == codigo; });
    if (it != titulos.end()) {
        titulos.erase(it, titulos.end());
    } else {
        throw std::invalid_argument("Titulo n�o encontrado.");
    }
}

// M�todos para Pagamento

/**
 * @brief Cria um novo pagamento e adiciona ao vetor de pagamentos gerenciados.
 *
 * @param pagamento O pagamento a ser criado e adicionado.
 */
void ServicoFinanceiro::criarPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

/**
 * @brief Busca e retorna todos os pagamentos associados a um c�digo.
 *
 * @param codigo O c�digo dos pagamentos a serem buscados.
 * @return std::vector<Pagamento> Um vetor contendo todos os pagamentos associados ao c�digo fornecido.
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
 * @throw std::invalid_argument Se o pagamento n�o for encontrado.
 */
void ServicoFinanceiro::atualizarPagamento(const Pagamento& pagamento) {
    auto it = std::find_if(pagamentos.begin(), pagamentos.end(), [&](const Pagamento& p) { return p.getCodigo() == pagamento.getCodigo(); });
    if (it != pagamentos.end()) {
        *it = pagamento;
    } else {
        throw std::invalid_argument("Pagamento n�o encontrado.");
    }
}

/**
 * @brief Exclui um pagamento com base no c�digo fornecido.
 *
 * @param codigo O c�digo do pagamento a ser exclu�do.
 * @throw std::invalid_argument Se o pagamento n�o for encontrado.
 */
void ServicoFinanceiro::excluirPagamento(const std::string& codigo) {
    auto it = std::remove_if(pagamentos.begin(), pagamentos.end(), [&](const Pagamento& p) { return p.getCodigo() == codigo; });
    if (it != pagamentos.end()) {
        pagamentos.erase(it, pagamentos.end());
    } else {
        throw std::invalid_argument("Pagamento n�o encontrado.");
    }
}
