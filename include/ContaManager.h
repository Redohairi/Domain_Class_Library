#ifndef CONTAMANAGER_H
#define CONTAMANAGER_H

#include <vector>
#include "Conta.h"

/**
 * @brief Classe ContaManager
 *
 * Esta classe gerencia um conjunto de contas, permitindo criar, ler, atualizar e excluir contas.
 */
class ContaManager {
private:
    std::vector<Conta> contas; ///< Vetor que armazena as contas gerenciadas

public:
    /**
     * @brief Cria uma nova conta e adiciona ao vetor de contas gerenciadas.
     *
     * @param conta A conta a ser criada e adicionada.
     */
    void criarConta(const Conta& conta);

    /**
     * @brief Busca e retorna uma conta pelo CPF.
     *
     * @param cpf O CPF da conta a ser buscada.
     * @return Conta A conta correspondente ao CPF fornecido.
     * @throw std::invalid_argument Se a conta não for encontrada.
     */
    Conta lerConta(const std::string& cpf) const;

    /**
     * @brief Atualiza os dados de uma conta existente.
     *
     * @param conta A conta com os dados atualizados.
     * @throw std::invalid_argument Se a conta não for encontrada.
     */
    void atualizarConta(const Conta& conta);

    /**
     * @brief Exclui uma conta com base no CPF fornecido.
     *
     * @param cpf O CPF da conta a ser excluída.
     * @throw std::invalid_argument Se a conta não for encontrada.
     */
    void excluirConta(const std::string& cpf);
};

#endif // CONTAMANAGER_H
