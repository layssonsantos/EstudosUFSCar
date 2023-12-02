# Laysson Santos da Silva 800349 & Daniel de Souza Sobrinho Macedo 813524
# Curso: Ciência da Computação (BCC)

# =======================================================================

#                                    DADOS DO PROBLEMA:
# Vagas oferecidas: N(2 ≤ N ≤ 100)
# Pessoas chamadas pra segunda fase: K(1 ≤ K ≤ 100)
# Número de candidatos que concorreram á vaga: C(10 ≤ C ≤ 106)
# C números reais R(0.0 ≤ R ≤ 100.0) com a nota obtidada de cada candidato
# K ≤ C em todos os casos de testes

# Exemplo de entrada:
# 3(N)
# 3(K) 10(C) R = {75.2 45.3 23.4 35.9 77.7 52.7 66.6 98.3 88.9 12.3}
# 5 8 11.1 22.2 33.3 44.4 55.5 66.6 77.7 88.8
# 1 5 25.8 97.3 99.9 95.4 89.7

# Objetivo:
# imprimir um único valor real para cada vaga, 
# indicando qual é K-ésima maior nota obtida

# =======================================================================

import heapq

# Função para encontrar a K-ésima maior nota usando heap (fila de prioridade)
def ordenar(arr, k):
    heap = arr[:k]
    heapq.heapify(heap)   
    for i in range(k, len(arr)):
        if arr[i] > heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, arr[i]) 
    return heap[0]

# Lê o número de vagas
num_vagas = int(input())

# Loop para cada vaga
for i in range(num_vagas):
    arr = input().split(' ')
    k, c = map(int, arr[:2])  # Lê K e C
    notas = list(map(float, arr[2:]))  # Lê as notas
    maiorNotaK = ordenar(notas, k)  # Encontra a K-ésima maior nota
    print("{:.2f}".format(maiorNotaK))  # Imprime o resultado com duas casas de precisão
    notas = []