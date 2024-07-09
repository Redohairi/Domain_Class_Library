#ifndef PAGAMENTOMANAGER_H
#define PAGAMENTOMANAGER_H

#include <vector>
#include "Pagamento.h"

/**
 * @brief Classe PagamentoManager
 *
 * Esta classe gerencia um conjunto de pagamentos, permitindo criar, ler, atualizar e excluir pagamentos.
 */
class PagamentoManager {
private:
    std::vector<Pagamento> pagamentos; ///< Vetor que armazena os pagamentos gerenciados

public:
    /**
     * @brief Cria um novo pagamento e adiciona ao vetor de pagamentos gerenciados.
     *
     * @param pagamento O pagamento a ser criado e adicionado.
     */
    void criarPagamento(const Pagamento& pagamento);

    /**
     * @brief Busca e retorna um pagamento pelo c�digo.
     *
     * @param codigo O c�digo do pagamento a ser buscado.
     * @return Pagamento O pagamento correspondente ao c�digo fornecido.
     * @throw std::invalid_argument Se o pagamento n�o for encontrado.
     */
    Pagamento lerPagamento(const std::string& codigo) const;

    /**
     * @brief Busca e retorna todos os pagamentos associados a um CPF.
     *
     * @param cpf O CPF dos pagamentos a serem buscados.
     * @return std::vector<Pagamento> Um vetor contendo todos os pagamentos associados ao CPF fornecido.
     */
    std::vector<Pagamento> lerPagamentos(const std::string& cpf) const;

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

#endif // PAGAMENTOMANAGER_H
