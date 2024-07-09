#ifndef SERVICOFINANCEIRO_H
#define SERVICOFINANCEIRO_H

#include <vector>
#include "Conta.h"
#include "Titulo.h"
#include "Pagamento.h"

/**
 * @brief Classe ServicoFinanceiro
 *
 * Esta classe gerencia contas, títulos e pagamentos, permitindo criar, ler, atualizar e excluir esses objetos.
 */
class ServicoFinanceiro {
private:
    std::vector<Conta> contas;       ///< Vetor que armazena as contas gerenciadas
    std::vector<Titulo> titulos;     ///< Vetor que armazena os títulos gerenciados
    std::vector<Pagamento> pagamentos; ///< Vetor que armazena os pagamentos gerenciados

public:
    // Métodos para Conta

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

    /**
     * @brief Retorna todas as contas gerenciadas.
     *
     * @return std::vector<Conta> Um vetor contendo todas as contas.
     */
    std::vector<Conta> lerContas() const;

    // Métodos para Titulo

    /**
     * @brief Cria um novo título e adiciona ao vetor de títulos gerenciados.
     *
     * @param titulo O título a ser criado e adicionado.
     */
    void criarTitulo(const Titulo& titulo);

    /**
     * @brief Busca e retorna todos os títulos associados a um código.
     *
     * @param codigo O código dos títulos a serem buscados.
     * @return std::vector<Titulo> Um vetor contendo todos os títulos associados ao código fornecido.
     */
    std::vector<Titulo> lerTitulos(const std::string& codigo) const;

    /**
     * @brief Atualiza os dados de um título existente.
     *
     * @param titulo O título com os dados atualizados.
     * @throw std::invalid_argument Se o título não for encontrado.
     */
    void atualizarTitulo(const Titulo& titulo);

    /**
     * @brief Exclui um título com base no código fornecido.
     *
     * @param codigo O código do título a ser excluído.
     * @throw std::invalid_argument Se o título não for encontrado.
     */
    void excluirTitulo(const std::string& codigo);

    // Métodos para Pagamento

    /**
     * @brief Cria um novo pagamento e adiciona ao vetor de pagamentos gerenciados.
     *
     * @param pagamento O pagamento a ser criado e adicionado.
     */
    void criarPagamento(const Pagamento& pagamento);

    /**
     * @brief Busca e retorna todos os pagamentos associados a um código.
     *
     * @param codigo O código dos pagamentos a serem buscados.
     * @return std::vector<Pagamento> Um vetor contendo todos os pagamentos associados ao código fornecido.
     */
    std::vector<Pagamento> lerPagamentos(const std::string& codigo) const;

    /**
     * @brief Atualiza os dados de um pagamento existente.
     *
     * @param pagamento O pagamento com os dados atualizados.
     * @throw std::invalid_argument Se o pagamento não for encontrado.
     */
    void atualizarPagamento(const Pagamento& pagamento);

    /**
     * @brief Exclui um pagamento com base no código fornecido.
     *
     * @param codigo O código do pagamento a ser excluído.
     * @throw std::invalid_argument Se o pagamento não for encontrado.
     */
    void excluirPagamento(const std::string& codigo);
};

#endif // SERVICOFINANCEIRO_H
