#ifndef TITULOMANAGER_H
#define TITULOMANAGER_H

#include <vector>
#include "Titulo.h"

/**
 * @brief Classe TituloManager
 *
 * Esta classe gerencia um conjunto de t�tulos, permitindo criar, ler, atualizar e excluir t�tulos.
 */
class TituloManager {
private:
    std::vector<Titulo> titulos; ///< Vetor que armazena os t�tulos gerenciados

public:
    /**
     * @brief Cria um novo t�tulo e adiciona ao vetor de t�tulos gerenciados.
     *
     * @param titulo O t�tulo a ser criado e adicionado.
     */
    void criarTitulo(const Titulo& titulo);

    /**
     * @brief Busca e retorna um t�tulo pelo c�digo.
     *
     * @param codigo O c�digo do t�tulo a ser buscado.
     * @return Titulo O t�tulo correspondente ao c�digo fornecido.
     * @throw std::invalid_argument Se o t�tulo n�o for encontrado.
     */
    Titulo lerTitulo(const std::string& codigo) const;

    /**
     * @brief Busca e retorna todos os t�tulos associados a um CPF.
     *
     * @param cpf O CPF dos t�tulos a serem buscados.
     * @return std::vector<Titulo> Um vetor contendo todos os t�tulos associados ao CPF fornecido.
     */
    std::vector<Titulo> lerTitulos(const std::string& cpf) const;

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
};

#endif // TITULOMANAGER_H
