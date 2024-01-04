# Cadastro-de-Despesas



👨🏻‍💻APRESENTAÇÃO👨🏻‍💻:

Um trabalho de lógica de programação de nível de ensino superior, um programa na linguagem de programação C, diante da demanda do Centro Federal de Educação Tecnológica de Minas Gerais (CEFET-MG).
É gerado um arquivo binário em formato de uma estrutura já definida pelo programa, no qual um cadastro de despesas será mantido na memória do computador e que pode ter seus dados acessados a qualquer momento pelo uso programa, sem que seja reiniciado ou excluído.
Dito isso, um painel com 5 opções são exibidas para o usuário, com as respectivas funções:

- Inclusão de despesas (sem poder repetir despesas de mesma descrição);

- Alteração de despesas (a descrição não é alterável);

- Relatório (exibe todas as despesas);
  
- Pesquisa (exibe os dados da despesa em que a descrição foi inserida);
  
- Exclusão de despesas (com a confirmação de querer a exclusão).

  
🔧FUNÇÕES🔧:

- Inclusão de despesas: inclui despesas e não permite a inclusão de despesas de descrições iguais.

- Alteração de despesas: abre um novo arquivo e escreve tudo armazenado no antigo, com as alterações requeridas, além de apagar o antigo e renomear o novo.

- Relatório: imprime na tela do usuário todas as despesas e suas informações.

- Pesquisa: imprime na tela do usuário as informações da despesa, no qual a descrição foi informada.

- Exclusão de despesas: abre um novo arquivo e escreve tudo armazenado no antigo, com exceção da despesa indesejada, além de apagar o antigo, renomear o nome e confirmar se deseja mesmo excluir a despesa.

- Corrige erro do usuário: corrige o erro de entrada que o usuário pode ter cometido ao inserir uma opção inválida para as alternativas do menu, pede para inserir uma resposta até ser uma válida.

- Corrige erro de escolha: corrige o erro de entrada que o usuário pode ter cometido ao inserir uma opção inválida para as alternativas de saída ou não do programa, pede para inserir uma resposta até ser uma válida.

- Ações: exibe para o usuário um painel de escolhas com 5 opções de funcionalidades.

- Chama Função: é uma função com utilidade única de chamar as funções das funcionalidades requeridas, intuito de deixar a main mais limpa e curta.

- Main: Declaração de variáveis que são passadas como parâmetros para outras funções
e gerenciamento do código; chama outras funções; inicia o programa ao usuário e imprime as principais mensagens.
