# Para executar, basta deixar todos os outros arquivos
# no mesmo diretório do index.py, pois os arquivos estão
# todos ligados por meio de cabeçalho.
# Como entrada, pode ser as instrucoes do mips, exemplo 
# add $10, $20, $30, addi $10, $20, 40, j (algum endereco)
# A Saida será a instrução decodificada para linguagem de maquina
# (Sequencia de 0 e 1)

from functions import *
from interpretador import *
from memoria import *

# Inicializando o programa
print("Vamos iniciar! Digite quantas instrucoes queres executar:")
quantidadeInstrucoes = int(input())
vetorInstrucoes = []

# Alocando a memoria ( Memoria do processador + Instrucoes )
memoria = MemoriaMIPS(quantidadeInstrucoes)

# Entrada de dados e criação do arquivo binário
for i in range (quantidadeInstrucoes):
    vetorInstrucoes.append(digitarDados())

for i in vetorInstrucoes:
    gerarArquivoBinario(i)
    
# Escrever as instrucoes na memoria de instrucoes
memoria.escritaInstrucoesMemoria()

print (memoria.memoriaInstrucao)



