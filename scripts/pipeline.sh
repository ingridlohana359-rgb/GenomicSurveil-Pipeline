#!/bin/bash
set -e

echo "=== INICIANDO PIPELINE DE BIOINFORMATICA ==="

# 1. Compilar o código C++
echo "[Bash] Compilando o modulo C++..."
g++ -O3 src/fasta_parser.cpp -o bin/fasta_parser

# 2. Executar o binário C++ gerando os dados estruturados
echo "[Bash] Executando parsing de sequencias em C++..."
./bin/fasta_parser data/amostras.fasta outputs/tabela_intermediaria.csv

# 3. Executar o script Python de análise estatística
echo "[Bash] Executando analise em Python..."
python3 scripts/process_data.py outputs/tabela_intermediaria.csv outputs/relatorio_final.csv

echo "=== PIPELINE CONCLUIDO COM SUCESSO! ==="
