#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    string nome;
    vector<string> nomes_usuarios, email_usuarios, cpf_usuarios, senhas_usuarios, telefone_usuarios;
    string email, cpf, telefone, senha;
} Usuario;

struct Admin{
    string adm_email = "adm1234@gmail.com", adm_senha = "1234";
};

typedef struct{
    vector<string> destino, descricao, data;
    vector<float> valor;
    vector<int> vagas;
} Viagens;

typedef struct{
    float gift_card;
    vector<float> carteira;
} Balance;

typedef struct{
    vector<string> metodo;
    vector<string> n_cartao, data, cvv, nome_cartao;
} Pagamento;

typedef struct{
    vector<string> destino;
    vector<float> valor_carrinho;
    vector<int> vagas;
} Carrinho;

int main() {
    
    bool adm_painel = false;
    bool login_sucess = false;
    int opcao=0;
    
    Carrinho carrinho;
    Pagamento pagamento;
    Viagens viagem;
    Admin admin;
    Usuario user;
    Balance balance;
    
    int opcao_viagem = 0;
    
    
    string viagens_all[] = {"Rio de Janeiro", "Curitiba", "Santa Catarina"};
    string descricao_viagem[] = {"Viagem para o rio, com cafe da manha incluso e hospedagem de 3 dias em um hotel a 200mts da praia de copacabana","Curta um final de semana em curitiba por preco acessivel e com guia de viagem, incluso cafe da manha","Aproveite o ano novo na praia mais desejada do brasil, em um apartamento exclusivo de frente para a praia"};
    string data_viagem[] = {"10/07/2023 a 14/07/2023", "12/08/2024 a 16/08/2024", "22/12/2024 a 30/12/2024"};
    float valor_viagem[] = {1099.99, 899.99, 2399.99};
    int vagas_viagem[] = {50, 50, 50};
    string cartao_a_na[] = {"nao ativo"};
    float carteira_rs[] = {0};
    
    vector<string> viagem_selecionada_vagas;
    
    float valor_total;
    
    int qnt_carrinho = 0.0;
    
    int qnt_viagens = sizeof(viagens_all)/sizeof(viagens_all[0]);
    
    float valor_total_destino[] = {};
    
    for(int i=0 ; i < 3 ; i++){
        viagem.destino.push_back(viagens_all[i]);
        viagem.descricao.push_back(descricao_viagem[i]);
        viagem.data.push_back(data_viagem[i]);
        viagem.valor.push_back(valor_viagem[i]);
        viagem.vagas.push_back(vagas_viagem[i]);
    }
    
    pagamento.metodo.push_back(cartao_a_na[0]);
    balance.carteira.push_back(carteira_rs[0]);
    
    int pessoa = sizeof(user.nomes_usuarios)/sizeof(user.email[0])+1;
    
    string poltronas[51][51];
    string poltronas_select[51][51];
    
    for(int i=0 ; i<51 ; i++){
        for(int k=1 ; k<51 ; k++){
            poltronas[i][k] = to_string(k);
            poltronas_select[i][k] = to_string(k);
        }
    }
    
    cout << "================================================================" << endl;
    cout << "   BEM VINDO AO BigO Turismo, POR FAVOR ENTRE OU REGISTRE-SE!" << endl;
    cout << "================================================================" << endl;
    cout << endl;
    
    
    cout << "Insira 1 para se registrar ou 2 para login: ";
    cin >> opcao;
    
    if(opcao == 1){
        cout << "\nPor favor, preencha os campos abaixo corretamente.\n";

        while(true){
            cout << "\nNome completo: ";
            cin.ignore();
            getline(cin,user.nome);
            
            cout << "\nEmail: ";
            cin >> user.email;
        
            cout << "\nSenha: ";
            cin.ignore();
            getline(cin,user.senha);
            
            cout << "\nTelefone: ";
            cin >> user.telefone;
            
            cout << "\nCPF (Sem hifen ou espacos): ";
            cin >> user.cpf;
  
            
            if(user.cpf.length() != 11){
                cout << "CPF Invalido, preencha os campos corretamente!" << endl;
            }
            
            else{
                user.nomes_usuarios.push_back(user.nome);
                user.email_usuarios.push_back(user.email);
                user.senhas_usuarios.push_back(user.senha);
                user.telefone_usuarios.push_back(user.telefone);
                user.cpf_usuarios.push_back(user.cpf);
                break;
            }
        }
        
        cout << "\n=== Cadastro realizado com sucesso! ===" << endl;
    }
    
    else{
        int y = sizeof(user.email_usuarios)/sizeof(user.email_usuarios[0]);
            
        if(y==0){
            cout << "\nNao foi possivel encontrar o usuario. Por favor, cadastre-se e tente novamente mais tarde.\n" << endl;
            
            exit(0);
        }
        
        cout << "\nPor favor, insira os dados de cadastro abaixo: " << endl;
        cout << endl;
        cout << "Email: ";
        cin >> user.email;
        
        cout << "Senha: ";
        cin.ignore();
        getline(cin, user.senha);
        
        
        for(int i=0; i<y; i++){
            if(user.email == user.email_usuarios[i]){
                if(user.senha == user.senhas_usuarios[i]){
                    login_sucess = true;
                    break;
                }
                else{
                    for(int k=0; k<3 ; i++){
                        cout << "Insira a senha novamente: ";
                        getline(cin, user.senha);
                        
                        if(user.senha == user.senhas_usuarios[i]){
                            login_sucess = true;
                            break;
                        }
                        else{
                            cout << "Senha incorreta" << endl;
                        }
                    }
                    
                }
            }
            else{
                cout << "Email invalido" << endl;
                cout << "Insira o email novamente: ";
                cin >> user.email;
                for(int i=0; i<y ; i++){
                    if(user.email == user.email_usuarios[i]){
                        for(int l=0 ; i < 3 ; i++){
                            cout << "Digite a senha: ";
                            cin.ignore();
                            getline(cin, user.senha);
                            
                            if(user.senha == user.senhas_usuarios[i]){
                                login_sucess = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    while(true){
        int y = sizeof(user.email_usuarios)/sizeof(user.email_usuarios[0]);
            
        if(y==0){
            y = y+1;
        }
        
        cout << "\nPor favor, insira os dados de cadastro abaixo: " << endl;
        cout << endl;
        cout << "Email: ";
        cin >> user.email;
        
        cout << "Senha: ";
        cin.ignore();
        getline(cin, user.senha);
        
        if(user.email == admin.adm_email){
            if(user.senha == admin.adm_senha){
                adm_painel = true;
                login_sucess = true;
                break;
            }
        }
        
        else{
            for(int i=0; i<y; i++){
                if(user.email == user.email_usuarios[i]){
                    if(user.senha == user.senhas_usuarios[i]){
                        login_sucess = true;
                        break;
                    }
                    else{
                        for(int k=0; k<3 ; i++){
                            cout << "Insira a senha novamente: ";
                            getline(cin, user.senha);
                            
                            if(user.senha == user.senhas_usuarios[i]){
                                login_sucess = true;
                                break;
                            }
                            else{
                                cout << "Senha incorreta" << endl;
                            }
                        }
                        
                    }
                }
                else{
                    cout << "Email invalido" << endl;
                    cout << "Insira o email novamente: ";
                    cin >> user.email;
                    for(int i=0; i<y ; i++){
                        if(user.email == user.email_usuarios[i]){
                            for(int l=0 ; i < 3 ; i++){
                                cout << "Digite a senha: ";
                                cin.ignore();
                                getline(cin, user.senha);
                                
                                if(user.senha == user.senhas_usuarios[i]){
                                    login_sucess = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if(login_sucess == false){
            
            cout << "\nNao foi possivel encontrar o usuario. Por favor tente novamente mais tarde.\n" << endl;
            
            exit(0);
        }
            
        else{
            break;
        }
    }
    
    
    int usuario_ativo = 0;
    
    if(adm_painel == true){
        cout << "\n\nadm painel ON\n" << endl;
        usuario_ativo = 0;
    }
    
    else{
        
        int y = sizeof(user.email_usuarios)/sizeof(user.email_usuarios[0]);
            
        if(y==0){
            y = y+1;
        }
        
        for(int i=0 ; i < y ; i++){
            
            if(user.email == user.email_usuarios[i]){
                usuario_ativo = i;
                
                break;
            }
        }
        
        cout << "\n======= BEM VINDO "<< user.nomes_usuarios[usuario_ativo] << " =========\n";
    }


    while(true){
        
        cout << "\n ==    Insira uma opcao     ==" << endl;
        cout << "===============================" << endl;
        cout << "|        Catalogo = 1         |" << endl;
        cout << "|   Formas de Pagamento = 2   |" << endl;
        cout << "|        Carrinho = 3         |" << endl;
        cout << "|          Sair = 4           |" << endl;
        cout << "===============================" << endl;
        
        opcao = 0;
        cout << "\nInsira a opcao: ";
        cin >> opcao;
    
        
        if(opcao == 1){
            cout << endl;
            
            cout << "\nTodas as nossas opcoes de viagens sao como origem em Ourinhos-Sp\n";
            cout << "\n== Viagens Disponíveis ==" << endl;
            
            
            for(int i=0 ; i < qnt_viagens ; i++){
                cout << "Destino: " << viagem.destino[i] << " [" << i << "]" << endl;
            }
            
            do{
                opcao_viagem = 0;
                
                cout << "\nSelecione uma viagem para exibir detalhes, digite '-1' para voltar ao menu: ";
                cin >> opcao_viagem;
                
                if(opcao_viagem <= qnt_viagens && opcao_viagem >= 0){
                    
                    cout << "\nDestino: " << viagem.destino[opcao_viagem] << endl;
                    cout << "Valor: R$" << viagem.valor[opcao_viagem] << endl;
                    cout << "Sobre: " << viagem.descricao[opcao_viagem] << endl;
                    cout << "Data: " << viagem.data[opcao_viagem] << endl;
                    cout << "Vagas disponiveis: " << viagem.vagas[opcao_viagem] << endl;
                    cout << "\nDeseja adicionar a viagem ao carrinho? (Sim, 1 ou Nao, 2): ";
                    
                    int opcao_s_n;
                    cin >> opcao_s_n;
                    
                    if(opcao_s_n == 1){
                        
                        int vagas_qnt = 0;
                        
                        cout << "\nQuantas vagas voce deseja adicionar ao carrinho?: ";
                        cin >> vagas_qnt;
                        
                        int confirm = 0;
                        
                        cout << "\nVoce deseja realmente adicionar " << vagas_qnt << " vagas para o destino " << viagem.destino[opcao_viagem] << "? (Sim, 1 ou Nao, 2): ";
                        cin >> confirm;
                        
                        cout << "\n";
                        
                        if(confirm == 1){
                            
                            for(int i=1 ; i <= 50 ; i++){
                                if(i<10){
                                    if(poltronas[opcao_viagem][i] == "X"){
                                        cout << "[" << poltronas[opcao_viagem][i] << "] ";
                                    }
                                    
                                    else{
                                        cout << " [" << poltronas[opcao_viagem][i] << "] ";
                                    }
                                }
                                else{
                                    cout << "[" << poltronas[opcao_viagem][i] << "] ";
                                }
                                
                                if(i==13){
                                    cout << endl;
                                }
                                if(i==26){
                                    cout << endl;
                                    cout << "-----------------------------------------------------------------------\n                          CORREDOR\n-----------------------------------------------------------------------\n";
                                }
                                if(i==38){
                                    cout << "  |   |" << endl;
                                }
                                if(i==50){
                                    cout << "  |   |" << endl;
                                }
                            }
                            
                            cout << "\n===Selecione as vagas desejadas===\n";
                            
                            for(int j=0 ; j<vagas_qnt ; j++){
                                while(true){
                                    int aux = 0;
                                    
                                    cout << "\nDigite o numero da poltrona " << j+1 << ": ";
                                    cin >> aux;
                                    
                                    if(poltronas[opcao_viagem][aux]=="X"){
                                        cout << "\nA poltrona ja esta ocupada\n";
                                    }
                                    else{
                                        poltronas_select[opcao_viagem][aux] = "X";
                                        break;
                                    }
                                }
                            }
                            
                            viagem_selecionada_vagas.push_back(viagem.destino[opcao_viagem]);
                            
                            carrinho.destino.push_back(viagem.destino[opcao_viagem]);
                            carrinho.valor_carrinho.push_back(viagem.valor[opcao_viagem]);
                            
                            valor_total_destino[qnt_carrinho] = viagem.valor[opcao_viagem]*vagas_qnt;
                            valor_viagem[qnt_carrinho] = vagas_qnt;
                            qnt_carrinho += 1;
                        }
                        
                        else{
                            cout << "\nOperacao cancelada! Voltando...\n" << endl;
                        }
                        
                        cout << "\nDestino adicionado ao carrinho! Va para a opcao Carrinho no menu, para prosseguir com a compra!" << endl;
                        
                        break;
                    }
                    
                    else{
                        cout << "\nOperecao cancelada!" << endl;
                    }
                }
                
                else{
                    cout << "\nErro, tente novamente" << endl;
                }
                
            } while(opcao_viagem != -1);
        }
        
        else if(opcao == 2){
            cout << "\nCarteira: " << balance.carteira[usuario_ativo] << endl;
                
            if(pagamento.metodo[usuario_ativo] == "ativo"){
                cout << "\n=== Cartao ativo ===\n" << endl; 
                
                cout << "Nome: " << pagamento.nome_cartao[usuario_ativo] << endl;
                cout << "Numero do cartao: " << pagamento.n_cartao[usuario_ativo] << endl;
                cout << "CVV: " << pagamento.cvv[usuario_ativo] << endl;
                cout << "Data: " << pagamento.data[usuario_ativo] << endl; 
            }
            
            else{
                cout << "\nNenhum cartao ativo! Cadastre seu cartao com a opcao 1." << endl;
            }
            
            int pagamento_opcao = 0;
            
            cout << "\nAdicionar cartao = 1\nAdicionar Gift Card = 2\nRemover cartao ativo = 3\nVoltar = 4\n\nInsira a opcao desejada: ";
            cin >> pagamento_opcao;
            
            if(pagamento_opcao == 1){
                if(pagamento.metodo[usuario_ativo] == "ativo"){
                    cout << "\nVoce ja possui um cartao ativo, remova-o para adicionar outro." << endl;
                    cout << "Voltando...\n" << endl;
                }
                else{
                    string nome_cartao, n_cartao, cvv, cartao_data, cartao_numero;
                    
                    cout << "\nPreencha os campos abaixo para adicionar seu cartao\n" << endl;
                    
                    cout << "Nome completo no cartao: ";
                    cin.ignore();
                    getline(cin, nome_cartao);
                    pagamento.nome_cartao.push_back(nome_cartao);
                    
                    cout << "Numero do cartao (Sem espacos): ";
                    cin >> cartao_numero;
                    pagamento.n_cartao.push_back(cartao_numero);
                    
                    cout << "CVV: ";
                    cin >> cvv;
                    pagamento.cvv.push_back(cvv);
                    
                    cout << "Data de vencimento (dd/mm/aaaa): ";
                    cin >> cartao_data;
                    pagamento.data.push_back(cartao_data);
                    
                    cout << "\nCartao adicionado com sucesso!" << endl;
                    
                    pagamento.metodo[usuario_ativo] = "ativo";
                }
            }
            else if(pagamento_opcao == 2){
                
                cout << "Insira o codigo abaixo: " << endl;
                
                string codigo_gfc;
                cin >> codigo_gfc;
                
                if(codigo_gfc.length() != 12){
                    cout << "\nCodigo invalido! Tente novamente ou compre um codigo valido em nossos sites ou lojas parceiras." << endl;
                }
                else{
                    balance.carteira[usuario_ativo] += 250.00;
                    
                    cout << "\nCodigo ativado, confira sua carteira!\nVoltando..." << endl;
                }
            }
            else if(pagamento_opcao == 3){
                cout << "\nDeseja realmente remover cartao atual? (Sim, 1 ou Nao, 2): ";
                int remover = 0;
                cin >> remover;
                
                
                if(remover==2){
                    cout << "\nOperacao cancelada!\nVoltando..." << endl;
                }
                else{
                    if(pagamento.metodo[usuario_ativo] == "ativo"){   
                        pagamento.metodo[usuario_ativo] = "nao ativo";
                        pagamento.n_cartao[usuario_ativo] = " ";
                        pagamento.nome_cartao[usuario_ativo] = " ";
                        pagamento.data[usuario_ativo] = " ";
                        pagamento.cvv[usuario_ativo] = " ";
                        
                        cout << "\nCartao removido com sucesso!\nVoltando..." << endl;
                    }
                    else{
                        cout << "\nVoce nao possui cartao cadastrado. Voltando...\n" << endl;
                    }
                }
            }
            else{
                cout << "\nVoltando..." << endl;
            }
        }
        
        else if(opcao == 3){
        
            int payment = 0;
            
            if(qnt_carrinho > 0){
                for(int i=0 ; i < qnt_carrinho ; i++){
                    cout << "Item " << i+1 << ": " << carrinho.destino[i] << " || Vagas: " << valor_viagem[i] << " || Valor: " << valor_total_destino[i] << endl;
                    valor_total += valor_total_destino[i];
                }
                cout << "\nValor total = R$" << valor_total << endl;
                
                cout << "\nDeseja finalizar compra? (Sim, 1 ou Nao, 2): ";
                cin >> payment;
                
                if(payment==1){
                    if(pagamento.metodo[usuario_ativo]=="ativo"){
                        
                        cout << "\nComo voce deseja finalizar a compra? (Carteira, 1 ou Cartao, 2): ";
                        
                        int payment_choice = 0;
                        cin >> payment_choice;
                        
                        if(payment_choice == 2){
                            int opcao_juros = 0;
                            
                            cout << "\n===Selecione a opcao desejada===\n";
                            cout << "\n1 - Pagamento em 1x (Sem juros)";
                            cout << "\n2 - Pagamento em 2x (Sem juros)";
                            cout << "\n3 - Pagamento em 3x (Sem juros)";
                            cout << "\n4 - Pagamento em 4x (50$ de juros)";
                            cout << "\n5 - Pagamento em 5x (75$ de juros)\n";
                            
                            cout << "\nInsira a opcao: ";
                            cin >> opcao_juros;
                            
                            cout << "\nFinalizando compra...\nPagamento efetuado! Confira seu email para informacoes da passagem! Fique atento para nao perder a data." << endl;
                            
                            for(int i=0 ; i < qnt_viagens ; i++){
                                for(int k=0 ; k < qnt_carrinho ; k++){
                                    if(viagem.destino[i] == viagem_selecionada_vagas[k]){
                                        viagem.vagas[i] -= valor_viagem[k];
                                        
                                        carrinho.destino[k] = "";
                                        valor_viagem[k] -= valor_viagem[i];
                                        valor_total_destino[k] -= valor_total_destino[i];
                                    }
                                }
                            }
                            
                            for(int l=0 ; l<=50 ; l++){
                                for(int m=1 ; m<=50 ; m++){    
                                    if(poltronas_select[l][m] == "X"){
                                        poltronas[l][m] = "X";
                                        poltronas_select[l][m] = to_string(m);
                                    }
                                }
                            }
                        
                            qnt_carrinho = 0;
                            valor_total = 0;
                            
                        }
                        else{
                            if(balance.carteira[usuario_ativo] >= valor_total && balance.carteira[usuario_ativo]>0){
                                balance.carteira[usuario_ativo] = balance.carteira[usuario_ativo] - valor_total;
                                valor_total = 0;
                            }
                            else{
                                cout << "\nVoce nao possui saldo na carteira, adicione um gift card no menu de pagamento e tente novamente." << endl;
                            }
                        }
                    }
                    else{
                        cout << "\nVoce nao possui cartao registrado" << endl;
                        
                        if(balance.carteira[usuario_ativo] >= valor_total && balance.carteira[usuario_ativo] > 0){
                            cout << "\nVoce deseja efetuar o pagamento com o saldo da carteira disponivel? (Sim, 1 ou Nao, 2): ";
                            
                            int accept_choice = 0;
                            cin >> accept_choice ;
                            
                            if(accept_choice == 1){
                                cout << "\nFinalizando compra...\nPagamento efetuado! Confira seu email para informacoes da passagem! Fique atento para nao perder a data." << endl;
                                
                                balance.carteira[usuario_ativo] = balance.carteira[usuario_ativo] - valor_total;
                                
                                for(int i=0 ; i < qnt_viagens ; i++){
                                    for(int k=0 ; k < qnt_carrinho ; k++){
                                        if(viagem.destino[i] == viagem_selecionada_vagas[k]){
                                            viagem.vagas[i] -= valor_viagem[k];
                                            
                                            carrinho.destino[k] = "";
                                            valor_viagem[k] = valor_viagem[i];
                                            valor_total_destino[k] -= valor_total_destino[i];
                                        }
                                    }
                                }
                                
                                for(int l=0 ; l<=50 ; l++){
                                    for(int m=1 ; m<=50 ; m++){    
                                        if(poltronas_select[l][m] == "X"){
                                            poltronas[l][m] = "X";
                                            poltronas_select[l][m] = to_string(m);
                                        }
                                    }
                                }
                                
                                qnt_carrinho = 0;
                                valor_total = 0;
                                
                            }
                            else{
                                cout << "\nOperacao cancelada, voltando...\n" << endl;
                            }
                        }
                        else{
                            cout << "\nVoce nao possui saldo na carteira suficiente, adicione creditos no menu Pagamento.\nVoltando...\n" << endl;
                        }
                    }
                }
            }
            
            else{
                cout << "\nAdicione itens ao carrinho no menu 'Catalogo'.\nVoltando...\n";
            }
        }
        
        else{
            cout << "\n=== Obrigado por usar o nosso software, esperamos voce de novo em breve! ===";
            
            break;
            return 0;
        }
    } 
}
