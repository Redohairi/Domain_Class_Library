#ifndef TITULOMANAGER_H
#define TITULOMANAGER_H

#include <vector>
#include "Titulo.h"

/**
 * @brief Classe TituloManager
 *
 * Esta classe gerencia um conjunto de títulos, permitindo criar, ler, atualizar e excluir títulos.
 */
class TituloManager {
private:
    std::vector<Titulo> titulos; ///< Vetor que armazena os títulos gerenciados

public:
    /**
     * @brief Cria um novo título e adiciona ao vetor de títulos gerenciados.
     *
     * @param titulo O título a ser criado e adicionado.
     */
    void criarTitulo(const Titulo& titulo);

    /**
     * @brief Busca e retorna um título pelo código.
     *
     * @param codigo O código do título a ser buscado.
     * @return Titulo O título correspondente ao código fornecido.
     * @throw std::invalid_argument Se o título não for encontrado.
     */
    Titulo lerTitulo(const std::string& codigo) const;

    /**
     * @brief Busca e retorna todos os títulos associados a um CPF.
     *
     * @param cpf O CPF dos títulos a serem buscados.
     * @return std::vector<Titulo> Um vetor contendo todos os títulos associados ao CPF fornecido.
     */
    std::vector<Titulo> lerTitulos(const std::string& cpf) const;

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
};

#endif // TITULOMANAGER_H
