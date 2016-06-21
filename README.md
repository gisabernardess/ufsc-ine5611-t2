Trabalho 2 – E/S e Arquivos

INE5611 - Sistemas Operacionais

O Trabalho 2 (T2) consiste em desenvolver um programa para gerenciar uma base de dados de funcionários de uma empresa em um arquivo binário. Cada funcionário deverá ser representado obrigatoriamente pela seguinte estrutura:

		struct  funcionario {unsigned  int id; char  nome [256]; char  sexo; float  salario; }

O programa deverá receber pela linha de comando o nome de um arquivo binário contendo a base de dados dos funcionários (o arquivo de dados deverá ser criado caso não exista). O programa deverá permanecer em um loop infinito aguardando operações por parte do usuário. As operações permitidas são: 

1. Inserir um funcionário: o programa deverá solicitar que o usuário digite todos os dados do funcionário a ser inserido (id, nome, sexo e salario ). O programa só deverá inserir o funcionário na base de dados se o id informado for maior do que zero e não exista nenhum funcionário já cadastrado com o mesmo id.

2. Remover um funcionário: o usuário deverá informar o id do funcionário a ser removido. A remoção consistirá em alterar o id do funcionário para o valor zero. Portanto, usuários com id=0 serão considerados como removidos da base de dados.

3. Calcular a média de salários dos funcionários por sexo: o programa deverá calcular ambas as médias e mostrá-las na tela. O programa não poderá incluir os salários dos funcionários removidos do sistema.

4. Exportar os dados dos funcionários para um arquivo em formato texto: o programa deverá solicitar o nome do arquivo de texto de saída onde serão exportados os dados. O programa não deverá exportar os funcionários removidos do sistema.

5. Compactar a base de dados: o programa deverá remover fisicamente da base de dados todos os funcionários que possuam id=0,  reduzindo assim o tamanho da base de dados.

6. Sair do programa: ao sair do programa o arquivo binário contendo a base de dados deve permanecer no disco para utilização posterior.
