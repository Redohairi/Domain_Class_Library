#ifndef SERVICOFINANCEIRO_H
#define SERVICOFINANCEIRO_H

#include <vector>
#include "Conta.h"
#include "Titulo.h"
#include "Pagamento.h"

/**
 * @brief Classe ServicoFinanceiro
 *
 * Esta classe gerencia contas, t�tulos e pagamentos, permitindo criar, ler, atualizar e excluir esses objetos.
 */
class ServicoFinanceiro {
private:
    std::vector<Conta> contas;       ///< Vetor que armazena as contas gerenciadas
    std::vector<Titulo> titulos;     ///< Vetor que armazena os t�tulos gerenciados
    std::vector<Pagamento> pagamentos; ///< Vetor que armazena os pagamentos gerenciados

public:
    // M�todos para Conta

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
     * @throw std::invalid_argument Se a conta n�o for encontrada.
     */
    Conta lerConta(const std::string& cpf) const;

    /**
     * @brief Atualiza os dados de uma conta existente.
     *
     * @param conta A conta com os dados atualizados.
     * @throw std::invalid_argument Se a conta n�o for encontrada.
     */
    void atualizarConta(const Conta& conta);

    /**
     * @brief Exclui uma conta com base no CPF fornecido.
     *
     * @param cpf O CPF da conta a ser exclu�da.
     * @throw std::invalid_argument Se a conta n�o for encontrada.
     */
    void excluirConta(const std::string& cpf);

    /**
     * @brief Retorna todas as contas gerenciadas.
     *
     * @return std::vector<Conta> Um vetor contendo todas as contas.
     */
    std::vector<Conta> lerContas() const;

    // M�todos para Titulo

    /**
     * @brief Cria um novo t�tulo e adiciona ao vetor de t�tulos gerenciados.
     *
     * @param titulo O t�tulo a ser criado e adicionado.
     */
    void criarTitulo(const Titulo& titulo);

    /**
     * @brief Busca e retorna todos os t�tulos associados a um c�digo.
     *
     * @param codigo O c�digo dos t�tulos a serem buscados.
     * @return std::vector<Titulo> Um vetor contendo todos os t�tulos associados ao c�digo fornecido.
     */
    std::vector<Titulo> lerTitulos(const std::string& codigo) const;

    /**
     * @brief Atualiza os dados de um t�tulo existente.
     *
     * @param titulo O t�tulo com os dados atualizados.
     * @throw std::invalid_argument Se o t�tulo n�o for encontrado.
     */
    void atualizarTitulo(const Titulo& titulo);

    /**
     * @brief Exclui um t�tulo com base no c�digo fornecido.
     *
     * @param codigo O c�digo do t�tulo a ser exclu�do.
     * @throw std::invalid_argument Se o t�tulo n�o for encontrado.
     */
    void excluirTitulo(const std::string& codigo);

    // M�todos para Pagamento

    /**
     * @brief Cria um novo pagamento e adiciona ao vetor de pagamentos gerenciados.
     *
     * @param pagamento O pagamento a ser criado e adicionado.
     */
    void criarPagamento(const Pagamento& pagamento);

    /**
     * @brief Busca e retorna todos os pagamentos associados a um c�digo.
     *
     * @param codigo O c�digo dos pagamentos a serem buscados.
     * @return std::vector<Pagamento> Um vetor contendo todos os pagamentos associados ao c�digo fornecido.
     */
    std::vector<Pagamento> lerPagamentos(const std::string& codigo) const;

    /**
     * @brief Atualiza os dados de um pagamento existente.
     *
     * @param pagamento O pagamento com os dados atualizados.
     * @throw std::invalid_argument Se o pagamento n�o for encontrado.
     */
    void atualizarPagamento(const Pagamento& pagamento);

    /**
     * @brief Exclui um pagamento com base no c�digo fornecido.
     *
     * @param codigo O c�digo do pagamento a ser exclu�do.
     * @throw std::invalid_argument Se o pagamento n�o for encontrado.
     */
    void excluirPagamento(const std::string& codigo);
};

#endif // SERVICOFINANCEIRO_H
