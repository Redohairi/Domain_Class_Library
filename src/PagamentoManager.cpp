#include "PagamentoManager.h"
#include <algorithm>
#include <stdexcept>

/**
 * @brief Cria um novo pagamento e adiciona ao vetor de pagamentos gerenciados.
 *
 * @param pagamento O pagamento a ser criado e adicionado.
 */
void PagamentoManager::criarPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

/**
 * @brief Busca e retorna um pagamento pelo código.
 *
 * @param codigo O código do pagamento a ser buscado.
 * @return Pagamento O pagamento correspondente ao código fornecido.
 * @throw std::invalid_argument Se o pagamento não for encontrado.
 */
Pagamento PagamentoManager::lerPagamento(const std::string& codigo) const {
    auto it = std::find_if(pagamentos.begin(), pagamentos.end(), [&](const Pagamento& p) { return p.getCodigo() == codigo; });
    if (it != pagamentos.end()) {
        return *it;
    }
    throw std::invalid_argument("Pagamento não encontrado.");
}

/**
 * @brief Busca e retorna todos os pagamentos associados a um CPF.
 *
 * @param cpf O CPF dos pagamentos a serem buscados.
 * @return std::vector<Pagamento> Um vetor contendo todos os pagamentos associados ao CPF fornecido.
 */
std::vector<Pagamento> PagamentoManager::lerPagamentos(const std::string& cpf) const {
    std::vector<Pagamento> resultado;
    for (const auto& pagamento : pagamentos) {
        if (pagamento.getCpf() == cpf) {
            resultado.push_back(pagamento);
        }
    }
    return resultado;
}

/**
 * @brief Atualiza os dados de um pagamento existente.
 *
 * @param pagamento O pagamento com os dados atualizados.
 * @throw std::invalid_argument Se o pagamento não for encontrado.
 */
void PagamentoManager::atualizarPagamento(const Pagamento& pagamento) {
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
void PagamentoManager::excluirPagamento(const std::string& codigo) {
    auto it = std::remove_if(pagamentos.begin(), pagamentos.end(), [&](const Pagamento& p) { return p.getCodigo() == codigo; });
    if (it != pagamentos.end()) {
        pagamentos.erase(it, pagamentos.end());
    } else {
        throw std::invalid_argument("Pagamento não encontrado.");
    }
}
