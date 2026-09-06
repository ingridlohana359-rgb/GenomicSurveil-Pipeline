import sys
import pandas as pd

def analisar_dados(input_path, output_path):
    print(f"[Python] Lendo dados processados de: {input_path}")
    df = pd.read_csv(input_path)
    
    # Simula uma análise estatística de expressão/tamanho
    media_tamanho = df['Tamanho'].mean()
    print(f"[Python] Tamanho medio das sequencias: {media_tamanho:.2f} pb")
    
    # Salva um relatório resumido
    df_resumo = df.describe()
    df_resumo.to_csv(output_path)
    print(f"[Python] Relatorio estatistico salvo em: {output_path}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Uso: python3 process_data.py <entrada.csv> <saida_resumo.csv>")
        sys.exit(1)
    analisar_dados(sys.argv[1], sys.argv[2])
