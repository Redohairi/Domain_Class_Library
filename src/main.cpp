#include <iostream>
#include "ServicoFinanceiro.h"

// Declarar as funções de teste
void testConta();
void testPagamento();
void testTitulo();

bool autenticarUsuario(ServicoFinanceiro& servico, const std::string& cpf, const std::string& senha) {
    try {
        Conta conta = servico.lerConta(cpf);
        return conta.getSenha() == senha;
    } catch (const std::invalid_argument&) {
        return false;
    }
}

void criarConta(ServicoFinanceiro& servico) {
    std::string cpf, nome, senha;
    std::cout << "Criar nova conta\n";
    std::cout << "Digite o CPF: ";
    std::cin >> cpf;
    std::cout << "Digite o Nome: ";
    std::cin >> nome;
    std::cout << "Digite a Senha: ";
    std::cin >> senha;

    try {
        Conta conta;
        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);
        servico.criarConta(conta);
        std::cout << "Conta criada com sucesso!\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao criar conta: " << e.what() << std::endl;
    }
}

void interagirComUsuario(ServicoFinanceiro& servico) {
    std::string cpf, senha;

    std::cout << "Digite o CPF para autenticar: ";
    std::cin >> cpf;
    std::cout << "Digite a Senha: ";
    std::cin >> senha;

    if (!autenticarUsuario(servico, cpf, senha)) {
        std::cout << "Autenticação falhou!" << std::endl;
        return;
    }

    int opcao;
    std::string nome, codigo, emissor, setor, dataEmissao, dataVencimento, data, estado;
    double valor;
    int percentual;

    while (true) {
        std::cout << "Selecione uma opcao:\n";
        std::cout << "1. Criar Conta\n";
        std::cout << "2. Ler Conta\n";
        std::cout << "3. Atualizar Conta\n";
        std::cout << "4. Excluir Conta\n";
        std::cout << "5. Criar Titulo\n";
        std::cout << "6. Ler Titulo\n";
        std::cout << "7. Atualizar Titulo\n";
        std::cout << "8. Excluir Titulo\n";
        std::cout << "9. Criar Pagamento\n";
        std::cout << "10. Ler Pagamento\n";
        std::cout << "11. Atualizar Pagamento\n";
        std::cout << "12. Excluir Pagamento\n";
        std::cout << "0. Voltar ao menu inicial\n";
        std::cout << "13. Sair\n";
        std::cin >> opcao;

        if (opcao == 13) {
            std::cout << "Tem certeza que deseja sair? (1 - Sim, 0 - Não): ";
            int confirmar;
            std::cin >> confirmar;
            if (confirmar == 1) break;
        }

        switch (opcao) {
        case 0:
            return; // Voltar ao menu inicial
        case 1:
            criarConta(servico);
            break;
        case 2:
            std::cout << "Digite o CPF: ";
            std::cin >> cpf;
            try {
                Conta contaLida = servico.lerConta(cpf);
                std::cout << "Conta lida: " << contaLida.getNome() << " com CPF: " << contaLida.getCpf() << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 3:
            std::cout << "Digite o CPF: ";
            std::cin >> cpf;
            std::cout << "Digite o Nome: ";
            std::cin >> nome;
            std::cout << "Digite a Senha: ";
            std::cin >> senha;
            try {
                Conta conta;
                conta.setCpf(cpf);
                conta.setNome(nome);
                conta.setSenha(senha);
                servico.atualizarConta(conta);
                std::cout << "Conta atualizada com sucesso!" << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << "Digite o CPF: ";
            std::cin >> cpf;
            try {
                servico.excluirConta(cpf);
                std::cout << "Conta excluída com sucesso." << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 5:
            std::cout << "Digite o Codigo: ";
            std::cin >> codigo;
            std::cout << "Digite o Emissor: ";
            std::cin >> emissor;
            std::cout << "Digite o Setor: ";
            std::cin >> setor;
            std::cout << "Digite a Data de Emissao: ";
            std::cin >> dataEmissao;
            std::cout << "Digite a Data de Vencimento: ";
            std::cin >> dataVencimento;
            std::cout << "Digite o Valor: ";
            std::cin >> valor;
            try {
                Titulo titulo;
                titulo.setCodigo(codigo);
                titulo.setEmissor(emissor);
                titulo.setSetor(setor);
                titulo.setDataEmissao(dataEmissao);
                titulo.setDataVencimento(dataVencimento);
                titulo.setValor(valor);
                servico.criarTitulo(titulo);
                std::cout << "Titulo criado com sucesso!" << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Erro ao criar título: " << e.what() << std::endl;
            }
            break;
        case 6:
            std::cout << "Digite o Codigo: ";
            std::cin >> codigo;
            try {
                std::vector<Titulo> titulos = servico.lerTitulos(codigo);
                if (!titulos.empty()) {
                    Titulo tituloLido = titulos[0];
                    std::cout << "Titulo lido: " << tituloLido.getCodigo() << " do emissor: " << tituloLido.getEmissor() << std::endl;
                } else {
                    std::cerr << "Titulo não encontrado." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 7:
            std::cout << "Digite o Codigo: ";
            std::cin >> codigo;
            std::cout << "Digite o Emissor: ";
            std::cin >> emissor;
            std::cout << "Digite o Setor: ";
            std::cin >> setor;
            std::cout << "Digite a Data de Emissao: ";
            std::cin >> dataEmissao;
            std::cout << "Digite a Data de Vencimento: ";
            std::cin >> dataVencimento;
            std::cout << "Digite o Valor: ";
            std::cin >> valor;
            try {
                Titulo titulo;
                titulo.setCodigo(codigo);
                titulo.setEmissor(emissor);
                titulo.setSetor(setor);
                titulo.setDataEmissao(dataEmissao);
                titulo.setDataVencimento(dataVencimento);
                titulo.setValor(valor);
                servico.atualizarTitulo(titulo);
                std::cout << "Titulo atualizado com sucesso!" << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 8:
            std::cout << "Digite o Codigo: ";
            std::cin >> codigo;
            try {
                servico.excluirTitulo(codigo);
                std::cout << "Titulo excluído com sucesso." << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 9:
            std::cout << "Digite o Codigo: ";
            std::cin >> codigo;
            std::cout << "Digite a Data: ";
            std::cin >> data;
            std::cout << "Digite o Percentual: ";
            std::cin >> percentual;
            std::cout << "Digite o Estado: ";
            std::cin >> estado;
            try {
                Pagamento pagamento;
                pagamento.setCodigo(codigo);
                pagamento.setData(data);
                pagamento.setPercentual(percentual);
                pagamento.setEstado(estado);
                servico.criarPagamento(pagamento);
                std::cout << "Pagamento criado com sucesso!" << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 10:
            std::cout << "Digite o Codigo: ";
            std::cin >> codigo;
            try {
                std::vector<Pagamento> pagamentos = servico.lerPagamentos(codigo);
                if (!pagamentos.empty()) {
                    Pagamento pagamentoLido = pagamentos[0];
                    std::cout << "Pagamento lido: " << pagamentoLido.getCodigo() << " com percentual: " << pagamentoLido.getPercentual() << "%" << std::endl;
                } else {
                    std::cerr << "Pagamento não encontrado." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 11:
            std::cout << "Digite o Codigo: ";
            std::cin >> codigo;
            std::cout << "Digite a Data: ";
            std::cin >> data;
            std::cout << "Digite o Percentual: ";
            std::cin >> percentual;
            std::cout << "Digite o Estado: ";
            std::cin >> estado;
            try {
                Pagamento pagamento;
                pagamento.setCodigo(codigo);
                pagamento.setData(data);
                pagamento.setPercentual(percentual);
                pagamento.setEstado(estado);
                servico.atualizarPagamento(pagamento);
                std::cout << "Pagamento atualizado com sucesso!" << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 12:
            std::cout << "Digite o Codigo: ";
            std::cin >> codigo;
            try {
                servico.excluirPagamento(codigo);
                std::cout << "Pagamento excluído com sucesso." << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }
    }
}

int main() {
    // Inicializando o serviço financeiro
    ServicoFinanceiro servico;

    while (true) {
        std::cout << "Selecione uma opção:\n";
        std::cout << "1. Acessar Serviços\n";
        std::cout << "2. Criar Conta\n";
        std::cout << "3. Ver Resultados dos Testes\n";
        std::cout << "4. Sair\n";
        int opcaoInicial;
        std::cin >> opcaoInicial;

        if (opcaoInicial == 4) {
            std::cout << "Tem certeza que deseja sair? (1 - Sim, 0 - Não): ";
            int confirmar;
            std::cin >> confirmar;
            if (confirmar == 1) break;
        }

        switch (opcaoInicial) {
        case 1:
            interagirComUsuario(servico);
            break;
        case 2:
            criarConta(servico);
            break;
        case 3:
            std::cout << "Resultados dos testes:\n";
            testConta();
            testPagamento();
            testTitulo();
            std::cout << "\nPressione qualquer tecla para voltar ao menu inicial.\n";
            std::cin.ignore(); // Ignorar o '\n' deixado no buffer
            std::cin.get(); // Esperar o usuário pressionar uma tecla
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }
    }

    return 0;
}
