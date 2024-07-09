#include "ContaManager.h"
#include "Conta.h"
#include <algorithm>
#include <stdexcept>

/**
 * @brief Cria uma nova conta e adiciona ao vetor de contas gerenciadas.
 *
 * @param conta A conta a ser criada e adicionada.
 */
void ContaManager::criarConta(const Conta& conta) {
    contas.push_back(conta);
}

/**
 * @brief Busca e retorna uma conta pelo CPF.
 *
 * @param cpf O CPF da conta a ser buscada.
 * @return Conta A conta correspondente ao CPF fornecido.
 * @throw std::invalid_argument Se a conta não for encontrada.
 */
Conta ContaManager::lerConta(const std::string& cpf) const {
    auto it = std::find_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == cpf; });
    if (it != contas.end()) {
        return *it;
    }
    throw std::invalid_argument("Conta não encontrada.");  // Correto: Lança exceção se não encontrar a conta.
}

/**
 * @brief Atualiza os dados de uma conta existente.
 *
 * @param conta A conta com os dados atualizados.
 * @throw std::invalid_argument Se a conta não for encontrada.
 */
void ContaManager::atualizarConta(const Conta& conta) {
    auto it = std::find_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == conta.getCpf(); });
    if (it != contas.end()) {
        *it = conta;  // Atualiza a conta encontrada.
    } else {
        throw std::invalid_argument("Conta não encontrada.");  // Correto: Lança exceção se não encontrar a conta.
    }
}

/**
 * @brief Exclui uma conta com base no CPF fornecido.
 *
 * @param cpf O CPF da conta a ser excluída.
 * @throw std::invalid_argument Se a conta não for encontrada.
 */
void ContaManager::excluirConta(const std::string& cpf) {
    auto it = std::remove_if(contas.begin(), contas.end(), [&](const Conta& c) { return c.getCpf() == cpf; });
    if (it == contas.end()) {
        throw std::invalid_argument("Conta não encontrada.");  // Corrige a lógica: Exceção se não encontrar a conta.
    }
    contas.erase(it, contas.end());  // Erase-remove idiom: remove todas as contas marcadas para remoção.
}
