/* O que é?
 * Flex:  "gerador" de analisador léxico.
 * Bison: "gerador" de analisador sintático.
 */

/* Para que serve?
 * Flex:  implementar autômatos.
 * Bison: implementar gramáticas.
 */

/* Download:
 * Flex: https://sourceforge.net/projects/gnuwin32/files/flex/2.5.4a-1/flex-2.5.4a-1.exe/download
 * Bison: http://downloads.sourceforge.net/gnuwin32/bison-2.4.1-setup.exe
 * GCC: baixar o DevC++ (https://www.bloodshed.net/) ou Code::Blocks (https://www.codeblocks.org/).
 */

/* Instalação:
 * Instalar o Flex e o Bison em uma pasta cujo 
 * caminho não possua espaços em branco.
 * Colocar as pastas "bin" do Flex, Bison e 
 * DevC++ (ou Code::Blocks) na variável "Path" do Windows.  
 */

/* Comandos para execução:
 * 1) flex analisador_lexico.l
 * 2) bison -d analisador_sintatico.y
 * 3) gcc lex.yy.c analisador_sintatico.tab.c -o prog
 * 4) ./prog
 */

/* Prólogo - Declarações:
 * Declarações = declarações auxiliares + definições regulares.
 */

 /* Declarações auxiliares:
  * Contém declaração global opcional, como 
  * importações, protótipo de função e 
  * variáveis globais.
  */
%{
  #include "analisador_sintatico.tab.h"
  #include <stdlib.h>
  extern char comando[5];
  int i;
%}

/* Definições regulares:
 * Consiste de símbolos e expressões regulares.
 */
delimitador      [ \t\n\r]
espaco_em_branco {delimitador}+
digito           [0-9]
numero           {espaco_em_branco}*{digito}+{espaco_em_branco}*
letra            [a-zA-Z]
aspa             ["]
add              (({ADD}|{add}){espaco_em_branco})
sub              (({SUB}|{sub}){espaco_em_branco})
print            (({PRINT}|{print}){espaco_em_branco})
string           {aspa}({espaco_em_branco}|{letra}|{numero})*{aspa}

/*Regras:*/
%%
{add}              {for(i=0; i < 3 ; i++) comando[i] = yytext; comando[i]="\0" return ADD;}
{sub}              {for(i=0; i < 3 ; i++) comando[i] = yytext; comando[i]="\0" return SUB;}
{print}            {for(i=0; i < 5 ; i++) comando[i] = yytext; comando[i]="\0" return PRINT;}
{numero}           {yylval = atoi(yytext); return NUM;}
{string}           {return STRING}
{espaco_em_branco} {/* Ignora espaços em branco.*/}
.                  {/* Ignora todo o resto.*/}
%%

/* Epílogo - Funções em Linguagem C:
 * Abaixo, informa-se funções auxiliares em 
 * linguagem C, caso seja necessário.
 */
